// https://leetcode.com/problems/couples-holding-hands/
#define all(c) c.begin(), c.end()
class Solution {
public:
    void _union(int a, int b, vector<int>& parent){
        int pa = _find(parent, a);
        int pb = _find(parent, b);
        if(pa != pb)
            parent[pa] = pb;
    }
    int _find(vector<int> parent, int a){
        while(parent[a] != a){
            a = parent[a];
        }
        return a;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        vector<int> parent(n);
        iota(all(parent), 0);
        for(int i = 0; i < row.size(); i++){
            row[i] = row[i]/2;
        }
        for(int i = 0; i < row.size(); i += 2){
            _union(row[i], row[i+1], parent);
        }
        int count = 0;
        for(int i = 0; i< n; i++){
            if(parent[i] == i)
                count++;
        }
        return n - count;
    }
};