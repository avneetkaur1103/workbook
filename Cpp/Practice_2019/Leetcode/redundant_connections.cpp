#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution {
public:
    vector<int> dfs(int u, vector<vector<int>>& adj, vector<int>& parent, unordered_set<int>& recstack){
        for(auto v: adj[u]){
            if(parent[v] == -1){
                parent[v] = u;
                recstack.insert(u);
                auto vec = dfs(v, adj, parent, recstack);
                if(vec.size())
                    return vec;
                recstack.erase(u);
            }
            else if(recstack.find(v) != recstack.end())
                return {u,v};
            else
                return {parent[v], v};
        }
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n,vector<int>());
        vector<int> incoming(n, 0);
        for(auto p: edges){
            adj[p[0]-1].push_back(p[1]-1);
            incoming[p[1]] += 1;
        }
        int root = find(all(incoming), 0) - incoming.begin();
        cout << "root: " << root << endl;
        vector<int> parent(n, -1);
        unordered_set<int> recstack;
        parent[root] = 0;
        auto result = dfs(root, adj, parent, recstack);
        return {result[0]+1, result[1]+1};
    }
};

