// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<pair<int, int>> neighbor = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool is_valid(int r, int c, int nR, int nC, vector<vector<bool>>& visited){
        if(r >= 0 && r < nR && c >= 0 && c < nC && !visited[r][c])
            return true;
        return false;
    }
    void dfs(int r, int c, int nR, int nC, vector<vector<bool>>& visited, vector<vector<int>>& matrix, vector<int>& result, int dir){
        visited[r][c] = true;
        result.push_back(matrix[r][c]);
        for(int i = 0; i < 4; i++){
            dir = (dir+i)%4;
            auto d = neighbor[dir];
            int dr = d.first;
            int dc = d.second;
            if(is_valid(r+dr, c+dc, nR, nC, visited))
                dfs(r+dr, c+dc, nR, nC, visited, matrix, result, dir);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nR = matrix.size();
        if(!nR)
            return {};
        int nC = matrix[0].size();
        vector<vector<bool>> visited(nR, vector<bool>(nC, false));
        vector<int> result;
        dfs(0, 0, nR, nC, visited, matrix, result, 0);
        return result;
    }
};
