// https://www.geeksforgeeks.org/eulerian-path-undirected-graph/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

void findpath(vector<vector<int>>& adj){
	int n = adj.size();
	int start = -1; int oc = 0;
	for(int i = 0; i < n; i++){
		int degree = accumulate(all(adj[i]), 0);
		if(degree&1){
			start = i;
			oc++;
		}
	}
	if(!oc)
		start = 0;

	stack<int> st;
	int curr = start;
	while(!st.empty() || accumulate(all(adj[curr]), 0)){
		if(accumulate(all(adj[curr]), 0) == 0){
			cout << curr << " ";
			curr = st.top(); st.pop();
		}
		else{
			for(int i = 0; i < n; i++){
				if(adj[curr][i]){
					st.push(curr);
					adj[curr][i] = 0;
					adj[i][curr] = 0;
					curr = i;
					break;
				}
			}
		}
	}
	cout << curr << endl;
}

int main()
{
    // Test case 1
    vector<vector<int>> graph1 = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 1, 0},
                       {0, 1, 1, 0, 0},
                       {1, 0, 0, 0, 0}};
    findpath(graph1);
}
