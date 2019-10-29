#include <bits/stdc++.h>
using namespace std;

int all_primes(int n){
	vector<bool> primes(n+1, true);
	for(int p = 2; p*p <= n; p++){
		if(primes[p])
		for (int i = p*p; i <= n; i += p){
			primes[i] = false;
		}
	}
	for(int i = 2; i <= n; i++){
        if(primes[i])
            cout << i << " ";
	}
	return 0;
}
int main(){
	all_primes(30);
}
