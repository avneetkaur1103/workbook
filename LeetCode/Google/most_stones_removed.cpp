// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3076/
class Solution {
public:
    void _union(int u, int v, vector<int>& parent){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu != pv)
            parent[pv] = pu;
    }
    int find(int u, vector<int>& parent){
        while(parent[u] != u){
            u = parent[u];
        }
        return u;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i!=j && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])){
                    _union(i, j, parent);
                }     
            }
        }
        unordered_set<int> components;
        for(int i = 0; i < n; i++)
            components.insert(find(i, parent));

        return n-components.size();
    }
    
};