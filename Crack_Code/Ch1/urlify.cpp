// Cracking the coding interview Q - 1.3
#include <bits/stdc++.h>
using namespace std;

string urlify(string& str, int n){
	int n_spaces = count(str.begin(), str.begin()+n, ' ');
	int len = n + 2*n_spaces;
	for(int i = n-1 ; i >= 0; i--){
		if(str[i] != ' ')
			str[--len] = str[i];
		else{
			str[--len] = '0';
			str[--len] = '2';
			str[--len] = '%';
		}
	}
	return str;
}

int main(){
	string s = "Mr John Smith    ";
	s = urlify(s, 13);
	cout << s;
}
