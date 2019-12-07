class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)
            return 0;
        
        int min_till_now = prices[0];
        int max_profit = 0;
        for(int i = 1 ; i < n; ++i){
            max_profit = max(max_profit, prices[i]-min_till_now);
            min_till_now = min(min_till_now, prices[i]);
        }
        return max_profit;
    }
};