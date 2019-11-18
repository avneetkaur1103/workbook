// Cracking the coding interview Q - 5.4
#include <bits/stdc++.h>
using namespace std;

unsigned int next_greater_no(unsigned int n){
	int start = -1;
	for(int i = 0 ; i < 32; i++){
		if(n & (1 << i)){
			start = i;
			break;
		}
	}
	if(start == -1){
		cout << "No bit set" << endl;
		return -1;
	}
	unsigned int temp = (n ^ (n + (1<<start))); //move 1 to a postion which would be set for next higer bit and all 0s
	cout << "Debug Start: " << start << endl;
	return (n + (1<<start))|((temp - 1) >> (start+2));
}
int main(){
	unsigned int x = 12;
	unsigned int result = next_greater_no(x);
	cout << bitset<32>(result) << endl;
}
