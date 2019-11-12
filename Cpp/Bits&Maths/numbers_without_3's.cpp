/* count numbers that dont contain 3
https://www.geeksforgeeks.org/count-numbers-that-dont-contain-3/
'msd' --> the most significant digit in n 
'd'   --> number of digits in n.
count(n) = n if n < 3
count(n) = n - 1 if 3 <= n  10 and msd is not 3
count(n) = count( msd * (10^(d-1)) - 1) 
           if n > 10 and msd is 3
*/
#include <bits/stdc++.h>
using namespace std;

int count(int n){
	if(n < 3)
		return n;
	if(n>=3 && n < 10)
		return n-1;

	int d = log10(n);
	int temp = pow(10, d);
	int msd = n / temp;

	if(msd == 3)
		return count(msd*temp - 1);
	else
		return count(msd)*count(temp-1) + count(msd) + count(n%temp);

}

int main(){
	cout << count(578);
}