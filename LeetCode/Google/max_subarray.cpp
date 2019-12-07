class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max_sum = INT_MIN;
        int local_sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            local_sum += nums[i];
            global_max_sum = max(global_max_sum, max(local_sum, nums[i]));
            
            if(local_sum < 0) 
                local_sum = 0;
        }
        return global_max_sum;
        
    }
};