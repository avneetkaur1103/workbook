#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const map<string, string> mapping = {{"0","0"}, {"1","1"}, {"6","9"}, {"8","8"}, {"9","6"}};
    vector<string> calculate(int n){
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"0", "1", "8"};
        for(int i = 2; i <= n; i++){
            for(auto str: dp[i-2]){
                for(auto p: mapping){
                    cout << "Dubug: " << p.first << ":" << p.second << endl;
                    dp[i].push_back(p.first + str + p.second);
                }
            }
        }
        return dp[n];
    }
    vector<string> findStrobogrammatic(int n) {
        if(!n)
            return vector<string>{""};
        if(n == 1){
            return vector<string>{"0", "1", "8"};
        }
        //nums staring with 1, 6, 8, 9
        vector<string> dp = calculate(n-2);
        vector<string> result;
        for(auto str: dp){
            for(auto p: mapping){
                if(p.first != "0")
                result.push_back(p.first + str + p.second);
            }
        }

        return result;
    }
};
int main(){
    vector<string> words = {"abat","baba","atan","atal"};
    Solution sol;
    auto result = sol.findStrobogrammatic(2);

    for(auto words: result)
        cout << words << endl;
}
