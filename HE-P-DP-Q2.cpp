#include<bits/stdc++.h>
#include<iostream>
using namespace std;
float pWin(int R, int G){
	float total = R+G;
	if(R <= 0){
        return 1;
	}
    else{
		float pTotal = R/total;
		if(G >= 2){
            pTotal += (G/total)*((G-1)/(total-1))*pWin(R,G-2);
		}
		//cout << "PTotal " << pTotal << endl;
		return pTotal;
	}
	return 0;
}

float solve(int R, int G){
	return pWin(R,G);
}

int main(){
	int n_tc;
	cin >> n_tc;
	std::cout << std::fixed;
    std::cout << std::setprecision(6);
	while(n_tc--){
		int R, G;
		cin >> R >> G;
		cout << solve(R,G) << endl;
	}
}
