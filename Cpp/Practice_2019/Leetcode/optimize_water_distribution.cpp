// https://leetcode.com/problems/optimize-water-distribution-in-a-village/

class Solution {
public:
    int mst_cost(vector<vector<pair<int, int>>>& adj, vector<int>& wells, int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({wells[i], i});
        }
        vector<bool> in_mst(2*n, false);
        vector<int> dist(n, INT_MAX);
        fill(in_mst.begin()+n, in_mst.end(), true);
        int cost = 0;
        while(!pq.empty()){
            auto tmp = pq.top(); pq.pop();
            int u = tmp.second; int w = tmp.first;
            if(!in_mst[u]){
                in_mst[u] = true;
                cost += w;
                //cout << "u:" << u << " w " << w << endl;
                for(auto p: adj[u]){
                    int v = p.first; w = p.second;
                    //cout << "\tv " << v << " w " << w << endl;
                    if(!in_mst[v] && dist[v] > w){
                        dist[v] = w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return cost;
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<pair<int, int>>> adj(2*n);

        for(auto vec: pipes){
            adj[vec[0]-1].push_back({vec[1]-1, vec[2]});
            adj[vec[1]-1].push_back({vec[0]-1, vec[2]});
        }
        return mst_cost(adj, wells, n);
    }
};