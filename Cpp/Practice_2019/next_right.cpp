// https://www.geeksforgeeks.org/find-next-right-node-given-key-set-2/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *left, *right;
    int key;
};

// Utility function to create a new tree node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node *nextRightNodeRecur(Node* root, int nodeval, int curr_level, int& value_level){
	if(!root)
		return root;
	if(value_level == curr_level)
		return root;

	if(root->key == nodeval){
		value_level = curr_level;
		return nullptr;
	}
	Node* result = nullptr;
	result = nextRightNodeRecur(root->left, nodeval, curr_level+1, value_level);
	if(!result)
		result = nextRightNodeRecur(root->right, nodeval, curr_level+1, value_level);
	return result;

}

Node* nextRightNodeUtil(Node* root, int k)
{
	int level = -1;
	return nextRightNodeRecur(root, k, 0, level);

}

void test(Node* root, int k)
{
    Node* nr = nextRightNodeUtil(root, k);
    if (nr != NULL)
        cout << "Next Right of " << k << " is "
             << nr->key << endl;
    else
        cout << "No next right node found for "
             << k << endl;
}

// Driver program to test above functions
int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
