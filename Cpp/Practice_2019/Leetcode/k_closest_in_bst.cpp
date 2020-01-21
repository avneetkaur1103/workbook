//https://leetcode.com/problems/closest-binary-search-tree-value-ii/
/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
double epsilon =  0.001;
class Solution {
public:
    void closest(TreeNode* root, double target, int& mindiff, TreeNode*& c_TreeNode){
        if(!root)
            return;
        double diff = root->val - target;
        cout << "Diff: " << diff << endl;
        if(!c_TreeNode || abs(diff) +0.01 < mindiff){
            mindiff = abs(diff);
            c_TreeNode = root;
        }
        if(root->val > target)
            return closest(root->left, target, mindiff, c_TreeNode);
        else if(root->val < target)
            return closest(root->right, target, mindiff, c_TreeNode);
    }
    TreeNode* largest(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    
    TreeNode* smallest(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* get_next_pred(TreeNode*root, TreeNode* curr){
        TreeNode* pred = nullptr;
        while(root){
            if(root == curr){
                if(root->left)
                    pred = largest(root->left);
                return pred;
            }
            if(root->val > curr->val){
                root = root->left;
            }
            else{
                pred = root;
                root = root->right;
            }
        }
        return pred;
    }
    TreeNode* get_next_succ(TreeNode* root, TreeNode* curr){
        TreeNode* succ = nullptr;
        while(root){
            if(root == curr){
                if(root->right)
                    succ = smallest(root->right);
                return succ;
            }
            if(root->val > curr->val){
                succ = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return succ;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(!root)
            return {};
        TreeNode* c_TreeNode = nullptr;
        int mindiff = INT_MAX;
        closest(root, target, mindiff, c_TreeNode);
        if(!c_TreeNode){
            return vector<int>();
        }
        vector<int> vpred;
        vector<int> vsucc;
        vector<int> result;
        vsucc.push_back(c_TreeNode->val);
        TreeNode *pred = c_TreeNode, *succ = c_TreeNode;
        pred = get_next_pred(root,pred);
        succ = get_next_succ(root, succ);
        k--;
        while(k--){
            if(pred && succ){
                if(abs(target-pred->val) < abs(target-succ->val)){
                    vpred.push_back(pred->val);
                    pred = get_next_pred(root,pred);
                }
                else{
                    vsucc.push_back(succ->val);
                    succ = get_next_succ(root, succ);
                }
            }
            else if(pred){
                vpred.push_back(pred->val);
                pred = get_next_pred(root,pred);
            }
            else if(succ){
                vsucc.push_back(succ->val);
                succ = get_next_succ(root, succ);
            }
            else{
                cout << "Breaking" << endl;
                break;
            }
        }
        copy(vpred.rbegin(), vpred.rend(), back_inserter(result));
        copy(vsucc.begin(), vsucc.end(), back_inserter(result));
        return result;
    }
};