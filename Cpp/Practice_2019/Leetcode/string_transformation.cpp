// https://leetcode.com/problems/string-transforms-into-another-string/

#define all(c) c.begin(), c.end()

class Solution {
public:
    bool dfs(char u, unordered_map<char, char>& adj, unordered_set<char>& visited, unordered_set<char>& recstack, int& freecharcount){
        if(adj.find(u) == adj.end())
            return true;
        
        visited.insert(u);
        recstack.insert(u);
        if(recstack.find(adj[u]) != recstack.end()){
            if(freecharcount){
                freecharcount--;
                recstack.erase(u);
                return true;
            }
            else
                return false;
        }
        bool result = dfs(adj[u], adj, visited, recstack, freecharcount);
        recstack.erase(u);
        return result;
    }
    
    bool is_cyclic(unordered_map<char, char>& adj, int& freecharcount){
        unordered_set<char> visited;
        unordered_set<char> recstack;
        for(auto p: adj){
            char u = p.first;
            if(visited.find(u) == visited.end()){
                if(!dfs(u, adj, visited, recstack, freecharcount))
                    return true;
            }
        }
        return false;
    }
    bool canConvert(string str1, string str2) {
        int n = str1.length();
        if(n < 2)
            return true;
        
        unordered_map<char, char> adj;
        int freecharcount = 0;
        unordered_set<char> allchars;        
        for(int i = 0; i < n; i++){
            char a = str1[i]; char b = str2[i];
            if(a == b)
                continue;
            if(adj.find(a) != adj.end() && adj[a] != b)
                return false; // 2 outgoing edges
            adj[a] = b;
            allchars.insert(a);
        }
        freecharcount = 26 - allchars.size();
        if(is_cyclic(adj, freecharcount)){
            cout << "Cyclic";
            return false;
        }
        return true;
    }
};