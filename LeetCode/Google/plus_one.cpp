//https://leetcode.com/explore/interview/card/google/59/array-and-strings/339/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result;
        result.reserve(n+1);
        int carry = 1;
        transform(digits.rbegin(), digits.rend(), back_inserter(result), [& carry](auto i){ int temp = (i+carry)%10; carry = (i+carry)/10; return temp; });
        if(carry)
            result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;

    }
};
