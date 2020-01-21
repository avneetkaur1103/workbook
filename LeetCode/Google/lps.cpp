// https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/451/
class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        string largest = "";

        for(int len = 1 ; len <= n; len++){
        	for(int i = 0 ; i < n-(len-1); i++){
        		int j = i + len - 1;

        		if(len == 1)
        			isPalindrome[i][j] = true;
        		else if(len == 2)
        			isPalindrome[i][j] = s[i] == s[j];
        		else
        			isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);

        		if(largest.size() < len && isPalindrome[i][j])
        			largest = s.substr(i, len);
        	}
        }
        return largest;
    }
};