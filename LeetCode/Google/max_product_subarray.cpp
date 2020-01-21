// https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3087/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long result = INT_MIN, forward = 1, backward = 1;
        for(int i = 0; i < n; i++){
            forward = nums[i]? forward*nums[i]: 1;
            backward = nums[n-1-i] ? backward*nums[n-1-i]: 1;
            result = nums[i]? max(result, forward) : result;
            result = nums[n-1-i]? max(result, backward) : result;
            result = max(result, (long long)nums[i]);
        }
    return result;
    }
};