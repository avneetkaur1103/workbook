// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;

bool is_from_bst(vector<int>& pre){
	int root = INT_MIN;
	stack<int> st;
	int n = pre.size();
	for(int i = 0; i < n; i++){
		if(pre[i] < root)
			return false;
		if(!st.empty() && st.top() < pre[i]){
			root = st.top(); st.pop();
		}
		st.push(pre[i]);
	}
	return true;
}

int main(){
	vector<int> pre1 = {40, 30, 35, 80, 100};
	cout << "Ans: " << is_from_bst(pre1) << endl;
	vector<int> pre2 = {40, 30, 35, 20, 80, 100};
	cout << "Ans: " << is_from_bst(pre2) << endl;
}
