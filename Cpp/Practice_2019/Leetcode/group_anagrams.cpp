// https://leetcode.com/problems/group-anagrams/
#define all(c) c.begin(), c.end()
class Solution {
public:
    string calculate(string s){
        vector<int> counter(26, 0);
        for(auto ch: s){
            counter[ch-'a']++;
        }
        string result;
        for(auto i : counter){
            result += i + '0';
        }
        // cout << "Result: " << result << endl;
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;
        for(auto s: strs){
            string key = calculate(s);
            mapping[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto p: mapping)
            result.push_back(p.second);
        return result;
    }
};