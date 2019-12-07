#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

class Solution {
public:
	void buff_copy(char* buff, int& buff_index, string s, int& si, int n, string& source, string& target){
		int i = 0;
        if(s.substr(si, source.length()) == source){
            si += source.length();
            while(i < target.length()){
                buff[++buff_index] = target[i++];
            }
        }

	}
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        char buff[2000]; int buff_index = -1;
        int n = s.length();
        int vi = 0; int vl = sources.size();

        vector<pair<int, int>> index_map;
        for(int i = 0; i < vl; i++){
            index_map.push_back({indexes[i], i});
        }
        sort(all(index_map));

        int i = 0;
        while(i<n){
        	if(vi < vl && i == index_map[vi].first){
                cout << "source: " << sources[index_map[vi].second] << " target: " << targets[index_map[vi].second] << endl;
        		buff_copy(buff, buff_index, s, i, n, sources[index_map[vi].second], targets[index_map[vi].second]);
        		vi++;
        	}
        	else
        		buff[++buff_index] = s[i++];
        }
        buff[++buff_index] = '\0';
        string result(buff);
        return result;
    }
};