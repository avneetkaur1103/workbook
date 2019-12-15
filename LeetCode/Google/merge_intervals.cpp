class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(!n)
            return {newInterval};
        
        vector<vector<int>> st;
        int i = 0;
        while(i<n || newInterval.size()){
            vector<int> next;
            if((i>=n) || (newInterval.size() && newInterval[0] < intervals[i][0])){
                next = newInterval;
                newInterval.clear();
            }
            else
                next = intervals[i++];
            
            if(!st.size()){
                st.push_back(next);
                continue;
            }
                
            vector<int>& top = st.back();
            if(next[0] <= top[1])
                top[1] = max(next[1], top[1]);
            else
                st.push_back(next);
        }
        return st;
    }
};