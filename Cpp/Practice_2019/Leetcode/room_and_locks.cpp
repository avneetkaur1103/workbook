https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        for(auto v: adj[u]){
            if(!visited[v])
                dfs(v, adj, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n < 2)
            return true;
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int u = 0; u < n; u++){
            for(auto v: rooms[u])
                adj[u].push_back(v);
        }
        dfs(0, adj, visited);
        return all_of(visited.begin(), visited.end(), [](int val){ return val == true;});
    }
};