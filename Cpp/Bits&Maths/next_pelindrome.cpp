/* Given a number, find the next smallest palindrome larger than this number. For example, if the input number is “2 3 5 4 5”,
the output should be “2 3 6 3 2”. And if the input number is “9 9 9”, the output should be “1 0 0 1”.*/

/*
case 1: => right > rev(left) +1, propagate & reflect
case 2: => right < rev(left) reflect
case 3: => all 9's
*/

#include <bits/stdc++.h>
using namespace std;

int next_palindrome(vector<int>& v){
	int n = v.size();
	int mid = n/2;
	int endleft = mid-1;
	int j = n&1 ? mid + 1: mid;
	int startright = j;
	int i = endleft;

	while(i >= 0 && v[i] == v[j])
		i--; j++;

	if(i < 0 || v[i] > v[j]){
		while(i >= 0){
			v[j] = v[i];
			i--; j++;
		}
	}
	else{ //left greater
        int carry = 0;
		int mid = n&1? n/2: n/2-1;
		if(n & 1){ // ood has a mid elemet to handle even has no mid to handle explicitly
			v[mid] += 1;
			if(v[mid]/10){
            	v[mid] %= 10;
            	carry = 1;
			}
		}

		int i = endleft;
		int j = startright;
		while(i>=0){
            cout << "Debug: " << i << " , " << j;
		    v[i] += carry;
            if(v[i] == 10){
                v[i] -= 10;
                carry = 1;
            }
            else
                carry = 0;
			v[j] = v[i];
			i--; j++;
		}
	}
}
int main()
{
    vector<int> v = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}; // op => 9 4 1 8 8 0 8 8 1 4 9
    next_palindrome(v);
    for(auto i: v)
        cout << i << " ";

    return 0;
}
