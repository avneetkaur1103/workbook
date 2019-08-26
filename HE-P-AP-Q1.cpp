/* HE practice AP article Q1*/
#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;

std::vector<pair<int,int>> bridges;
std::vector<int> ap;
void addEdge(std::vector<list<int>>& g , int i , int j){
	g[i].push_back(j);
	g[j].push_back(i);
}

int dfsForAP(std::vector<list<int>>& g, int u, int parent , std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& ap,int children){
	static int time  = 0 ;

	disc[u] = low[u] = ++time;
	visited[u] = true;
	int _count = 0 ;
	for(auto v : g[u]){
		if(!visited[v]){
           	children++;
           	_count++;
			_count += dfsForAP(g,v,u,visited,disc,low,ap,0);
			low[u] = min(low[v],low[u]);
			if(parent == -1 && children > 1)
				ap[u] = _count;
			if(parent != -1 && low[v] >= disc[u]){
                ap[u] = _count;
			}
			if(low[v] > disc[u])
				bridges.push_back({min(u,v),max(u,v)});

		}
		else if(v != parent){
			low[u] = min(low[u], disc[v]);
		}
	}
	return _count;
}
void printAP(std::vector<list<int>>& g){
	int n = g.size();
	std::vector<bool> visited(n,false);
	std::vector<int> disc(n,0);
	std::vector<int> low(n,0);
	bridges.clear();
	ap.clear();
	ap.resize(n,0);
	for(int i = 0 ; i < n ; i++){
		if(!visited[i])
			dfsForAP(g,i,-1,visited,disc,low,ap,0);
	}
	// cout << count_if(ap.begin(), ap.end() , [](auto i){ return i==true; }) << endl;
	// for(int i = 0 ; i < ap.size() ; i++)
 	//	 if(ap[i]) cout << i << " ";
    // cout << endl;
    // sort(all(bridges));
    // cout << bridges.size() << endl;
    // for(auto& i: bridges){
    // 	cout << i.first << " " << i.second << endl;
    // }
}
int main(){
    int n , m ,u ,v, Q;
	cin >> n >> m;
	std::vector<list<int>> graph(n);
	for(int i = 0 ; i < m ; i++){
		cin >> u >> v;
		addEdge(graph,u-1, v-1);
	}
	printAP(graph);
	cin >> Q;
	for(int i  = 0 ; i < Q; i++){
		cin >> u;
		ap[i] ? cout << "Satisfied " <<ap[i] : cout << "Not Satisfied";
		cout << endl;
	}


}
