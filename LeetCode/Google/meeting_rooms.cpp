// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3059/
#define all(c) c.begin(), c.end()
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(all(start)); sort(all(end));
        
        int count = 0;
        int start_index = 0, end_index = 0;
        int max_count = 0;
        
        while(start_index < n){
            if(start[start_index] < end[end_index]){
                count++; start_index++;
                max_count = max(count, max_count);
            }
            else if(start[start_index] < end[end_index]){
                count--; end_index++;
            }
            else{
                start_index++; end_index++;
            }     
        }
        return max_count;
    }
};