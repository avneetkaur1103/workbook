// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/

#define all(c) c.begin(), c.end()

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        if(n < 2)
            return 0;
        
        vector<int> matchA(n, INT_MAX);
        vector<int> matchB(n, INT_MAX);
        int lastA = A[0], lastB = B[0];
        matchA[0] = 0; matchB[0] = 0;
        for(int i = 1; i < n; i++){
            if(matchA[i-1]!= INT_MAX){
                if(A[i] == lastA)
                    matchA[i] = matchA[i-1];
                else if(B[i] == lastA)
                    matchA[i] = 1+matchA[i-1];
            }
            if(matchB[i-1]!= INT_MAX){
                if(B[i] ==lastB)
                    matchB[i] = matchB[i-1];
                else if(A[i] == lastB)
                    matchB[i] = 1+matchB[i-1];
            }
        }
        
        int result = min(matchA[n-1], matchB[n-1]);
        lastA = B[0]; lastB = A[0];
        fill(all(matchA), INT_MAX); fill(all(matchB), INT_MAX);
        matchA[0] = 1; matchB[0] = 1;
        for(int i = 1; i < n; i++){
            if(matchA[i-1]!= INT_MAX){
                if(A[i] == lastA)
                    matchA[i] = matchA[i-1];
                else if(B[i] == lastA)
                    matchA[i] = 1+matchA[i-1];
            }
            if(matchB[i-1]!= INT_MAX){
                if(B[i] == lastB)
                    matchB[i] = matchB[i-1];
                else if(A[i] == lastB)
                    matchB[i] = 1+matchB[i-1];
            }
        }
        result = min(result, min(matchA[n-1], matchB[n-1]));
        return result == INT_MAX ? -1: result;
                                                    
    }
};