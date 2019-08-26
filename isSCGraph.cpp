#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int v;
	std::vector<list<int>> adj;
	void dfsUtil(int src, std::vector<bool>& visited);
	Graph getTranpose();
public:
	Graph(int n):v(n){adj.resize(n);};
	void addEdge(int i , int j){
		adj[i].push_back(j);
	}
	bool isSC();

};

void Graph::dfsUtil(int src, std::vector<bool>& visited){
	visited[src] = true;
	for(auto i :  adj[src]){
		if(!visited[i])
			dfsUtil(i,visited);
	}
}
Graph Graph::getTranpose(){
	Graph g(v);
	for(int i = 0 ; i < adj.size() ; i++){
		for(auto v : adj[i])
			g.addEdge(v,i);
	}
	return g;
}

bool Graph::isSC(){
	std::vector<bool> visited(v,false);
	dfsUtil(0,visited);

	for(auto i : visited)
		if(!i) return false;
	Graph trG = std::move(getTranpose());

	fill_n(visited.begin(),v,false);

	trG.dfsUtil(0,visited);
	for(auto i : visited)
		if(!i) return false;

	return true;
}

int main(){

    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";
    return 0;
}
