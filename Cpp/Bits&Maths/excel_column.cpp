#include <bits/stdc++.h>
using namespace std;

string get_name(int n){
	string str;
	while(n){
        int r = n % 26;
		n = r? n/26: (n/26 - 1);
		str += r?'A'+r-1:'Z';
	}
	reverse(str.begin(), str.end());
	return str;
}
int main(){
	cout << get_name(26) << endl;
	cout << get_name(51) << endl;
	cout << get_name(52) << endl;
	cout << get_name(80) << endl;
}
