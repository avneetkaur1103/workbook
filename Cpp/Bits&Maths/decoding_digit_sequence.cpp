#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& arr){
	int n = arr.size();
	vector<int> dp(n+1, 0);

	dp[0] = 1; dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1];
		if(arr[i-2] == 1 || arr[i-1] < 7 && arr[i-2] < 3){
			dp[i] += dp[i-2];
		}
	}
	return dp[n];
}
int main(){
	vector<int> v = {1,2,3,4};
	cout << count(v);
}
