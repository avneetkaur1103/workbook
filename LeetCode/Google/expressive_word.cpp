#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<int, pair<char, int>> get_group_freequnecy(string& word){
        map<int, pair<char, int>> counter;
        int n = word.size();
        int start = -1;
		for(int i = 0; i < n; i++){
    		if(i && word[i] == word[i-1]){
    			counter[start].second += 1;
    		}
    		else{
    			counter[++start] = {word[i], 1};
    		}
    	}
        return counter;
	}
    int expressiveWords(string s, vector<string>& words) {
    	map<int, pair<char, int>> query_freeq = get_group_freequnecy(s);
    	print(query_freeq);
    	int count = 0;
    	for(auto word: words){
    		map<int, pair<char, int>> freeq = get_group_freequnecy(word);
    		print(freeq);
    		if(! freeq.size() == query_freeq.size()) continue;

			auto itrq = query_freeq.begin();
    		for(auto itrw = freeq.begin(); itrq != query_freeq.end() && itrq->second.first == itrw->second.first; itrq++, itrw++){
  				int qcount = itrq->second.second; int wcount = itrw->second.second;
    			if((qcount < 3 && qcount == wcount) || (qcount >= 3 && wcount <= qcount)) continue;
                else break;
    		}
    		count += itrq == query_freeq.end() ? 1: 0;
    	}
    	return count;
    }
};