#include<bits/stdc++.h>
using namespace std;

int maxProfit(std::vector<int>& stocks){
    int n = stocks.size();
	std::vector<int> diff(n);
	for(int i = 0 ; i < n-1 ; i++){
		diff[i] = stocks[i+1] - stocks[i];
	}
	int totalProfit = 0, profit1 = 0, profit2 = 0;
	for(int i = 2 ; i < n ; i++){
	    profit1 = 0 ; profit2 = 0;
		for(int j = 0 ; j < i ; j++){
			if(diff[j] > 0)
				profit1 +=diff[j];
		}

		for(int j = i ; j < n-1 ; j++){
			if(diff[j] > 0)
				profit2 +=diff[j];
		}
		if(totalProfit < profit1 + profit2)
			totalProfit = profit1 + profit2;
	}
	return totalProfit > 0 ? totalProfit : 0;
}
// Drive program
int main()
{
    vector<int> price = {2, 30, 15, 10, 8, 25, 80};
    cout << "Maximum Profit = " << maxProfit(price);
    return 0;
}
