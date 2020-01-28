// https://leetcode.com/problems/number-of-corner-rectangles/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n <= 1 || grid[0].size() <= 1)
            return 0;
        
        int m = grid[0].size();
        unordered_map<string, int> mapping;
        auto key = [](int x, int y){return to_string(x) + "|" + to_string(y);};
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    for(int k = j+1; k < m; k++){
                        if(grid[i][k]){
                            count += mapping[key(j,k)];
                            mapping[key(j,k)] += 1;
                        }
                    }
                }
            }
        }
        return count;
    }
};

// -----------------
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n <= 1 || grid[0].size() <= 1)
            return 0;
        
        int m = grid[0].size();
        map<pair<int, int>, int> mapping;
                
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    mapping[{i,j}] = 1;
                }
            }
        }
        for(auto p: mapping){
            int r1 = p.first.first, c1 = p.first.second;
            cout << "{r1, c1}: " << "{" << r1 << "," << c1 << "}" << endl;
        }
        
        for(auto itr2 = mapping.begin(); itr2 != mapping.end(); itr2++){
            for(auto itr1 = mapping.begin(); itr1 != itr2; itr1++){
                pair<int, int> pos1 = itr1->first;
                pair<int, int> pos2 = itr2->first;
                int r1 = pos1.first, c1 = pos1.second;
                int r2 = pos2.first, c2 = pos2.second;
                if(r1 >= r2 || c1 >= c2)
                    continue;
                count += grid[r1][c2] && grid[r2][c1];
            }
        }
        return count;
    }
};

// can use bitset for each line and count set bit nC2