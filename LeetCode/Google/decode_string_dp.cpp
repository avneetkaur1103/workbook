// https://leetcode.com/explore/interview/card/facebook/55/dynamic-programming-3/264/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; i++){
            if(i == 1){
                if(s[i-1] - '0' == 0)
                    return 0;
                if(s[i-1]-'0' > 0)
                    dp[i] = 1;
            }
            else{
                if(s[i-1]-'0' > 0)
                    dp[i] = dp[i-1];
                if((s[i-1] - '0' < 7 &&s[i-2] - '0' == 2) || (s[i-2] - '0' == 1))
                    dp[i] += i==2? 1:dp[i-2];
            }
        }
        return dp[n];
    }
};