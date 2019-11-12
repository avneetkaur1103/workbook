// Given a string, print all permutations of it in sorted order
#include <bits/stdc++.h>
using namespace std;

int find_ceil (string& str, int l)
{
    int n = str.length();
    int ceilIndex = l+1;
    for (int i = l+2; i < n; i++)
        if (str[i] > str[l] && str[i] < str[ceilIndex])
            ceilIndex = i;

    return ceilIndex;
}

bool _next_permutation(string& str){
	int n = str.length();
	int i;
	for(i = n-2 ; i >= 0; i--)
		if(str[i] < str[i+1])
			break;
	if(i == -1) // last permutation already
		return false;
	else{
		int j = find_ceil(str, i);
		cout << "Debug: Swap " <<  str[i] << " , " << str[j] << endl;
        swap(str[i], str[j]);
		reverse(&str[i+1], &str[n-1]);
	}
	return true;
}
void all_sorted_permutation(string& str){
	sort(str.begin(), str.end());
	while(_next_permutation(str)){
		cout << str << endl;
	}
}
int main()
{
    string str = "ABCD";
    all_sorted_permutation( str );
    return 0;
}
