// Cracking the coding interview Q - 1.2
#include <bits/stdc++.h>
using namespace std;

int is_permutation(string& str1, string& str2){
	int char_counts[26] = {0};
	for(auto s: str1)
		char_counts[s - 'A'] += 1;
	for(auto s: str2)
		char_counts[s - 'A'] -= 1;

	for(int i = 0; i < 26; i++)
		if(char_counts[i])
			return false;

	return true;
}

int main(){
	string s1 = "ABBBACD";
	string s2 = "BACDABB";
	cout << (is_permutation(s1, s2) ? "YES" : "NO");
}
