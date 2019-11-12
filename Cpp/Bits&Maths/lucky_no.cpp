/* https://www.geeksforgeeks.org/lucky-numbers/ */

#include <bits/stdc++.h>
using namespace std;

bool is_lucky_number(int n){
	static int counter = 2;
	if(n < counter)
		return true;
	if(n == counter)
		return false;
	n -= n/counter;
	counter++;
	return is_lucky_number(n);
}
int main(){  
    int x = 7;  
    if( is_lucky_number(x) )  
        cout << x << " is a lucky no.";  
    else
        cout << x << " is not a lucky no.";  
}