#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getMoneyAmountUtil(int start, int end, map<pair<int, int>, int>& mapping){
        if(start >= end)
            return 0;
        
		if(mapping.find({start, end}) != mapping.end())
			return mapping[{start, end}];

		int result = INT_MAX/2;
		for(int i = start; i <= end; i++)
			result = min(result, i+max(getMoneyAmountUtil(start, i-1, mapping), getMoneyAmountUtil(i+1, end, mapping)));

		mapping[{start, end}] = result;
		return result;
	}
    int getMoneyAmount(int n) {
    	map<pair<int, int>, int> mapping;
    	getMoneyAmountUtil(1, n, mapping);
        return mapping[{1,n}];
    }
};