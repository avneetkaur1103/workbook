// https://leetcode.com/explore/featured/card/google/61/trees-and-graphs/3070/
#define all(c) c.begin(), c.end()

class Solution {
public:
    bool topological_sort(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& st, vector<int>& rec_stack){
        visited[u] = true;
        rec_stack.push_back(u);
        for(auto v: adj[u]){
            if(!visited[v]){
                if(topological_sort(v, adj, visited, st, rec_stack))
                    return true;
            }
            else if(find(all(rec_stack), v) != rec_stack.end()){
                cout << "found: " << v << endl;
                for(auto i: rec_stack)
                    cout << i << " ";
                cout << endl;
                return true;
            }
        }
        rec_stack.pop_back();
        st.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> st; // stack
        vector<int> rec_stack; // stack
        vector<bool> visited(numCourses, false);
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(topological_sort(i, adj, visited, st, rec_stack))
                    return vector<int>(); // cyclic
            }
        }
        reverse(all(st));
        return st;
    }
};