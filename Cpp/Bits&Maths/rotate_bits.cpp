// https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
#include <bits/stdc++.h>
using namespace std;
#define NUM_BITS 32

unsigned int rotate_left(unsigned int n, int d){
	return ((n << d) | n >> (NUM_BITS - d));
}

unsigned int rotate_right(unsigned int n, int d){
	return ((n >> d) | n << (NUM_BITS - d));
}

int main(){
    cout << rotate_left(17, 1) << endl;
    cout << rotate_right(17, 1) << endl; // will o/p -ve if signed int
}