// https://www.geeksforgeeks.org/delete-edge-minimize-subtree-sum-difference/
#include <bits/stdc++.h>
using namespace std;

#define all(c) c.begin(), c.end()

int dfs(int u, vector<vector<int>>& adj, vector<int>& vertex, int parent, int total, int& result){
	int sum = vertex[u];
	for(auto v: adj[u]){
		if(v != parent){
			sum += dfs(v, u, adj, vertex, total, result);
		}
	}
	result = min(result, total-2*sum);
	return sum;
}
int getMinSubtreeSumDifference(vector<int>& vertex, vector<vector<int>>& edges){
	int n = vertex.size();
	vector<vector<int>> adj(n);
	for(auto edge: edges){
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	int total = accumulate(all(vertex), 0);
	int result = INT_MAX;
	dfs(0, -1, adj, vertex, total, result);
	return result;
}

int main() 
{ 
    vector<int> vertex = {4, 2, 1, 6, 3, 5, 2}; 
    vector<vector<int>> = {{0, 1}, {0, 2}, {0, 3}, 
                      {2, 4}, {2, 5}, {3, 6}};
    cout << getMinSubtreeSumDifference(vertex, edges); 
    return 0; 
}