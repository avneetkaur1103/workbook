// https://www.geeksforgeeks.org/check-if-there-is-a-cycle-with-odd-weight-sum-in-an-undirected-graph/
#include <bits/stdc++.h>
using namespace std;

bool is_bipertite(int u, vector<vector<int>>& adj, vector<int>& colors, int c){
	colors[u] = c;
	for(auto v: adj[u]){
		if(colors[v] == -1){
			if(!is_bipertite(v, adj, colors, !c))
				return false;
		}
		else if(colors[v] == c)
			return false;
	}
	return true;
}

bool isOddSum(vector<vector<int>>& info, int n, int m){
	vector<vector<int>> adj(2*n);
	int pseudo = n;
	for(auto edge: info){
		int u = edge[0];
		int v = edge[1];
		if(!(edge[2]&1)){
			adj[u].push_back(pseudo);
			adj[pseudo].push_back(v);
			adj[v].push_back(pseudo);
			adj[pseudo].push_back(u);
		}
		else{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	vector<int> colors(2*n);
	return is_bipertite(0, adj, colors, 0);

}

int main() {
    int n = 4, m = 3;
    vector<vector<int>> info = {{1, 2, 12},
                     {2, 3, 1},
                     {4, 3, 1},
                     {4, 1, 20}};

    if (isOddSum(info, n, m) == true)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}
