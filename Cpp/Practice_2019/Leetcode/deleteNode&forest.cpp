// https://leetcode.com/problems/delete-nodes-and-return-forest/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define all(c) c.begin(), c.end()
class Solution {
public:
    TreeNode* _delete(TreeNode* root, unordered_set<int>& tbd, vector<TreeNode*>& result){
        if(root){
            root->left = _delete(root->left, tbd, result);
            root->right = _delete(root->right, tbd, result);
            if(tbd.find(root->val) != tbd.end()){ // => O(1)
                if(root->left)
                    result.push_back(root->left);
                if(root->right)
                    result.push_back(root->right);
                
                root = nullptr;
                delete(root);
                return nullptr;
            }
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        if(!root)
            return {};
        if(!to_delete.size()){
            result.push_back(root);
            return result;
        }
        unordered_set<int> tbd(all(to_delete));
        TreeNode* val = _delete(root, tbd, result);
        if(val)
            result.push_back(val);
        return result;
    }
};

/*
Strategy1: 
1. post-order traveresal
    => if root->val in to_delete
        =>store left & right | delete node | return null = > O(n*m)/ O(nlogm)
    build a hashmap for all to delet vals and do a look up in there in constant time => O(n)time + O(m) space

*/