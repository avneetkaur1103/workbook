// Cracking the coding interview Q-1.1

#include <bits/stdc++.h>
using namespace std;

int has_uniques(string& str){
	unordered_map<char, int> char_count;
	for(auto s: str)
		char_count[s] += 1;
	for(auto p: char_count)
		if (p.second > 1)
			return false;

	return true;
}

int main(){
	string s = "ABCDE";
	cout << has_uniques(s);
}
