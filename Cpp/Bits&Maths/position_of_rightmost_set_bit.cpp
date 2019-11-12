//https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
// considering -ve no in 2's complemnets
#include<bits/stdc++.h>
using namespace std;

int right_most(int n){
	return log2(n & -n) + 1;
}

int main(){
	cout << right_most(12);
}