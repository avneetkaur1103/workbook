// https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
#include <bits/stdc++.h>
using namespace std;
#define NUM_BITS 32

void reverse_bits(unsigned int& n){
    int result = 0;
	for(int i = 0; i < NUM_BITS; i++){
		if(n&1)
			result |= 1;
        if (i != NUM_BITS-1){
            n >>= 1;
            result <<= 1;
        }
		// cout << bitset<32>(n)<< "\t";
		// cout << bitset<32>(result)<< endl;
	}
	n = result;
}
int main(){
	unsigned int x = 2147483648;
    reverse_bits(x);
    cout << x;
}
