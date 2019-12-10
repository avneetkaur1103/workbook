// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/331/
#define all(c) c.begin(), c.end()
class Solution {
public:
    double find_path(unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited, string& src, string& dest){
        if(src == dest)
            return 1;
        
        visited.insert(src);
        double result = 0;
        for(auto p: adj[src]){
            string v = p.first; double wt = p.second;
            if(visited.find(v) == visited.end()){
                result = wt * find_path(adj, visited, v, dest);
                if(result)
                    return result;
            }
        }
        return result;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < n; i++){
            auto eq = equations[i];
            double wt = values[i];
            adj[eq[0]].push_back({eq[1], wt});
            adj[eq[1]].push_back({eq[0], 1.0/wt});
        }
        vector<double> result;
        unordered_set<string> visited;
        for(auto q: queries){
            visited.clear();
            if(adj.find(q[0])== adj.end() || adj.find(q[1])== adj.end()){
                cout << "Not Found: " << q[0] << " " << q[1] << endl;
                result.push_back(-1);
                continue;
            }
            double val = find_path(adj, visited, q[0], q[1]);
            result.push_back(val ? val : -1);
        }
        return result;
    }
};