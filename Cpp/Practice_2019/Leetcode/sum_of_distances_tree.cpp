// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

class Solution {
public:
    void postorder(int u,vector<vector<int>>& adj, vector<int>& ans, vector<int>& count, int parent){
        for(auto v: adj[u]){
            if(parent == v)
                continue;
            postorder(v, adj, ans, count, u);
            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
    }
    void preorder(int u,vector<vector<int>>& adj, vector<int>& ans, vector<int>& count, int parent, int N){
        for(auto v: adj[u]){
            if(parent == v)
                continue;
            ans[v] = ans[u] - count[v] + N - count[v];
            preorder(v, adj, ans, count, u, N);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        int n = N;
        vector<vector<int>> adj(n);
        for(auto p: edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> result(n, 0);
        vector<int> count(n, 1);
        postorder(0, adj, result, count, -1);
        preorder(0, adj, result, count, 0, n);
        return result;
    }
};