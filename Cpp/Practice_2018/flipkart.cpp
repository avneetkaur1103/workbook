#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;

void solve(std::vector<int> input, int n,int D){
	std::vector<pair<int,int>> dataSet;
	for(int i  = 0 ; i < input.size(); i++){
		dataSet.push_back({input[i],i});
	}
	sort(all(dataSet));
	sort(dataSet.begin(), dataSet.begin()+n,[](auto i , auto j){ if(i.second < j.second) return true; return false;});
	for(int i = 0 ; i < n ; i++){
		cout << input[dataSet[i].second] << " ";
	}
	cout <<endl;

}

int main(){
	int N,M,D;
	cin >> N >> M >> D;
	std::vector<int> input(M,0);
	for(int i = 0 ; i < M ; i++){
		cin >> input[i];
	}
	solve(input,N,D);
}
