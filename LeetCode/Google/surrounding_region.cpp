// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/843/

class Solution {
public:
    const set<pair<int, int>> neighbours = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; //left, up, right, down
    bool is_safe(int r, int c, int nR, int nC){
        return r >= 0 && r < nR && c >= 0 && c < nC;
    }
    void dfs(int r, int c, int nR, int nC, vector<vector<char>>& board, vector<vector<bool>>& visited){
        visited[r][c] = true;
        for(auto p: neighbours){
            int next_r = r + p.first;
            int next_c = c + p.second;
            if(is_safe(next_r, next_c, nR, nC) && !visited[next_r][next_c] && board[next_r][next_c] == 'O')
                dfs(next_r, next_c, nR, nC, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int nR = board.size();
        if(!nR || nR < 3)
            return;
        int nC = board[0].size();
        if(!nC || nC < 3)
            return;
        
        vector<vector<bool>> visited(nR, vector<bool>(nC, false));
        for(auto i: {0, nR-1}){ // 1st & last row all col
            for(int j = 0 ; j < nC; j++){
                if(!visited[i][j] && board[i][j] == 'O')
                    dfs(i, j, nR, nC, board, visited);
            }
        }
        
        for(int i = 0 ; i < nR; i++){ // 1st & last col all rows
            for(auto j: {0, nC-1}){
                if(!visited[i][j] && board[i][j] == 'O')
                    dfs(i, j, nR, nC, board, visited);
            }
        }
        
        for(int i = 0; i < nR; i++){
            for(int j = 0; j < nC; j++){
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};