// https://leetcode.com/problems/zigzag-conversion/submissions/
class Solution {
public:
    string convert(string s, int numRows) {
        map<int, string> _map;
        int n = s.length();
        int i = 0;
        while(i < n){
            for(int h = 0; h < numRows && i < n; h++){
                _map[h].push_back(s[i]); i++;
            }
            for(int h = numRows-2; h > 0 && i < n; h--){
                _map[h].push_back(s[i]); i++;
            }
        }
        string result;
        for(auto p: _map){
            cout << "Key: " << p.first << " val: " << p.second << endl;
            result += p.second;
        }
        return result;
    }
};