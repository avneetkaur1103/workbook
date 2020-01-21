// https://leetcode.com/problems/maximal-rectangle/
class Solution {
public:
    int hist_area(vector<int>& dp){
        stack<int> st;
        int max_area = 0;
        int n = dp.size();
        int i;
        for(i = 0; i < n; i++){
                while(!st.empty() && dp[st.top()] >= dp[i]){
                    int temp = st.top(); st.pop();
                    int base = !st.empty()? st.top() : -1;
                    max_area = max(max_area, dp[temp]*(i-base-1));
                }
                st.push(i);
        }
        while(!st.empty()){
            int temp = st.top(); st.pop();
            int base = !st.empty()? st.top() : -1;
            max_area = max(max_area, dp[temp]*(i-base-1));
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n)
            return 0;
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        int max_area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[j] = matrix[i][j] == '1'? dp[j]+1: 0;
            }
            for(auto v: dp)
                cout << v << " ";
            cout << endl;
            max_area = max(max_area, hist_area(dp));
        }
        return max_area;
    }
};