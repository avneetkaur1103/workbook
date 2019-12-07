#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	int n = nums.size(); vector<long> sums(n);
    	vector<vector<long>> dp(m, vector<long>(n, INT_MAX));

    	sums[0] = nums[0];
    	for(int i = 1; i < n; i++){
    		sums[i] = sums[i-1] + nums[i];
    		dp[0][j] = sums[j];
    	}

    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(j == i){
    				dp[i][j] = *max_element(&nums[0], &nums[j]+1);
    			}
    			else if(j > i){
    				int temp = j-1;
    				while(i-1 <= temp){
    					dp[i][j] = min(dp[i][j], max(dp[i-1][temp], sums[j]-sums[temp]));
    					temp--;
    				}
    			}
    		}
    	}
    	return dp[m-1][n-1];
    }
};