// https://leetcode.com/problems/reconstruct-itinerary/
class Solution {
public:
    void dfs(string u, unordered_map<string, set<string>>& adj, vector<string>& routes){
        while(!adj[u].empty()){
            auto it = adj[u].begin();
            string temp = *it; adj[u].erase(it);
            dfs(temp, adj, routes);
        }
        routes.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> adj;
        for(auto p: tickets){
            adj[p[0]].insert(p[1]);
        }
        vector<string> routes;
        dfs("JFK", adj, routes);
        reverse(routes.begin(), routes.end());
        return routes;
    }
};