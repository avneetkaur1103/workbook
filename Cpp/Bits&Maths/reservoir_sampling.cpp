/* So we are given a stream of numbers and we need to write an efficient function to randomly select k numbers where 1 <= k <= n. */
#include <bits/stdc++.h>
using namespace std;

vector<int> sample(vector<int>& v, int k){
	int n = v.size();
	vector<int> res(k);
	int i = 0;
	for(; i < k; i++){
		res[i] = v[i];
	}

	srand(time(NULL));
	for(; i < n; i++){
		int j = rand()%(i+1);
		if(j<k)
			res[j] = v[i];
	}
	return res;
}
// Driver Code
int main()
{
    vector<int> stream = {1, 2, 3, 4, 5, 6,
                    7, 8, 9, 10, 11, 12};
    auto res = sample(stream, 5);
    for(auto i: res){
    	cout << i << " ";
    }
    cout << endl;
    return 0;
}
