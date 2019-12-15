// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/851/
#define all(c) c.begin(), c.end()
class Solution {
    void merge(int low, int mid, int high, vector<int>& nums,vector<int>& index, vector<int>& result){
        int count_left = 0, count_right = 0;
        int left = low, right = mid+1;
        vector<int> temp;
        
        while(left <= mid && right <= high){
            if(nums[index[left]] <= nums[index[right]]){
                //temp.push_back(nums[index[left]]);
                temp.push_back(index[left]);
                result[index[left]] += count_right;
                left++;
            }
            else if(nums[index[left]] > nums[index[right]]){
                //temp.push_back(nums[index[right++]]);
                temp.push_back(index[right++]);
                count_right++;
            }
        }
        while(left <= mid){
            temp.push_back(index[left]);
            result[index[left]] += count_right;
            left++;
        }
        while(right <= high){
            temp.push_back(index[right++]);
        }
        copy(all(temp), index.begin()+low);
    }
    void merge_sort(vector<int>& nums, int low, int high, vector<int>& index, vector<int>& result){
        if(low < high){
            int mid = low + (high-low)/2;
            merge_sort(nums, low, mid, index, result);
            merge_sort(nums, mid+1, high, index, result);
            merge(low, mid, high, nums, index, result);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(!n) return vector<int>();
        
        vector<int> result(n,0);
        vector<int> index(n);
        iota(all(index), 0);
        merge_sort(nums, 0, n-1, index, result);
        return result;        
    }
};