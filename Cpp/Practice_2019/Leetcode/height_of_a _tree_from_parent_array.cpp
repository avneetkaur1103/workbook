// https://leetcode.com/problems/k-similar-strings/
#define all(c) c.begin(), c.end()
class Solution {
public:
    int _find(int i, vector<int>& parent){
        while(parent[i] != i){
            i = parent[i];
        }
        return i;
    }
    void _union(int a, int b, vector<int>& parent){
        int pa = _find(a, parent);
        int pb = _find(b, parent);
        parent[pa] = pb;
    }
    int kSimilarity(string A, string B) {
        int n = A.size();
        vector<int> parent(n, 0);
        iota(all(parent), 0);
        vector<list<int>> locations(6);
        for(int i = 0; i < n; i++){
            if(A[i] != B[i])
                locations[A[i]-'a'].push_back(i);
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] == B[i])
                continue;
            char ch = B[i];
            int j = locations[ch-'a'].front();
            _union(i, j, parent);
            locations[ch-'a'].pop_front();
            cout << "union: " << i << " " << j << endl;
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            cout << "i: " << i << " parent: " << parent[i] << endl;
            if(parent[i] == i){
                count++;
            }
        }
        return n-count;
    }
};