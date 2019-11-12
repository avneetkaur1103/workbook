/* HE practice AP article*/
#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;

std::vector<pair<int,int>> bridges;
void addEdge(std::vector<list<int>>& g , int i , int j){
	g[i].push_back(j);
	g[j].push_back(i);
}

void dfsForAP(std::vector<list<int>>& g, int u, int parent , std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<bool>& ap,int children){
	static int time  = 0 ;

	disc[u] = low[u] = ++time;
	visited[u] = true;
	for(auto v : g[u]){
		if(!visited[v]){
           	children++;
			dfsForAP(g,v,u,visited,disc,low,ap,0);
			low[u] = min(low[v],low[u]);
			if(parent == -1 && children > 1)
				ap[u] = true;
			if(parent != -1 && low[v] >= disc[u]){
                ap[u] = true;
			}
			if(low[v] > disc[u])
				bridges.push_back({min(u,v),max(u,v)});

		}
		else if(v != parent){
			low[u] = min(low[u], disc[v]);
		}
	}
}
void printAP(std::vector<list<int>>& g){
	int n = g.size();
	std::vector<bool> visited(n,false);
	std::vector<int> disc(n,0);
	std::vector<int> low(n,0);
	std::vector<bool> ap(n,false);
	bridges.clear();
	for(int i = 0 ; i < n ; i++){
		if(!visited[i])
			dfsForAP(g,i,-1,visited,disc,low,ap,0);
	}
	cout << count_if(ap.begin(), ap.end() , [](auto i){ return i==true; }) << endl;
	for(int i = 0 ; i < ap.size() ; i++)
        if(ap[i]) cout << i << " ";
    cout << endl;
    sort(all(bridges));
    cout << bridges.size() << endl;
    for(auto& i: bridges){
    	cout << i.first << " " << i.second << endl;
    }
}
int main(){
    int n , m ,u ,v;
	cin >> n >> m;
	std::vector<list<int>> graph(n);
	for(int i = 0 ; i < m ; i++){
		cin >> u >> v;
		addEdge(graph,u, v);
	}
	printAP(graph);

}
