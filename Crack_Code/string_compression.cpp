// Cracking the coding interview Q - 1.6
//Assumption sorted input
#include <bits/stdc++.h>
using namespace std;

string compress(string& str){
	int char_counts[26] = {0};
	int char_counts_caps[26] = {0};

	string result;
	char last_char = NULL;
	int count = 0;
	int n = str.size();
	for(int i = 0; i < n; i++){
        char s = str[i];
		if(!last_char){
			last_char = s;
			count = 1;
		}
		else if(last_char == s)
			count += 1;
		else{
			result += last_char;
			result += '0' + count;
			last_char = s;
			count = 1;
		}
		if(i == n-1){
            result += last_char;
			result += '0' + count;
		}
	}
	return (result.length() < str.length() ? result : str);
}
int main(){
	string str = "aabcccccaaa";
	sort(str.begin(), str.end());
	cout << "String: " << str << endl;
	cout << compress(str);
}
