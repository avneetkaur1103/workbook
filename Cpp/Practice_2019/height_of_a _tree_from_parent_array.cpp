// https://www.geeksforgeeks.org/height-generic-tree-parent-array/
#include <bits/stdc++.h>
using namespace std;

int height(int i, vector<int>& dp, vector<int>& parents){
	if(dp[i] != -1)
		return dp[i];

	else if(parents[i] == -1)
		return 0;

	dp[i] = 1 + height(parents[i], dp, parents);
	return dp[i];
}

int findHeight(vector<int> parents){
	int n = parents.size();
	vector<int> dp(n, -1);

	int max_height = -1;
	for(int i = 0; i < n; i++){
		if(dp[i] == -1)
			height(i, dp, parents);
		max_height = max(max_height, dp[i]);
	}
	return max_height;
}

int main()
{
    vector<int> parent = { -1, 0, 0, 0, 3, 1, 1, 2 };
    cout << "Height of N-ary Tree = "
         << findHeight(parent);
    return 0;
}
