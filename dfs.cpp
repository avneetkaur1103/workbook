#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int odd , even;

void doDfs(std::vector<list<int>>& G ,vector<bool>& visited, int src , int level){
	for(auto& i : G[src]){
		if(!visited[i]){
            visited[i] = true;
			level&1 ? odd++ : even++;
			doDfs(G,visited,i,level+1);
		}
	}
}
int countPairs(std::vector<list<int>>& G ){
	int src  = 0 , level = 0;
	vector<bool> visited(G.size(), false);
	visited[src] = true;
	even++;
	doDfs(G,visited,src,level);
	return (odd*(odd-1))/2 + (even*(even-1))/2;
}
int main(){
	int n_tc;
	cin >> n_tc;
	while(n_tc--){
		int n;
		cin >> n;
		std::vector<list<int>> G(n);
		for (int i = 0; i < n-1; ++i)
		{
			/* code */
			int x, y;
			cin >> x >> y;
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		}
		odd  = 0 ; even = 0;
		cout << countPairs(G) << endl;
	}
}
