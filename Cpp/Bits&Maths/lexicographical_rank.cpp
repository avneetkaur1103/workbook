/* Given a string, find its rank among all its permutations sorted lexicographically.
 For example, rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6. */
#include <bits/stdc++.h>
using namespace std;

int fact(int n){
	return n <= 1 ? 1 : n * fact(n-1);
}

int getrank(string& str){
	int n = str.length();
	int mul = fact(n);
	int rank = 1;

	for(int i = 0; i < n ; i++){
		mul /= (n-i);
		int cnt = count_if(str.begin() + (i+1), str.end(), [&str, &i](auto& x){ return x < str[i];});
		cout << "Debug: cnt " << cnt << endl;
		rank += mul * cnt;
	}
	return rank;
}
int main(){
	string s = "string";
	cout << getrank(s);
}
