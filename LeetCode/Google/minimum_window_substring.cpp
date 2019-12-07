//https://leetcode.com/explore/interview/card/google/59/array-and-strings/345/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m == 1 || n < m){
            return s.find(t) == string::npos ? "" : t;
        }

        unordered_map<char, int> counter;
        set<char> pending(all(t));
        unordered_map<char, int> pattern_counts;
        for(auto i: t){
            pattern_counts[i] += 1;
        }

        int l = 0, r = 0;
        string max_string;
        for(int i = 0; i < n; i++){
            if(pending.size()){
                counter[s[i]]++;
                if(pending.find(s[i]) != pending.end() && pattern_counts[s[i]] == counter[s[i]])
                    pending.erase(s[i]);
                r++;
            }
            if(!pending.size()){
                while(!pending.size() && l < r){
                    counter[s[l]]--;
                    if(t.find(s[l]) != string::npos){
                        if(counter[s[l]] < pattern_counts[s[l]])
                            pending.insert(s[l]);
                    }
                    l++;
                }
                int len = r-(l-1);
                if(!max_string.size() || max_string.size() > len){
                    max_string = s.substr(l-1,len);
                }
            }
        }
        return max_string;
    }
};
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << "Ans: " << sol.minWindow(s, t);
}