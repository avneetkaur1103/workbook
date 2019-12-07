#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        set<vector<int>> all_triplets;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int a = nums[i], b = nums[j];
                if(counter.find(-(a+b)) != counter.end() && counter[-(a+b)]){
                    //cout << "Found: " << -(nums[i]+nums[j]) << " for " << nums[i] << "," << nums[j] << endl;
                    vector<int> v = {a,b, -(a+b)};
                    sort(all(v));
                    if(all_triplets.find(v) == all_triplets.end())
                        all_triplets.insert(v);
                }
            }
            counter[nums[i]]++;
        }
        return vector<vector<int>>(all(all_triplets));
    }
};
int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> result = sol.threeSum(v);
}
