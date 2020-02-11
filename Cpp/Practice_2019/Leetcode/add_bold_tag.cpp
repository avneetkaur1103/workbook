// https://leetcode.com/problems/add-bold-tag-in-string/
#define all(c) c.begin(), c.end()

class Solution {
public:
    vector<pair<int, int>> _copy(stack<pair<int, int>>& st, vector<pair<int, int>>& intervals){
        intervals.clear();
        while(!st.empty()){
            intervals.push_back(st.top()); st.pop();
        }
        reverse(all(intervals));
        return intervals;
    }
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        if(!n)
            return "";
        
        vector<pair<int, int>> intervals;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                string word = s.substr(j, i-j+1);
                if(find(all(dict), word) != dict.end())
                    intervals.push_back({j,i});
            }
        }
        stack<pair<int, int>> st;
        for(auto p: intervals){
            while(!st.empty() && st.top().first > p.first){
                st.pop();
            }
            if(!st.empty() && st.top().second >= p.first-1)
                st.top().second = p.second;
            else
                st.push(p);
        }
        _copy(st, intervals);
        int i = 0, j = 0;
        string result;
        while(i < n){
            if(j < intervals.size() && i == intervals[j].first)
                result += "<b>";
            result += s[i];
            if(j < intervals.size() && i == intervals[j].second){
                result += "</b>"; j++;   
            }
            i++;
        }
        return result;
    }
};