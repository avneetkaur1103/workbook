#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	std::vector<list<int>> adj;
	Graph(int n):{adj.reserve(n)};
	Graph getTranspose(){
		Graph g(adj.size);
		for(int i = 0 ; i < adj.size; i++){
			for(auto v : adj[i]){
				g.adj[v].push_back(i);
			}
		}
		return g;
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}
}

void fillStack(Graph& g, std::vector<bool>& visited, int src, stack<int>& stackOrder){
	visited[src] = true; 
	for(auto i: g.adj[src]){
		if(!visited[i]){
			fillStack(g,visited,i,stackOrder);
		}
	}
	stackOrder.push(src);
}

void doDfs(Graph& g , src, std::vector<bool>& visited){
	visited[src] = true;

	for(auto i : g.adj[src]){
		if(!visited[i])
			doDfs(g,i,visited);
	}
}

void printSCCs(Graph& g){
	int n = g.adj.size();
	std::vector<bool> visited(n,false);
	stack<int> stackOrder;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			fillStack(g,visited,i,stackOrder)
		}
	}
	Graph trG = g.getTranspose();
	fill(visited.begin() , visited.end(), false);

	while(!stackOrder.empty()){
		int u = stackOrder.top();
		stackOrder.pop();
		if(!visited[u])
			doDfs(trG,u,visited);
	}
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
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