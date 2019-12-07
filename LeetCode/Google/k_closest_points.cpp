#define all(c) c.begin(), c.end()

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        sort(all(points), [](auto a, auto b){ return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);});
        copy_n(points.begin(), K, back_inserter(result));
        return result;
    }
};