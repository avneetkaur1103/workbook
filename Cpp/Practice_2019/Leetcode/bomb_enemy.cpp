// https://leetcode.com/problems/bomb-enemy/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if(!n)
            return 0;
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < n; i++){ // left to right col wise
            count = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'E')
                    count++;
                if(grid[i][j] == 'W')
                    count = 0;
                if(grid[i][j] == '0')
                    dp[i][j] += count;
            }
            count = 0;
            for(int j = m-1; j >= 0; j--){ // right to left col wise
                if(grid[i][j] == 'E')
                    count++;
                if(grid[i][j] == 'W')
                    count = 0;
                if(grid[i][j] == '0')
                    dp[i][j] += count;
            }
        }
        for(int i = 0; i < m; i++){
            count = 0;
            for(int j = 0; j < n; j++){ // top to bottom row wise
                if(grid[j][i] == 'E')
                    count++;
                if(grid[j][i] == 'W')
                    count = 0;
                if(grid[j][i] == '0')
                    dp[j][i] += count;
            }
            count = 0;
            for(int j = n-1; j >= 0; j--){ // bottom to top row wise
                if(grid[j][i] == 'E')
                    count++;
                if(grid[j][i] == 'W')
                    count = 0;
                if(grid[j][i] == '0')
                    dp[j][i] += count;
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                result = max(result, dp[i][j]);
        
        return result;
    }
};