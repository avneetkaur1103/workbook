/* Let us consider the following problem to understand Segment Trees.
We have an array arr[0 . . . n-1]. We should be able to
1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1
2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int fill_segment_tree(vector<int>& v, int ss, int se, vector<int>& st, int pos ){
	if(ss == se){
		st[pos] = v[ss];
		return st[pos];
	}
	int mid = (se+ss)/2;
	int sum = fill_segment_tree(v, ss, mid, st, 2*pos+1) + fill_segment_tree(v, mid+1, se, st, 2*pos+2);
	return st[pos] = sum;
}

vector<int> make_segment_tree(vector<int>& v){
	int n = v.size();
	int m = ceil(log2(n));
	m = 2*pow(2, m) - 1;
	cout << "Debug: sg_size " << n << endl;
	vector<int> st(m);
	fill_segment_tree(v, 0, n-1, st, 0);
	return st;
}

int _query(vector<int> st, int qs, int qe, int start, int end, int pos){
	if(qs <= start && qe >= end)
		return st[pos];
	if(qs > end || qe < start)
		return 0;

	int mid = start + (end-start)/2;
	return _query(st, qs, qe, start, mid, 2*pos+1) + _query(st, qs, qe, mid+1, end, 2*pos+2);
}

int query(vector<int>& st, int n, int qs, int qe){
	return _query(st, qs, qe, 0, n-1, 0);
}

/*
int main(){
	vector<int> v = {1, 3, 5, 7, 9, 11};
	vector<int> st = make_segment_tree(v);
	int n = v.size();
	int qs = 1, qe = 3;
	for(auto x: v){
        cout << x << " ";
	}
	cout << endl;
	for(auto x: st){
        cout << x << " ";
	}
	cout << "Sum for range: " << qs << ", " << qe << " : " << query(st, n, 1, 3);
}
*/
