#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;

int min_swaps(vector<int>& inorder){
    int n = inorder.size();
	vector<int> visited(n, false);
	vector<pair<int, int>> temp(n);
	for(int i = 0; i < n ; i++){
		temp[i] = {inorder[i], i};
	}
	sort(all(temp));
	int swap_count = 0;
	for(int i = 0 ; i < n; i++){
		if(i == temp[i].second)
			continue;
		int j = i;
		int count = 0;
		while(!visited[j]){
			visited[j] = true;
			j = temp[j].second;
			count++;
		}
		if(count > 0)
            swap_count += count-1;
	}
	return swap_count;
}

int main(){
	vector<int> inorder = {1, 5, 4, 3, 2};
	cout << min_swaps(inorder);
}
