// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// int hist[] = {6, 2, 5, 4, 5, 1, 6};
#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
class Node{
    public:
        char data;
        Node* left;
        Node* right;
        Node(int data):data{data}, left{nullptr}, right{nullptr}{}
};

void printInorder(Node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

void preorder(Node* root1, Node* root2, int level){
	if(!root1 || !root2)
		return;

	if(!(level&1)){
        cout << "swapping " << root1->data << " " << root2->data << endl;
		swap(root1->data, root2->data);
	}
	preorder(root1->left, root2->right, level+1);
	preorder(root1->right, root2->left, level+1);
}

void reverseAlternate(Node* root){
	preorder(root->left, root->right, 0);
}

// Driver program to test above functions
int main()
{
    Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    cout << "Inorder Traversal of given tree\n";
    printInorder(root);

    reverseAlternate(root);

    cout << "\n\nInorder Traversal of modified tree\n";
    printInorder(root);
    return 0;
}
