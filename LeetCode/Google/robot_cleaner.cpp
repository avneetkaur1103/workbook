// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/1340/
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    const vector<vector<int>> pos = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void come_back(Robot& r){
        r.turnRight();
        r.turnRight();
        r.move();
        r.turnRight();
        r.turnRight();
    }
    void dfs(int r, int c, int angle, set<pair<int, int>>& visited, Robot& robot){
        visited.insert({r,c});
        robot.clean();
        cout << "clean: " << r << "," << c << endl;
        for(int i = 0; i < 4; i++){
            int new_angle = (angle+i) % 4;
            int next_r = r + pos[new_angle][0];
            int next_c = c + pos[new_angle][1];
            if(visited.find({next_r, next_c}) == visited.end() && robot.move()){
                dfs(next_r, next_c, new_angle, visited, robot);
                come_back(robot);
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        set<pair<int, int>> visited;
        dfs(0,0, 0, visited, robot);
        
    }
};