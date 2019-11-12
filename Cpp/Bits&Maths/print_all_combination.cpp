#include <bits/stdc++.h>
using namespace std;

void combinations_util(vector<int>&v, vector<int>& data, int index, int k){
	if(v.size() == k){
		for(auto i: v){
			cout << i << " ";
		}
		cout<<endl;
		return;
	}

    if(index >= data.size()){
		return;
	}
	v.push_back(data[index]);
	combinations_util(v, data, index+1, k);
	v.pop_back();
	combinations_util(v, data, index+1, k);

}

void combinations(vector<int>& data, int k){
	int n = data.size();
	for(int i = 0; i < n-k+1; i++){
        vector<int> v;
		combinations_util(v, data, i, k);
	}

}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    combinations(v, 3);
}
