// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wcmap;
        unordered_map<string, int> twcmap;
        vector<int> result;
        for(auto word: words){
            wcmap[word] += 1;
        }
        int wc = words.size();
        if(!wc)
            return {};
        int wl = words[0].size();
        int n = s.size();
        for(int i = 0; i < wl; i++){
            int left = i;
            int right = left+wl;
            int currsize = 0; twcmap.clear();    
            while(right <= n){
                string next = s.substr(right-wl, wl);
                if(wcmap.find(next) != wcmap.end()){
                    while(left < right && wcmap[next] <= twcmap[next]){
                        string temp = s.substr(left, wl);
                        left += wl;
                        twcmap[temp] = twcmap[temp] > 0 ? twcmap[temp] - 1 : 0;
                        currsize--;
                    }
                    if(wcmap[next] > twcmap[next]){
                        currsize++;
                        twcmap[next]++;
                    }
                }
                else{
                    left = right;
                    currsize = 0;
                    twcmap.clear();
                }
                if(currsize == wc){
                    result.push_back(left);
                    string temp = s.substr(left, wl);
                    left += wl;
                    twcmap[temp] = twcmap[temp] > 0 ? twcmap[temp] - 1 : 0;
                    currsize--;
                }
                right += wl;
            }
        }
        return result;
    }
};