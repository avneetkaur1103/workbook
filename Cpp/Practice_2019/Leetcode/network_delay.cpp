// https://leetcode.com/problems/network-delay-time/
#define all(c) c.begin(), c.end()
typedef pair<int, int> pii;

class Solution {
public:
    int dijkstra(vector<vector<pii>>& adj, int n, int src){
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto temp = pq.top(); pq.pop();
            int u = temp.second;
            for(auto p: adj[u]){
                int v = p.first;
                int w = p.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxtime = *max_element(all(dist));
        return maxtime == INT_MAX ? -1: maxtime;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>> adj(N);
        for(auto p: times){
            adj[p[0]-1].push_back({p[1]-1, p[2]});
        }
        return dijkstra(adj, N, K-1);
    }
};