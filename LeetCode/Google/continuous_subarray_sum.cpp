// https://leetcode.com/explore/interview/card/facebook/55/dynamic-programming-3/3038/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sums;
        sums[0] = -1; int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(k != 0)
                sum %= k;
            if(sums.find(sum) != sums.end()){
                if(i-sums[sum] > 1){
                    return true;
                }
            }
            else{
                sums[sum] = i;
            }
        }
        return false;
    }
};