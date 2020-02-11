// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3047/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> counter;
        int start = -1, end = -1;
        int max_size = 0, size = 0;
        for(int i = 0; i < n; i++){
        	if(start == -1){
        		start = end = 0;
        		counter[s[i]] += 1;
        		size = max_size = 1;
        	}
        	else if(counter.find(s[i]) == counter.end() || !counter[s[i]]){
        		counter[s[i]] += 1;
        		end = i; size++;
        	}
        	else{
        		while(start <= end && counter[s[i]]){
        			counter[s[start]] --;
        			start++;
        			size--;
        		}
        		counter[s[i]] += 1;
        		end = i; size++;
        	}
        	max_size = max(size, max_size);
        }
        return max_size;
    }
};
