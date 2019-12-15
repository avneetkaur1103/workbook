// https://leetcode.com/problems/recover-binary-search-tree/submissions/

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
    void inorder(TreeNode *root, TreeNode*& prev, vector<TreeNode*>& store){
        if(root){
            inorder(root->left, prev, store);
            if(prev && prev->val > root->val){
                store.push_back(prev);
                store.push_back(root);
                //cout << prev->val << " " << root->val << endl;
            }
            prev = root;
            inorder(root->right, prev, store);
        }
        
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> store;
        TreeNode *prev = nullptr;
        inorder(root, prev, store);
        
        int n = store.size();
        if(n){
            //cout << "swap: " << store[0]->val << " " << store[1]->val << endl;
            //cout << store[0] << " " << store[n-1] << endl;
            swap(store[0]->val, store[n-1]->val);
        }
    }
};