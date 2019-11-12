// https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> elements(vector<int>& v){
	int _xor = 0, x =0, y = 0;
	for(auto i: v){
		_xor ^= i;
	}
	//split it into 2 by right_most set bit
	_xor = (_xor & -_xor);	 // => returns rightmost set bit by property of -ve being in 2's complement form

	for(auto i: v){
		if(i & _xor)
			x ^= i;
		else
			y ^= i;
	}
	return {x,y};
}

int main(){
	vector<int> v = {2, 3, 7, 9, 11, 2, 3, 11};
	auto result = elements(v);
	cout << result.first << " " << result.second;
}
