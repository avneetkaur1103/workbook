// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int r = 0;
        int next = 0, prev = 0;
        while(r < n/2){
            for(int c = r; c < n-r-1; c++){
                next = matrix[r][c];
                for(int i = 0; i < 4; i++){
                    prev = next;
                    next = matrix[c][n-r-1];
                    matrix[c][n-r-1] = prev;
                    int tc = n-r-1;
                    int tr = c;
                    c = tc; r = tr;
                }
            }
            r++;
        }
    }
};