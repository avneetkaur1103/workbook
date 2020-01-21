// https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

int findoptimal(int n){
	if(n < 7)
		return n;
	vector<int> dp(n+1);
	iota(all(dp), 0);

	int last = 0;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1]+1 ; // Single A
		if(dp[i-1]+last > dp[i])
			dp[i] = dp[i-1] + last;
		if(dp[i-3]*2 >= dp[i]){
			dp[i] = 2*dp[i-3];
			last = dp[i-3];
		}
	}
	return dp[n];
}

int main()
{
    int N;
    for (N = 1; N <= 20; N++)
        printf("Maximum Number of A's with %d keystrokes is %d\n",
               N, findoptimal(N));
}
