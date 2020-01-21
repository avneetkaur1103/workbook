// https://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
#include <bits/stdc++.h>
using namespace std;

bool isSameBSTUtil(vector<int>& a, vector<int>& b, int _min, int _max, int ia, int ib, int na, int nb){
	int i, j;
	for(i = ia; i < na; i++){
		if(a[i] > _min && a[i] < _max)
			break;
	}
	for(j = ib; j < nb; j++){
		if(b[j] > _min && b[j] < _max)
			break;
	}

	if(i == na && j == nb)
		return true;
	if(((i == na) ^ (j == nb)) || a[i] != b[j])
		return false;
	return isSameBSTUtil(a, b, _min, a[i], i+1, j+1, na, nb) && isSameBSTUtil(a, b, a[i], _max, i+1, j+1, na, nb);
}

bool isSameBST(vector<int>& a, vector<int>& b){
	int na = a.size();
	int nb = b.size();
	return isSameBSTUtil(a, b, INT_MIN, INT_MAX, 0, 0, na, nb);
}

int main()
{
    vector<int> a = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    vector<int> b = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    if(isSameBST(a, b))
    {
        cout << "BSTs are same";
    }
    else
    {
        cout << "BSTs not same";
    }
    return 0;
}
