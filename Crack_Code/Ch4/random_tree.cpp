// Cracking the coding interview Q - 4.11

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int left_count;
	Node *left, *right;

	Node(int data = 0):data{data}, left{nullptr}, right{nullptr}, left_count{1}{}
};

int size(Node *root){
	if(!root)
		return 0;
	return 1 + size(root->left) + size(root->right);
}

Node* insert(Node* root, int data){
	if(!root)
		return new Node(data);
	if(data < root-> data){
		root->left = insert(root->left, data);
		root->left_count += 1;
		return root;
	}
	else{
		root->right = insert(root->right, data);
		return root;
	}
}

Node*  get_nth(Node* root, int n){
	if(!root){
		cout << "Not Found for " << n <<endl;
		return nullptr;
	}

	if(root->left_count == n)
		return root;
	if(root->left_count > n)
		return get_nth(root->left, n);
	return get_nth(root->right, n - root->left_count);
}

Node* get_randon(Node* root){
	int n = size(root);
	int rand_int = rand() % n + 1;
	return get_nth(root, rand_int);
}

void inorder(Node *root)
{
    if (!root)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);
    srand(time(NULL));
    Node *result = get_randon(root);
    cout << "Random Node " << result->data << endl;
    result = get_randon(root);
    cout << "Random Node " << result->data << endl;
    result = get_randon(root);
    cout << "Random Node " << result->data << endl;
    result = get_randon(root);
    cout << "Random Node " << result->data << endl;

    return 0;
}
