#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution {
public:
    int last_non_inversion(vector<int>& v){
        int pos = -1 ; int n = v.size();
        for(int i = n-1 ; i > 0; i--){
            if(v[i] > v[i-1]){
                pos = i;
                break;
            }
        }
        return pos;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos;
        if((pos = last_non_inversion(nums)) != -1){
            sort(nums.begin()+pos, nums.end());
            auto next_bigger = upper_bound(nums.begin()+pos, nums.end(), nums[pos-1]);
            swap(*next_bigger, nums[pos-1]);
        }
        else
            sort(all(nums));
    }
};