#include <bits/stdc++.h>
using namespace std;

struct entity {
    int id, type, x, y, item; // if this entity is a robot, the item it is carrying (-1 for NONE, 2 for RADAR, 3 for TRAP, 4 for ORE)
};

struct ore_metadata {
    int x, y, count;
};

float dist (int x1, int y1, int x2, int y2)
{
    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
}

pair<int, int> getRandom(int x, int y)
{
    int newX = rand()%30;
    int newY = rand()%15;
    if(newY == y) newY=14;
    if(newX == x) newX=29;

    return make_pair(newX, newY);
}

pair <int, int> isNeighbourOre(int x, int y, set < pair <int, int> > &v)
{
    if(v.find(make_pair(x, y)) != v.end())
        return make_pair(x, y);
    else if(x-1 > 0 && v.find(make_pair(x-1, y)) != v.end())
        return make_pair(x-1, y);
    else if(x+1 < 30 && v.find(make_pair(x+1, y)) != v.end())
        return make_pair(x+1, y);
    else if(y-1 > 0 && v.find(make_pair(x, y-1)) != v.end())
        return make_pair(x, y-1);
    else if(y+1 < 15 && v.find(make_pair(x, y+1)) != v.end())
        return make_pair(x, y+1);
    else
        return make_pair(-1, -1);
}

bool flag[]={ 0, 0, 0, 0, 0 };   //0-> MOVE 1-> DIG
bool replantFlag = false, trapFlag = false;

int main()
{
    int width, height;
    cin >> width >> height; cin.ignore();

    set < pair <int, int> > radar_points;
    radar_points.assign( make_pair(7, 11) );
    radar_points.assign( make_pair(7, 3) );
    radar_points.assign( make_pair(12, 7) );
    radar_points.assign( make_pair(17, 11) );
    radar_points.assign( make_pair(17, 3) );
    radar_points.assign( make_pair(20, 7) );
    radar_points.assign( make_pair(24, 3) );
    radar_points.assign( make_pair(24, 11) );

    map < int, pair<int, int> > assigned;
    set <int> robo_assigned;
    int firstRadarX = radar_points.begin()->first, firstRadarY = radar_points.begin()->second;

    vector < pair <int, int> > formation;
    formation.push_back(make_pair(firstRadarX+2, firstRadarY));
    formation.push_back(make_pair(firstRadarX, firstRadarY+2));
    formation.push_back(make_pair(firstRadarX-2, firstRadarY));
    formation.push_back(make_pair(firstRadarX, firstRadarY-2));
    int loopFormation=0;

    set < pair <int, int> > trap_points;
    map < int, pair<int, int> > assigned_trap;
    set <int> robo_assigned_trap;

    while (1)
    {
        loopFormation = 0;
        bool isRadarRequested=0, isTrapRequested=0;

        int myScore, opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();

        set < pair <int, int> > isTrap, isHole, isRadar;
        vector < entity> robo, oppRobo, radar, trap;
        vector < ore_metadata > active_ores;
        set < pair <int, int> > active_ores_set;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                string ore;
                int hole;
                cin >> ore >> hole; cin.ignore();
                ore_metadata temp;
                if(ore != "?" && ore != "0")
                {
                    temp.x=j;
                    temp.y=i;
                    temp.count=stoi(ore);
                    active_ores.push_back(temp);
                    active_ores_set.insert(make_pair(j, i));
                }
                if(hole)
                    isHole.insert(make_pair(j, i));
            }
        }

        int entityCount, radarCooldown, trapCooldown;
        cin >> entityCount >> radarCooldown >> trapCooldown; cin.ignore();
        for (int i = 0; i < entityCount; i++)
        {
            entity temp;
            cin >> temp.id >> temp.type >> temp.x >> temp.y >> temp.item; cin.ignore();

            switch(temp.type)
            {
                case 0: robo.push_back(temp);
                break;
                case 1: oppRobo.push_back(temp);
                break;
                case 2:
                {
                    radar.push_back(temp);
                    isRadar.insert(make_pair(temp.x, temp.y));
                }
                break;
                case 3:
                {
                    trap.push_back(temp);
                    isTrap.insert(make_pair(temp.x, temp.y));
                }
                break;
            }
        }

        //Radar Replant
        if(radar_points.size() == 0 && radar.size() != 8 && replantFlag == true)
        {
            if(isRadar.find(make_pair(8, 3)) == isRadar.end())
                radar_points.assign( make_pair(8, 3) );
            if(isRadar.find(make_pair(8,11)) == isRadar.end())
                radar_points.assign( make_pair(8, 11) );
            if(isRadar.find(make_pair(13, 7)) == isRadar.end())
                radar_points.assign( make_pair(13, 7) );
            if(isRadar.find(make_pair(18, 3)) == isRadar.end())
                radar_points.assign( make_pair(18, 3) );
            if(isRadar.find(make_pair(18, 11)) == isRadar.end())
                radar_points.assign( make_pair(18, 11) );
            if(isRadar.find(make_pair(21, 7)) == isRadar.end())
                radar_points.assign( make_pair(21, 7) );
            if(isRadar.find(make_pair(25, 3)) == isRadar.end())
                radar_points.assign( make_pair(25, 3) );
            if(isRadar.find(make_pair(25, 11)) == isRadar.end())
                radar_points.assign( make_pair(25, 11) );
        }
        
        for(int i=0; i<5; i++)
        {   
            if(robo[i].x == -1 && robo_assigned.find(robo[i].id) != robo_assigned.end())
            {
                radar_points.assign(assigned[robo[i].id]);
                assigned.erase(robo[i].id);
                robo_assigned.erase(robo_assigned.find(robo[i].id));
            }
        }

        //Precompute radar allocation
        if(radar_points.size() != 0 && radarCooldown == 0 )//&& robo_assigned.size() < 2)// && active_ores.size() < 10)  //TODO: REMOVE COOLDOWN CONDITION & ADD THRESHOLD
        {
            int radarMan = -1;
            float min_dist=INT_MAX;
            cerr<<robo_assigned.size()<<endl;
            for(int i = 0; i < 5; i++)
            {
                if(robo[i].item != -1 || robo_assigned.find(robo[i].id) != robo_assigned.end() || robo[i].x == -1)
                    continue;
                float distance = robo[i].x; //dist(0, robo[i].y, radar_points.begin()->first, radar_points.begin()->second) + robo[i].x;
                if(distance < min_dist)
                {
                    min_dist = distance;
                    radarMan = robo[i].id;
                }
            }
            if( radarMan != -1)
            {
                assigned[radarMan] = *radar_points.begin();
                robo_assigned.insert(radarMan);
                radar_points.erase(radar_points.begin());
                
                cerr<<robo_assigned.size()<<" "<<radarMan<<" "<<assigned[radarMan].first<<" "<<assigned[radarMan].second<<endl;
            }
        }

        //Precompute trap allocation
        if(trap_points.size() != 0 && trapCooldown == 0 && trapFlag == true)
        {
            int trapMan = -1;
            float min_dist=INT_MAX;
            for(int i = 0; i < 5; i++)
            {
                float distance = dist(0, robo[i].y, trap_points.begin()->first, trap_points.begin()->second) + robo[i].x;
                if(distance < min_dist)
                {
                    min_dist = distance;
                    trapMan = robo[i].id;
                }
            }
            assigned_trap[trapMan] = *trap_points.begin();
            robo_assigned_trap.insert(trapMan);
            trap_points.erase(trap_points.begin());
        }

        for(int i = 0; i < 5; i++)
        {
            if(robo[i].x == -1)
            {
                cerr<<robo[i].id<<" is dead"<<endl;
                cout<<"WAIT"<<endl;
                continue;
            }
            
            set < pair<int, int> > :: iterator it_set;
            for(it_set = isTrap.begin(); it_set != isTrap.end(); it_set++)
                remove_if(active_ores.begin(), active_ores.end(), [&it_set] (ore_metadata &elem) { return elem.x == it_set->first && elem.y == it_set->second; });
            
            cerr<<"X: "<<robo[i].x<<" "<<"Y: "<<robo[i].y<<endl;
            
            if(robo_assigned.find(robo[i].id) != robo_assigned.end())
            {
                if(robo[i].item == -1 || robo[i].item == 4) //TODO: PICK ORE ON THE WAY TO HOME => DONE
                {
                    if(robo[i].x != 0)
                    {
                        pair <int, int> dest = isNeighbourOre(robo[i].x, robo[i].y, active_ores_set);
                        if(robo[i].item == -1 && dest.first != -1 && dest.second != -1)
                        {
                            cout<<"DIG "<<dest.first<<" "<<dest.second<<endl;
                            //active_ores.erase(find(active_ores.begin(), active_ores.end(), make_pair(dest.first, dest.second)));
                            remove_if(active_ores.begin(), active_ores.end(), [&dest] (ore_metadata &elem) { return elem.x == dest.first && elem.y == dest.second; });
                        }
                        else
                            cout<<"MOVE 0 "<<robo[i].y<<endl;
                    }
                    else if(radarCooldown == 0 && isRadarRequested == false)
                    {
                        cout<<"REQUEST RADAR"<<endl;
                        isRadarRequested = true;
                    }
                    else
                        cout<<"WAIT"<<endl;
                }
                else if(robo[i].item == 2)
                {
                    int destX = assigned[robo[i].id].first, destY = assigned[robo[i].id].second;
                    if(abs(robo[i].x - destX) + abs(robo[i].y - destY) <= 1)
                    {
                        cout<<"DIG "<<destX<<" "<<destY<<endl;
                        assigned.erase(robo[i].id);
                        robo_assigned.erase(robo_assigned.find(robo[i].id));
                    }
                    else
                    {
                        cout<<"MOVE "<<destX<<" "<<destY<<endl;
                    }
                }
            }
            else if(robo_assigned_trap.find(robo[i].id) != robo_assigned_trap.end() && trapFlag == true)
            {
                if(robo[i].item == -1)
                {
                    if(robo[i].x != 0)
                        cout<<"MOVE 0 "<<robo[i].y<<endl;
                    else if(trapCooldown == 0 && isTrapRequested == false)
                    {
                        cout<<"REQUEST TRAP"<<endl;
                        isTrapRequested = true;
                    }
                    else
                        cout<<"WAIT"<<endl;
                }
                else if(robo[i].item == 3)
                {
                    int destX = assigned_trap[robo[i].id].first, destY = assigned_trap[robo[i].id].second;
                    if(abs(robo[i].x - destX) + abs(robo[i].y - destY) <= 1)
                    {
                        cout<<"DIG "<<destX<<" "<<destY<<endl;
                        assigned_trap.erase(robo[i].id);
                        robo_assigned_trap.erase(robo_assigned_trap.find(robo[i].id));
                    }
                    else
                    {
                        cout<<"MOVE "<<destX<<" "<<destY<<endl;
                    }
                }
            }
            else
            {
                if(robo[i].x == 0 && !trapCooldown && robo[i].item == -1 && myScore > 10) // TODO: THRESHOLD FOR MY SCORE
                {
                    cout<<"REQUEST TRAP"<<endl;
                    trapCooldown = 5;
                    continue;
                }

                if(robo[i].item == -1 || robo[i].item == 3)
                {
                    if(opponentScore == 0 && myScore == 0 && active_ores.size() == 0 && abs(robo[i].x - firstRadarX) + abs(robo[i].y - firstRadarY) > 1)
                    {
                        //cout<<"MOVE "<<firstRadarX<<" "<<firstRadarY<<endl; //TODO: IMPROVE FORMATION => DONE
                        cout<<"MOVE "<<formation[loopFormation].first<<" "<<formation[loopFormation].second<<endl;
                        loopFormation++;
                    }
                    else if(active_ores.size() != 0)
                    {
                        ore_metadata current_ore, min_ore;
                        min_ore.x=-1, min_ore.y=-1, min_ore.count=-1;

                        vector < ore_metadata > :: iterator it, min_it;
                        min_it=active_ores.begin();

                        float min_distance = INT_MAX;

                        for(it = active_ores.begin(); it != active_ores.end(); it++)
                        {
                            current_ore=*it;
                            float distance = dist(robo[i].x, robo[i].y, current_ore.x, current_ore.y);
                            if(distance < min_distance)
                            {
                                min_distance = distance;
                                min_ore = current_ore;
                                min_it = it;
                            }
                        }

                        if(min_ore.x != -1)
                        {
                            if( abs(robo[i].x - min_ore.x) + abs(robo[i].y - min_ore.y) <= 1 )
                            {
                                cout<<"DIG "<<min_ore.x<<" "<<min_ore.y<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(min_ore.x, min_ore.y));
                            }
                            else
                                cout<<"MOVE "<<min_ore.x<<" "<<min_ore.y<<endl;

                            if(min_it->count == 1)
                                active_ores.erase(min_it);
                            else
                                min_it->count--;
                        }
                        else
                        {
                            cerr<<"DEAD CODE BLOCK REACHED"<<endl;
                            cout << "WAIT" << endl;
                        }
                    }
                    else
                    {
                        if(!flag[i])
                        {
                            pair <int, int> newPos = getRandom(robo[i].x, robo[i].y);
                            cout<<"MOVE "<<newPos.first<<" "<<newPos.second<<endl;
                            flag[i] = true;
                        }
                        else if(flag[i])
                        {
                            if(isHole.find(make_pair(robo[i].x, robo[i].y)) == isHole.end() && isTrap.find(make_pair(robo[i].x, robo[i].y)) == isTrap.end())
                            {
                                cout<<"DIG "<<robo[i].x<<" "<<robo[i].y<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(robo[i].x, robo[i].y));
                                flag[i] = false;
                            }
                            else if(robo[i].x-1 > 2 && isHole.find(make_pair(robo[i].x-1, robo[i].y)) == isHole.end() && isTrap.find(make_pair(robo[i].x-1, robo[i].y)) == isTrap.end())
                            {
                                cout<<"DIG "<<robo[i].x-1<<" "<<robo[i].y<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(robo[i].x-1, robo[i].y));
                                flag[i] = false;
                            }
                            else if(robo[i].y-1 >= 0 && isHole.find(make_pair(robo[i].x, robo[i].y-1)) == isHole.end() && isTrap.find(make_pair(robo[i].x, robo[i].y-1)) == isTrap.end())
                            {
                                cout<<"DIG "<<robo[i].x<<" "<<robo[i].y-1<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(robo[i].x, robo[i].y-1));
                                flag[i] = false;
                            }
                            else if(robo[i].x+1 < 30 && isHole.find(make_pair(robo[i].x+1, robo[i].y)) == isHole.end() && isTrap.find(make_pair(robo[i].x+1, robo[i].y)) == isTrap.end())
                            {
                                cout<<"DIG "<<robo[i].x+1<<" "<<robo[i].y<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(robo[i].x+1, robo[i].y));
                                flag[i] = false;
                            }
                            else if(robo[i].y+1 < 15 && isHole.find(make_pair(robo[i].x, robo[i].y+1)) == isHole.end() && isTrap.find(make_pair(robo[i].x, robo[i].y+1)) == isTrap.end())
                            {
                                cout<<"DIG "<<robo[i].x<<" "<<robo[i].y+1<<endl;
                                if(robo[i].item == 3)
                                    isTrap.insert(make_pair(robo[i].x, robo[i].y+1));
                                flag[i] = false;
                            }
                            else
                            {
                                pair <int, int> newPos = getRandom(robo[i].x, robo[i].y);
                                cout<<"MOVE "<<newPos.first<<" "<<newPos.second<<endl;
                            }
                        }
                        else
                        {
                            cerr<<"UNREACHABLE CODE BLOCK"<<endl;
                            cout<<"WAIT"<<endl;
                        }
                    }
                }
                else if(robo[i].item == 2)
                {
                    cerr<<"DEAD CODE BLOCK REACHED FOR RADAR"<<endl;
                    cout<<"WAIT"<<endl;
                }
                //else if(robo[i].item == 3)
                //{
                //    cerr<<"TRAPS NOT INSTALLED"<<endl;
                //    cout<<"WAIT"<<endl;
                //}
                else
                {
                    cout<<"MOVE 0 "<<robo[i].y<<endl;
                }
            }
        }
    }
}