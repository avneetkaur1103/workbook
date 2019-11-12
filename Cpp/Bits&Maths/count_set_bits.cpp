// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
#include <iostream>
using namespace std;

int count_set_bits(int n){
	int count = 0;
	while(n){
		n &= n-1;
		++count;
	}
	return count;
}

int main(){
	int i = 11; 
    cout << count_set_bits(i);
}