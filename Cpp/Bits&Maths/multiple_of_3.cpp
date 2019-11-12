/*  If difference between count of odd set bits (Bits set at odd positions) and even set bits is multiple of 3 then is the number. */
#include <bits/stdc++.h>
using namespace std;

int is_divisible_by_3(int n){
	n = abs(n);
	if(!n)
		return true;
	if(n == 1)
		return false;

	int odd = 0, even = 0;
	while(n){
		if(n & 1)
			odd++;
		if(n & 2)
			even++;
		n = n >> 2;
	}
	return is_divisible_by_3(abs(even-odd));
}
int main(){
	cout << is_divisible_by_3(3);
}