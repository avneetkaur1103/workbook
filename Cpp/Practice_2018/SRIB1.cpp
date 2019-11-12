#include<bits/stdc++.h>
#include<iostream>
#define P 1000000007
using namespace std;
int solve(std::vector<int>& v){
	int n = v.size();
	unordered_map<int, vector<pair<int,pair<int,int>>>> umap;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			if(i == j){
				umap[i].push_back({i,{v[i],v[i]}});
			}
		}
	}
	long long totalSum = 0 ;
	for(int l = 2 ; l <= n ; l++){

		int sum = 0 ;
		for(int i = 0 ; i < n-l+1 ; i++){
                for(auto& umapi: umap[i])
                {
                    for(int j = umapi.first + 1; j < n ; j ++){
                        int min = umapi.second.first;
                        int max = umapi.second.second;
                        if(v[j] > max)
                            max = v[j];
                        else if(v[j] < min){
                            min = v[j];
                        }
                        umapi.first = j;
                        umapi.second.first = min;
                        umapi.second.second = max;
                        sum = (sum+ (min | max)) % P;
                        cout << " L - i - j " << l << " - " << i << " - "  << j << " SUM " << sum << endl;
                    }
				}
		}
		totalSum = (totalSum + sum) % P;
	}
	return totalSum;
}

int main(){
	int n;
	cin >> n;
	std::vector<int> v(n,0);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	cout << solve(v) <<endl;
}
