#include<bits/stdc++.h>
using namespace std;
string str = "ababbbabbababa";
void printPartition(std::vector<std::vector<pair<int,int>>>& data, int low , int high){

    if(high > low && !(data[low][high].second == high)){
        cout << str.substr(low,data[low][high].second+1-low)<< " ";
        printPartition(data,low,data[low][high].second);
        //cout << data[low][high].second << endl;
        printPartition(data, (int)data[low][high].second+1, high);
    }
}
int minPelindromePartition(string& str){
	int n =  str.length();
	std::vector<std::vector<pair<int,int>>> sol(n,std::vector<pair<int,int>>(n));
	std::vector<vector<bool>> isPalindrome(n,std::vector<bool>(n,false));

	for(int i = 0 ; i < n ; i++){
		isPalindrome[i][i] = true;
	}

	for(int l = 2 ; l <= n ; l++){
		for(int i = 0 ; i < n-l+1; i++){
			int j = i + l - 1;
			if(l == 2){
			 isPalindrome[i][j] = (str[i] == str[j]);
			 sol[i][j] = {0,j};
			}
			else if(str[i] == str[j] && isPalindrome[i+1][j-1]){
				isPalindrome[i][j] = true;
				sol[i][j] = {0,j};
			}
			if(!isPalindrome[i][j]){
				sol[i][j].first = numeric_limits<int>::max();
				for(int k = i ; k < j ; k++){
					if(sol[i][j].first > 1+((int)sol[i][k].first)+((int)sol[k+1][j].first))
						sol[i][j] = {1+((int)sol[i][k].first)+((int)sol[k+1][j].first) , k};
				}
			}
		}
	}
	printPartition(sol,0,n-1);
//	for(auto soli : sol){
//        for(auto i : soli){
//            cout << "{" << i.first <<","<< i.second <<"}";
//        }
//        cout << endl;
//	}
	return sol[0][n-1].first;
}
int main(){
	cout << "minPelindromePartition " << minPelindromePartition(str);
}
