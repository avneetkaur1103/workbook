// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int pivot(vector<int>& nums, int low, int high){
        if(high < low){
            cout << "Dead End" << endl;
            return -1;
        }
        if(low == high)
            return low;
        else if(low+1 == high){
            if(nums[low] > nums[high])
                return high;
            return -1;
        }
        int mid = low + (high-low)/2;

        if(nums[low] < nums[mid])
            return pivot(nums, mid, high);
        else
            return pivot(nums, low, mid);
    }
    int binary_search(vector<int>& nums, int low, int high, int target){
        if(high < low){
            cout << "BS Dead End" << endl;
            return -1;
        }
        int mid = low + (high-low)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            return binary_search(nums, mid+1, high, target);
        else
            return binary_search(nums, low, mid-1, target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        if(n == 1)
            return nums[0] == target ? 0: -1;
        int pv = pivot(nums, 0, n-1);
        cout << "pivot: " << pv << endl;
        if(pv == -1){
            return binary_search(nums, 0, n-1, target);
        }
        else{
            int index = binary_search(nums, 0, pv-1, target);
            if(index != -1)
                return index;
            return binary_search(nums, pv, n-1, target);
        }
    }
};