// https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/277/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void dfs(Node* u, unordered_map<Node*,Node*>& clones){
        for(auto v: u->neighbors){
            if(clones.find(v) == clones.end()){
                clones[v] = new Node(v->val, vector<Node*>());
                dfs(v, clones);
            }
            clones[u]->neighbors.push_back(clones[v]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        
        unordered_map<Node*,Node*> clones;
        set<Node*> visited;
        clones[node] = new Node(node->val, vector<Node*>());
        dfs(node, clones);
        return clones[node];
        
    }
};