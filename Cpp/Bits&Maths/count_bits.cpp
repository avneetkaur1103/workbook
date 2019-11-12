// https://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int next_higher(uint n){
	uint right_most_bit_only = n & -(signed)n;
	uint next_higher_bit_set = n + right_most_bit_only;
	uint right_extreme_bits = ((n^next_higher_bit_set)/right_most_bit_only) >> 2;
	return right_extreme_bits | next_higher_bit_set;
}

int main(){
	cout << next_higher(3);
}