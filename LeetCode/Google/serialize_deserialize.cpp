#define MARKER "|$|"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string _serialize(TreeNode *root){
        if(!root)
            return MARKER;
        string s =  "|" + to_string(root->val) + "|" + _serialize(root->left) + _serialize(root->right);
        return s;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = _serialize(root);
        return result;
    }
    
    string getnext(string& s, int& pos){
        int pos1 = s.find('|', pos);
        int pos2 = s.find('|', pos1+1);
        int diff = pos2 - pos1 - 1;
        pos = pos2+1;
        cout << "Pos: " << pos << endl;
        cout << "Token: " << s.substr(pos1+1, diff) << endl;
        return s.substr(pos1+1, diff);
    }

    TreeNode* _deserialize(string& s, int& pos){        
        TreeNode *root = nullptr;
        if(pos < s.length()){
            string token1 = getnext(s, pos);
            if( token1 == "$"){
                root = nullptr;
            }
            else{
                root = new TreeNode(stoi(token1));
                root->left = _deserialize(s, pos);
                root->right = _deserialize(s, pos);
            }
        }
        return root;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return _deserialize(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));