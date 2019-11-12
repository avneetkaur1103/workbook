#include<bits/stdc++.h>
using namespace std;

class Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node(int data):data(data),left(nullptr),right(nullptr){};
	~Node();
	
};

struct Info
{
	int min;
	int max;
	int size;
	bool isBST;
};

int largestBST(Node *root){

	if(!root) return {INT_MAX, INT_MIN,0,true};

	Info left = largestBST(root->left);
	Info right = largestBST(root->right);
	
	Info ret;

	ret._min = min(left.min, min(right.min,root->data));
	ret._max = max(left.max, max(right.max,root->data));
	ret.isBST = false;
	if(left.isBST && right.isBST && root->data > left.max && root->data < right.min){
		ret.size = 1 + left.size + right.size;
		ret.isBST = true;
	}
	else
		ret.size = max(left.size,right.size);
	return ret;
}

/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */
 
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    printf(" Size of the largest BST is %d\n",
           largestBST(root).size);
    return 0;
}