// https://leetcode.com/explore/interview/card/google/59/array-and-strings/361/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0; int n = nums.size();
        for(;i < n && i < k; i++){
        	pq.push(nums[i]);
        }
        for(;i < n; i++){
        	if(nums[i] > pq.top()){
        		pq.pop();
        		pq.push(nums[i]);
        	}
        }
        return pq.top();
    }
};