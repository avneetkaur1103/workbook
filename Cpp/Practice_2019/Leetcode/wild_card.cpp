// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(); // cols
        int m = p.size(); // rows
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(!j ){
                    if(p[i-1] == '*')
                        dp[i][j] = dp[i-2][j];
                }
                else{
                    if(s[j-1] == p[i-1] || p[i-1] == '.')
                        dp[i][j] = dp[i-1][j-1];
                    else if(p[i-1] == '*')
                        dp[i][j] = dp[i-2][j] || (dp[i][j-1] && (s[j-1] == p[i-2] || p[i-2] == '.'));
                }
             }
        }
        for(auto dpi: dp){
            for(auto val: dpi){
                cout << val << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};