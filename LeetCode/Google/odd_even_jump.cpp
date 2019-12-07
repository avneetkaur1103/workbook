#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;

class Solution {
	vector<int> next_greater_no(vector<int> index){
		int n = index.size();
		stack<int> st;
		vector<int> result(n, -1);
		for(auto i:index){
			while(!st.empty() && i >= st.top()){
				int j = st.top();
				result[j] = i;
				st.pop();
			}
			st.push(i);
		}
		return result;
	}
	void print(vector<int> v){
		for(auto i: v)
			cout << i << " ";
		cout << endl;
	}
    public:
        int oddEvenJumps(vector<int>& A) {
            int n = A.size();
            vector<int> index(n);
            iota(index.begin(), index.end(), 0);
            sort(index.begin(), index.end(), [&A](auto i, auto j){ return A[i] < A[j];});
            vector<int> next_odd = next_greater_no(index);
            //print(index);
            
            index.clear();
            index.resize(n);
            iota(index.begin(), index.end(), 0);
            sort(index.begin(), index.end(), [&A](auto i, auto j){ return A[i] > A[j];});
            vector<int> next_even = next_greater_no(index);
            //print(index);

            vector<bool> dp_odd(n, false), dp_even(n, false);
            dp_odd[n-1] = dp_even[n-1] = true;

            for(int i = n-2; i>=0; i--){
                if(next_odd[i] != -1)
                    dp_odd[i] = dp_even[next_odd[i]];
                if(next_even[i] != -1)
                    dp_even[i] = dp_odd[next_even[i]];
            }
            return count(all(dp_odd), true);
        }
};

int main(){
    Solution sol;
    vector<int> v = {2,3,1,1,4};
    cout << "Ans:" << sol.oddEvenJumps(v);
};
