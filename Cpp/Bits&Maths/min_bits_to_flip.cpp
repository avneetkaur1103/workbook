// https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/

#include <bits/stdc++.h>
using namespace std;

int count_bits(int n){
	int count = 0;
	while(n){
		n &= n-1;
		++count;
	}
	return count;
}

int min_flip(int a, int b){
	int diff = a ^ b;
	return count_bits(diff);
}

int main(){
	cout << min_flip(10, 20);
}
