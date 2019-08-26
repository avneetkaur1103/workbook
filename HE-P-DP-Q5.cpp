#include<bits/stdc++.h>
using namespace std;

long int largestPrime(long int n){
	std::vector<bool> primes(n+1,true);

	for(long int p = 2 ; p*p <= n ; p++){
		if(primes[p])
			for(long int i = 2*p ; i <= n ; i+=p){
				primes[i] =false;
			}
	}
	for(long int i = n ; i >=2 ; i-- ){
		if(primes[i]) return i;
	}
	return -1;
}

long int solve(std::vector<int>& points){
	int n = largestPrime(points.size());
	//cout << "Prime " << n <<endl;
	long int maxSum = 0;
	if(n != -1){
		long int sum = 0;
		for(int i = 0 ; i < n ; i++){
			sum += points[i];
		}
		maxSum = sum;
		for(int i = n ; i < points.size() - n + 1 ; i++){

			sum = (sum - points[n-i] )+ points[n];
			maxSum  = max(maxSum,sum);
		}
	}
	return maxSum;
}

int main(){
	int n;
	cin >> n;
	std::vector<int> points(n);
	for(int i  = 0 ; i < n ; i++){
		cin >> points[i];
	}
	cout << solve(points) << endl;
}
