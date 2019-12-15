#define all(c) c.begin(), c.end()
class Solution {
public:
    bool topological_sort(char u, unordered_map<char, vector<char>> adj, set<char>& visited, vector<char>& rec_stack, string& result){
        visited.insert(u);
        rec_stack.push_back(u);
        for(char v: adj[u]){
            if(visited.find(v) == visited.end()){
                if(topological_sort(v, adj, visited, rec_stack, result))
                    return true;
            }
            else if(find(all(rec_stack), v) != rec_stack.end())
                return true; // iscyclic = true;
        }
        result.push_back(u);
        rec_stack.pop_back();
        return false;
    }
        
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        int n = words.size();
        if(n  == 0)
            return "";  // can't determine order
        
        set<char> chars;
        for(int i = 0; i < n; i++){
            copy(all(words[i]), inserter(chars, chars.end()));
        }
        for(auto u: chars){
            adj[u] = {};
        }
        
        for(int i = 0; i <= n-2; i++){
            int l = 0;
            int _max_l = min(words[i].size(), words[i+1].size());
            while(l < _max_l){
                if(words[i][l] != words[i+1][l]){
                    adj[words[i][l]].push_back(words[i+1][l]);
                    //cout << words[i][l] << "->" << words[i+1][l] << endl;
                    break;
                }
                ++l;
            }
        }
            
        if(adj.size()){
            set<char> visited;
            string result;
            vector<char> rec_stack;
            for(auto u: chars){
                if(visited.find(u) == visited.end())
                    if(topological_sort(u, adj, visited, rec_stack, result))
                        return "";
            }
                
            reverse(all(result));
            return result;
        }
        return "";
    }
};