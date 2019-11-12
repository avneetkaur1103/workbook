// Fisher–Yates shuffle Algorithm
#include <bits/stdc++.h>
using namespace std;

void _shuffle(vector<int>& v){
	int n = v.size();
    srand(time(NULL)); // NULL = 0 current time
	for(int i = n-1; i >= 0; i--){
		int j = rand()%(i+1);
		swap(v[i], v[j]);
	}
}
// Driver Code
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    _shuffle(v);
    for(auto i: v){
    	cout << i << " ";
    }
    cout<<endl;
    return 0;
}
