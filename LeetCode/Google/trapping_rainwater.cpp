// https://leetcode.com/explore/featured/card/google/59/array-and-strings/341/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)
            return 0;
        
        vector<int> max_right(n, 0);
        vector<int> max_left(n, 0);
        int max_r = 0; 
        for(int i = n-1; i >= 0; --i){
            max_right[i] = max_r;
            max_r = max(max_r, height[i]);
        }
        int max_l = 0;
        for(int i = 0; i < n-1; ++i){
            max_left[i] = max_l;
            max_l = max(max_l, height[i]);
        }
        
        int volume = 0;
        for(int i = 1; i < n-1; i++){
            int h = (min(max_left[i], max_right[i]) - height[i]) > 0 ? (min(max_left[i], max_right[i]) - height[i]): 0;
            volume += h;
        }
        return volume;
    }
};