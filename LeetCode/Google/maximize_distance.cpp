// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3058/
#define all(c) c.begin(), c.end()
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = -1;
        int right = -1;
        int n = seats.size();
        vector<int> dist(n, INT_MAX);
        
        for(int i = 0; i < n; i++){
            if(seats[i]){
                left = i;
                dist[i] = INT_MIN;
            }
            else{
                if(left != -1)
                    dist[i] = min(i-left, dist[i]);
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(seats[i]){
                right = i;
                dist[i] = INT_MIN;
            }
            else{
                if(right != -1)
                    dist[i] = min(right-i, dist[i]);
            }
        }
        return *max_element(all(dist));
    }
};