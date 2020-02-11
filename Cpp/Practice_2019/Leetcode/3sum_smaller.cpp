// https://leetcode.com/problems/3sum-smaller/
#define all(c) c.begin(), c.end()
class Solution {
public:
    int get_count(vector<int>& nums, int partition, int target){
        int n = nums.size();
        int i = 0; int j = n-1;
        int count = 0;
        while(i < partition && j > partition){
            if(nums[i]+nums[j] < target){
                count += j - partition;
                i++;
            }
            else if(nums[i]+nums[j] >= target)
                j--;
        }
        return count;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        sort(all(nums));
        for(int i = 1; i < n-1; i++){
            count += get_count(nums, i, target-nums[i]);
        }
        return count;
    }
};