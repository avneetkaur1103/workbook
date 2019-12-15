// https://leetcode.com/explore/featured/card/google/63/sorting-and-searching-4/3081/
class Solution {
public:
    int binary_search(vector<int>& nums, int& low, int& high, int no){
        if(low > high)
            return -1;
         int mid = low + (high-low)/2;
        if(nums[mid] == no)
            return mid;
        if(nums[mid] < no)
            return binary_search(nums, ++mid, high, no);
        else
            return binary_search(nums, low, --mid, no);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int start = -1, end = -1;
        int result = -1;
        while((result = binary_search(nums, low, high, target)) != -1){
            //cout << "start: " << low << ":" << high << endl;
            start = result;
            high = start-1;
        }
        
        low = 0; high = n-1; 
        while((result = binary_search(nums, low, high, target)) != -1){
            //cout << "end: " << low << ":" << high << endl;
            end = result;
            low = end+1;
        }
        return {start, end};
    }
};