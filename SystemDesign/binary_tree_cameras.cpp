// https://leetcode.com/problems/binary-tree-cameras/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int postorder(TreeNode* root, unordered_set<TreeNode*>& covered, TreeNode* parent){
        if(!root)
            return 0;
        int left = postorder(root->left, covered, root);
        int right = postorder(root->right, covered, root);
        int result = left + right;
        
        if(!parent && covered.find(root) == covered.end() ||
          root->left && covered.find(root->left) == covered.end()||
          root->right && covered.find(root->right) == covered.end()){
            result += 1;
            covered.insert(root); covered.insert(root->left); covered.insert(root->right);
            covered.insert(parent);
        }
        return result;
    }
    int minCameraCover(TreeNode* root) {
        if(!root)
            return 0;
        unordered_set<TreeNode*> covered;
        return postorder(root, covered, nullptr);
    }
};