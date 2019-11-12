// geeksforgeeks.org/swap-all-odd-and-even-bits/
#include <bits/stdc++.h>
using namespace std;

int swap_odd_evens(int n){
	int evens_mask = 0xAAAAAAAA;
	int odds_mask  = 0x55555555;
	return ((n & evens_mask) >> 1 | (n & odds_mask) << 1); 	//A = 1010 safe to right shift
}

int main(){
	cout << swap_odd_evens(23);
}