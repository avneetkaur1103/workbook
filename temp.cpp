/* HE practice AP article Q3*/
#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;

class Graph
{
    int v;
    std::vector<list<pair<int,int>>> adj;
public:
    graph(int n): v(n)
    {
        adj.resize(n)
    };
    void addEdge(int u, int v, int b){
        adj[u] = {v,b};
        adj[v] = {u,b};
    }
    int size(){ return v};
    
};

void dfs(Graph& g, vector<int>& visited, int src, target){
    static int time = 1;
    visited[src] = time;

    for(auto i : g[src]){
        int v = i.first;
        int rose = i.second; 
        if(!visited[v]){
            if(rose) time++;
            dfs(g,visited,v,target);
        }else{
            if(time > 1 && visited[target])
                return true;
        }
    }
}
bool solve(Graph& g , int boy, int girl){

    std::vector<int> visited(g.size(),0);


}
int main(){
    int n,m,u,v,b;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < n; i++){
        cin >> u >> v >> b;
        graph.addEdge(u-1,v-1,b);
    }
 
}