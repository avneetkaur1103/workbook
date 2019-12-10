class Solution {
public:
	int diff(string& s1, string& s2){
		int count = 0;
		for(int i = 0; i < s1.size(); i++){
			count += s1[i] == s2[i]? 0 : 1;
		}
		return count;
	}
	int bfs(unordered_map<string, vector<string>>& adj, string start, string target, unordered_set<string>& visited, vector<string>& wordList){
		queue<pair<string, int>> q;
		q.push({start, 1});

		while(!q.empty()){
			auto p = q.front(); q.pop();
			if(p.first == target)
				return p.second;
            
            visited.insert(p.first);
            for(auto word: adj[p.first]){
                if(visited.find(word) == visited.end()){
                    //cout << word << ":" << 1+p.second << endl;
                    q.push({word,1+p.second});
                }
            }
	    }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        for(int i = 0; i< wordList.size(); i++){
            for(int j = i+1; j<wordList.size(); j++){
                string u = wordList[i]; string v = wordList[j];
                if(diff(u,v) == 1){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        unordered_set<string> visited;
        return bfs(adj, beginWord, endWord, visited, wordList);
    }
};