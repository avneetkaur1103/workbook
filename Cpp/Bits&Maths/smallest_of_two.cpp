// https://www.geeksforgeeks.org/compute-the-minimum-or-maximum-max-of-two-integers-without-branching/
#include <bits/stdc++.h>
using namespace std;

int _min(int a, int b){
	 return a ^ ((b ^ a) & -(a > b)); 	//= > -1 = 1111111 = all ones 
}
int main(){
	cout << _min(-6,5);
}