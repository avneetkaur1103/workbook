// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// int hist[] = {6, 2, 5, 4, 5, 1, 6};
#include <bits/stdc++.h>
using namespace std;
int largest(vector<int>& hist){
	stack<int> st;
	int max_area = 0;
    int n = hist.size(); int i = 0;
	while(i < n){
		if(st.empty() || hist[st.top()] <= hist[i])
			st.push(i++);
		else{
			int top = st.top();
			st.pop();
			int j = st.empty() ? -1 :st.top();
			int area = hist[top] * (i-j-1);
			max_area = max(area, max_area);
		}
	}
	while(!st.empty()){
		int top = st.top();
		st.pop();
		int j = st.empty() ? -1 :st.top();
		int area = hist[top] * (i-j-1);
		max_area = max(area, max_area);
	}
	return max_area;
}
int main(){
	vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
	cout << "Max Area: " << largest(hist);
}
