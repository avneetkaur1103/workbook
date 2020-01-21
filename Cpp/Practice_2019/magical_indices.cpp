// https://www.geeksforgeeks.org/magical-indices-array/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& A){
	int n = A.size();
	vector<int> parent(n, -1);
	int count = 0;

	for(int i = 0; i < n; i++){
		if(parent[i] == -1){
			int j = i;
			while(parent[j] == -1){
				parent[j] = i;
				j = (i + A[i] + 1) % n;
			}
			if(parent[j] == i){
				vector<bool> cvisited(n, false);
				while(!cvisited[j]){
					cvisited[j] = true;
					count++;
					j = (i + A[i] + 1) % n;
				}
			}
		}
	}
	return count;
}

int main()
{
    vector<int> A = { 0, 0, 0, 2 };
    cout << solve(A);
    return 0;
}
