//https://leetcode.com/explore/interview/card/google/59/array-and-strings/3053/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        int last_pos = n-1;
        for(int i = n-2 ; i>= 0; i--){
            if(i+nums[i] >= last_pos ){
                last_pos = i;
            }
        }
        return last_pos == 0;
        
    }
};