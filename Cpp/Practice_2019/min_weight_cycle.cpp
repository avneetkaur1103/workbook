// https://www.geeksforgeeks.org/find-minimum-weight-cycle-undirected-graph/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
struct Edge{
	int u;
	int v;
	int w;
};

class Graph{
	public:
		vector<vector<pair<int, int>>> adj;
		int v;
		vector<Edge> edges;
		Graph(int n){
			v = n;
			adj.reserve(n);
		}
		void addEdge(int u, int v, int w){
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			edges.push_back({u,v,w});
		}
		void _addEdge(int u, int v, int w){
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		void _remove_edge(int u, int v, int w){
		    auto it = find(all(adj[u]), make_pair(v, w));
			adj[u].erase(it);
			it = find(all(adj[v]), make_pair(u, w));
			adj[v].erase(it);
		}
};
int dijkstra(Graph& g, int src, int dest){
	int n = g.v;
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
	set<pair<int, int>> dset;
	dset.insert({0, src});
	while(!dset.empty()){
		pair<int, int> temp = *(dset.begin());
		dset.erase(dset.begin());
		int u = temp.second;
		for(auto p: g.adj[u]){
			int v = p.first;
			int w = p.second;
			if(dist[v] > dist[u]+w){
                if(dist[v] != INT_MAX){
                    auto it = dset.find({dist[v],v});
                    dset.erase(it);
                }
				dist[v] = dist[u]+w;
				dset.insert({dist[u]+w, v});
			}
		}
	}
	return dist[dest];
}

int min_weight_cycle(Graph& g){
	int result = INT_MAX;
	for(auto edge: g.edges){
		int u = edge.u;
		int v = edge.v;
		int w = edge.w;
		g._remove_edge(u, v, w);
		int dresult = dijkstra(g, u, v);
		if(dresult != INT_MAX)
			result = min(result, w+dresult);
		g._addEdge(u, v, w);
	}
	return result;
}

int main()
{
    int V = 9;
    Graph g(V);

    // making above uhown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << min_weight_cycle(g) << endl;
    return 0;
}
