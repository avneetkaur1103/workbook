// https://leetcode.com/problems/new-21-game/
#define all(c) c.begin(), c.end()
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if((!K) || K-1+W<=N )
            return 1;
        
        vector<double> dp(N+1, 0);
        
        dp[0] = 1.0; double currsum = 1;
        for(int i = 1; i <= N; i++){ // curr val
            dp[i] = currsum/W;
            if(i < K)
                currsum += dp[i];
            if(i >= W)
                currsum -= dp[i-W];
        }
        double result = 0;
        for(int i = K; i <= N; i++){
            cout << dp[i] << " ";
            result += dp[i];
        }
        return result;
    }
};

// ---------------------- TLE Below

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if((!K && !N) || K-1+W <=N)
            return 1;
        
        vector<double> dp(N+1, 0);
        
        dp[0] = 1.0;
        for(int i = 0; i < K; i++){ // curr val
            for(int j = 1; j <= W ; j++){ // picked val
                if(i+j <= N)
                    dp[i+j] += dp[i]/W;
            }
        }
        double result = 0;
        for(int i = K; i <= N; i++){
            cout << dp[i] << " ";
            result += dp[i];
        }
        return result;
    }
};