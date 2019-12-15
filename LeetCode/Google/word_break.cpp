// https://leetcode.com/explore/interview/card/facebook/55/dynamic-programming-3/3036/
#define all(c) c.begin(), c.end()
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(all(wordDict));
        int n = s.length();
        vector<int> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                int len = i-j;
                string word = s.substr(j, len);
                //cout << "Word: " << word << endl;
                if(words.find(word) != words.end() && dp[j]){
                    dp[i] = true; 
                    break;
                }   
            }
        }
        return dp[n];
        
    }
};