// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3055/
class Solution {
public:
    string range(long i, long j){
        string result = "";
        if(j-i == 2) 
            result = to_string(i+1);
        if(j-i > 2)
            result = to_string(i+1) + "->" + to_string(j-1);
        return result;
    }
    
    vector<string> findMissingRanges(vector<int>& nums, long lower, long upper) {
        int n = nums.size();
        vector<string> result;
        int i = 0;
        lower -= 1; upper += 1;
        if(!n){
            string s = range(lower, upper);
            result.push_back(s);
            return result;
        }
        for(i = 0; i < n; i++){
            if(nums[i] > upper)
                break;
            if(nums[i] > lower && nums[i] < upper){
                string s = range(lower, nums[i]);
                if(s.size())
                    result.push_back(s);
                lower = nums[i];
            }
        }
        if(nums[n-1] < upper){
            string s = range(nums[n-1], upper);
            if(s.size())
                result.push_back(s);
        }
        return result;  
    }
};