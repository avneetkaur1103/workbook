#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int& result){
        if(!root)
            return 0;
        int left = maxPathSumUtil(root->left, result);
        int right = maxPathSumUtil(root->right, result);
        result = max(result, root->val);
        result = max(result, root->val+max(left, right));
        result = max(result, root->val+left+right);

        return root->val+ (max(left, right) > 0? max(left, right): 0);
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSumUtil(root, result);
        return result;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
    Solution sol;
    cout << "Ans: " << sol.maxPathSum(root);
}
