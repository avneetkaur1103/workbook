// https://www.geeksforgeeks.org/find-k-cores-graph/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
	vector<vector<int>> adj;
	int v;
	Graph(int n){
		v = n;
		adj.reserve(n);
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void printKCores(int k);
};

bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& degree, int k){
	visited[u] = true;
	for(auto v: adj[u]){
		if(degree[u] < k)
			degree[v]--;
        if(!visited[v])
            if(dfs(v, adj, visited, degree, k))
                degree[u]--;
	}
	return degree[u] < k;
}

void Graph::printKCores(int k){
	vector<int> degree(v);
	int min_degree = INT_MAX;
	int start = -1;
	for(int i = 0; i < v; i++){
		degree[i] = adj[i].size();
		if(degree[i] < k && degree[i] < min_degree){
			start = i;
			min_degree = degree[i];
		}
	}
	if(start == -1){
		cout << "Already K-Core" << endl;
		return;
	}

	vector<bool> visited(v, false);
	dfs(start, adj, visited, degree, k);
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			dfs(i, adj, visited, degree, k);
		}
	}
	for(int i = 0; i < v; i++){
		if(degree[i] >= k){
			cout << "[" << i << "]";
			for(auto v: adj[i]){
				if(degree[v] >= k)
					cout << " -> " << v;
			}
			cout << endl;
		}
	}
}


int main()
{
    // Create a graph given in the above diagram
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);
}
