#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data):data(data),left(nullptr),right(nullptr){};
	~Node();
};

// A utility function to do inorder traversal
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

/* A utility function to insert a new Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (!node) return new Node(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) Node pointer */
    return node;
}
void printIntersection(Node *root1 , Node *root2){
	stack<Node*> stack1, stack2;
	int data1,data2;
	Node *temp;

    do{
		while(root1){
            stack1.push(root1);
			root1 = root1->left;
		}

		while(root2){
            stack2.push(root2);
			root2 = root2->left;
		}
		if(!root1){
			temp = stack1.top();
			data1 = temp->data;
			stack1.pop();
			stack1.push(root1 = temp->right);
		}
		if(!root2){
			temp = stack2.top();
			data2 = temp->data;
			stack2.pop();
			stack2.push(root2 = temp->right);
		}

		while(data1 < data2){
			while(root1){
                stack1.push(root1);
                root1 = root1->left;
			}
			if(!stack1.empty() && !root1){
                temp = stack1.top();
                data1 = temp->data;
                stack1.pop();
                stack1.push(root1 = temp->right);
			}
		}
		while(data1 > data2){
			while(root2){
                stack2.push(root2);
                root2 = root2->left;
			}
			if(!stack2.empty() && !root2){
                temp = stack2.top();
                data2 = temp->data;
                stack2.pop();
                stack2.push(root2 = temp->right);
			}
		}
		cout << data1 << " ";
	}while(!stack1.empty() && !stack2.empty());
}

// Driver program
int main()
{
    // Create first tree as shown in example
    Node *root1 = nullptr;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);

    // Create second tree as shown in example
    Node *root2 = nullptr;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);

    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;

    cout << "Tree 2 : ";
    inorder(root2);

    cout << "\nCommon Nodes: ";
    printIntersection(root1, root2);

    return 0;
}
