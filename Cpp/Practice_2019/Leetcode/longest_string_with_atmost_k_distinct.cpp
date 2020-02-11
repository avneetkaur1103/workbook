// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int getmin(unordered_map<char, int>& lastseen){
        int min = INT_MAX;
        for(auto p: lastseen){
            if(p.second < min)
                min = p.second;
        }
        return min;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(k*n == 0) return 0;
        
        unordered_map<char, int> lastseen;
        int max_len = 0; int left = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            lastseen[ch] = i;
            if(lastseen.size() == k+1){
                left = getmin(lastseen);
                lastseen.erase(s[left]);
                left = left + 1;
            }
            max_len = max(max_len, i-left+1);
        }
        return max_len;
    }
};