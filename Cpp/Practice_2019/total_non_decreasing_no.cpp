// https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

int countNonDecreasing(int n){
	vector<vector<int>> dp(n+1, vector<int>(10, 0));
	for(int len = 1; len <= n; len++){
		for(int d = 0; d < 10; d++){
			if(len == 1)
				dp[len][d] = 1;
			else{
				for(int i = 1; i <= d; i++){
					dp[len][d] += dp[len-1][i];
				}
			}
		}
	}
	return accumulate(all(dp[n]), 0);
}

int main() 
{ 
    int n = 3; 
    cout << countNonDecreasing(n); 
    return 0; 
} 
