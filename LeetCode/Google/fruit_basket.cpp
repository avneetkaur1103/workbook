#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
    	int n = tree.size();
    	int type1 = -1, type2 = -1;
    	int max_count = 0, count1 = 0, count2 = 0;
    	for(int i = 0; i < n; i++){
    		if(type1 == -1 || tree[i] == tree[type1]){
    			type1 = i; count1++;
    		}
    		else if(type2 == -1 || tree[type2] == tree[i]){
    			type2 = i; count2++;
    		}
    		else{
    			int _min = min(type1, type2);
    			int _max = max(type1, type2);
    			type1 = _max; count1 = i-(_min+1);
    			type2 = i;
    			count2= 1;
    		}
    		max_count = max(count1+count2, max_count);
    	}
        return max_count;
    }
};
int main(){
    Solution sol;
    vector<int> v = {6,2,1,1,3,6,6};
    cout << "Ans:" << sol.totalFruit(v);
}
