/* HE practice AP article Q3*/
#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;
 
unordered_map<int,pair<int,int>> bridges;
std::vector<int> ap;
void addEdge(std::vector<list<pair<int,int>>>& g , int i , int j, int id){
	g[i].push_back({j,id});
	g[j].push_back({i,id});
}
 
void dfsForAP(std::vector<list<pair<int,int>>>& g, int u, int parent , std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& ap,int children){
	static int time  = 0 ;
 
	disc[u] = low[u] = ++time;
	visited[u] = true;
	for(auto x : g[u]){
		int v = x,first;
		if(!visited[v]){
           	children++;
			dfsForAP(g,v,u,visited,disc,low,ap,0);
			low[u] = min(low[v],low[u]);
 
			if(low[v] > disc[u])
				bridges[x.second] = {u,v};
 
		}
		else if(v != parent){
			low[u] = min(low[u], disc[v]);
		}
	}
}
void printAP(std::vector<list<pair<int,int>>>& g){
	int n = g.size();
	std::vector<bool> visited(n,false);
	std::vector<int> disc(n,0);
	std::vector<int> low(n,0);
	bridges.clear();
	for(int i = 0 ; i < n ; i++){
		if(!visited[i])
			dfsForAP(g,i,-1,visited,disc,low,ap,0);
	}
 
}
int main(){
    int n , m ,u ,v, Q,index,id;
	cin >> n >> m >> Q;
	std::vector<list<pair<int,int>>> graph(n);
	for(int i = 0 ; i < m ; i++){
		cin >> u >> v >>id;
		addEdge(graph,u-1, v-1,id);
	}
	printAP(graph);
	for(int i  = 0 ; i < Q; i++){
		cin >> index;
		bridges[index] ? cout << "YES" : cout << "no";
		cout << endl;
	} 
}