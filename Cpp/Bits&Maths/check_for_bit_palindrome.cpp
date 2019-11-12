// https://www.geeksforgeeks.org/check-binary-representation-number-palindrome/

#include <bits/stdc++.h>
using namespace std;
#define NUM_BITS 32

bool is_palindrome(unsigned int n){
	int right = 1 << NUM_BITS-1;
	int left = 1;

	for(int i = 0; i < NUM_BITS/2; i++){
		cout << "n = " << bitset<64>(n) << endl;
		cout << "left = " << bitset<64>(left) << endl;
		cout << "right = " << bitset<64>(right) << endl;
		cout << "n&left = " << bitset<64>(left&n) << endl;
		cout << "n&right = " << bitset<64>(n&right) << endl;

		if(n&right != n&left){
			return false;
		}
		//right >>= 1;
		right = 1 << NUM_BITS-i-2;
		left <<= 1;
	}
	return true;
}

int main(){
	unsigned int x = 1 << 15 + 1 << 16;
    cout << "n = " << x << " " << is_palindrome(x) << endl;
    x = 2 ;
    cout << is_palindrome(x) << endl;
}
