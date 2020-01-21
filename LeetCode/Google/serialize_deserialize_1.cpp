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
// Full Tree Structure consideration approach
class Codec {
public:
    string _serialize(TreeNode *root){
        string node = "";
        string left = "";
        string right = "";
        
        if(root->left){
            node += "|" + to_string(root->left->val) + "|";
            left = _serialize(root->left);
        }
        else
            node += MARKER;
        
        if(root->right){
            node += "|" + to_string(root->right->val) + "|";
            right = _serialize(root->right);
        }
        else
            node += MARKER;
        
        
        return  node + left + right;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(root){
            result =  "|" + to_string(root->val) + "|";
            result += _serialize(root);
        }
        else
            result = MARKER;
        
        cout << "Serialized: " << result << endl;
        // return _serialize(root);
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
    void _deserialize(TreeNode* root, string& s, int& pos){        
        if(pos < s.length()){
            string token1 = getnext(s, pos);
            string token2 = getnext(s, pos);
            if(token1 == "$"){
                root->left = nullptr;
            }
            else{
                root->left = new TreeNode(stoi(token1));
                _deserialize(root->left, s, pos);
            }

            if(token2 == "$"){
                root->right = nullptr;
            }
            else{
                root->right = new TreeNode(stoi(token2));
                _deserialize(root->right, s, pos);
            }
        }        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        string token1 = getnext(s, pos);

        if(token1 == "$")
            return nullptr;
        else{
            TreeNode *root = new TreeNode(stoi(token1));
            _deserialize(root, data, pos);
            return root;
        }
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));