#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;

struct Graph{
	vector<vector<int>> adj;
	int v;
	Graph(int n = 0){
		v = n;
		adj.reserve(v);
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}

	Graph get_transpose(){
		Graph g(v);
		for(int u = 0; u < v; u++){
			for(auto v: adj[u]){
				g.adj[v].push_back(u);
			}
		}
		return g;
	}
	void printSCCs();
};
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
	visited[u] = true;
	for(auto v: adj[u]){
		if(!visited[v])
			dfs(v, adj, visited, st);
	}
	st.push(u);
}

void dfsprint(int u, vector<vector<int>>& adj, vector<bool>& visited){
	visited[u] = true;
	cout << u << " ";
	for(auto v: adj[u]){
		if(!visited[v])
			dfsprint(v, adj, visited);
	}
}

void Graph::printSCCs(){
	vector<bool> visited(v, false);
	stack<int> result;
	for(int i = 0; i < v; i++){
		if(!visited[i])
			dfs(i, adj, visited, result);
	}
	dfs(0, adj, visited, result);

    Graph g = get_transpose();
	fill(all(visited), false);
	while(!result.empty()){
		int top = result.top();
		result.pop();
		if(!visited[top])
			dfsprint(top, g.adj, visited);
            cout << endl;
	}
}

int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
    return 0;
}
