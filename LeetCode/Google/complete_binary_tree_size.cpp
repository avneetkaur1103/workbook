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
    int depth(TreeNode* root){
        int count = -1;
        while(root){
            root = root->left;
            count++;
        }
        return count;
    }
    bool exists(TreeNode *root, int val, int d){
        int low = 0, high = pow(2, d) -1;
        for(int i = 0; i < d; i++){
            int mid = low + (high-low)/2;
            if(mid >= val){
                root = root->left;
                high = mid;
            }
            else if(mid < val){
                root = root-> right;
                low = mid + 1;
            }
        }
        return root != NULL;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int d = depth(root);
        if(d == 0)
            return 1;
        
        int left = 1, right = pow(2, d) -1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(exists(root, mid, d))
                left = mid+1;
            else 
                right = mid-1; 
        }
        return pow(2, d) -1 + left;
        
    }
};