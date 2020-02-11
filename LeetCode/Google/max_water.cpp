// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3048/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int n = height.size();
        int i = 0; j = n-1;
        int area = 0, max_area = 0;
        while(i <= j){
        	area = min(height[i],height[j])*(j-i);
        	max_area = max(area, max_area);
        	if(height[i] < height[j])
        		i++;
        	else
        		j++;
        }
        return max_area;
    }
};