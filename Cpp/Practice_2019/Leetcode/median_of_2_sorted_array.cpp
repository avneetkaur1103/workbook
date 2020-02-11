// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double median(vector<int>& nums){
        double result = 0;
        int n = nums.size();
        if(n){
            if(n&1)
                result = nums[n/2];
            else
                result = (nums[n/2-1]+nums[n/2])/2.0;
        }
        return result;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();

 /*     if(n>m){
            swap(nums1, nums2);
            n = nums1.size(); m = nums2.size();
        }
        if(!n || !m){
            if(n)
                return median(nums1);
            if(m)
                return median(nums2);
        }
*/        
        int total = (n+m+1)/2;
        int low = -1, high = n-1;
        while(low <= high){
            int ni = (low+high)/2;
            int mi = total - (ni+1) - 1;
            //cout << "ni: " << ni << " mi: " << mi << endl;
            int leftmaxx = ni >= 0 ? nums1[ni]: INT_MIN;
            int rightminx = ni < n-1 ? nums1[ni+1]: INT_MAX;
            
            int leftmaxy = mi >= 0 ? nums2[mi]: INT_MIN;
            int rightminy = mi < m-1 ? nums2[mi+1]: INT_MAX;
            
            if(leftmaxx <= rightminy && leftmaxy <= rightminx){
                if((n+m)&1)
                    return max(leftmaxx, leftmaxy);
                    
                else
                    return (max(leftmaxx, leftmaxy)+ min(rightminx, rightminy))/2.0;
            }
            else if(leftmaxx > rightminy)
                high = ni+1; 
            else
                low = ni-1;
                           
        }
        return 0;
    }
};