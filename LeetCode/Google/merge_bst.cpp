// https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data = 0): data{data}, left{nullptr}, right{nullptr}{}
};

void merge(Node* root1, Node* root2){
	stack<Node*> st1;
	stack<Node*> st2;
	Node *curr1 = root1, *curr2 = root2;
	while(true){
		while(curr1){
			st1.push(curr1);
			curr1 = curr1 -> left;
		}
		while(curr2){
			st2.push(curr2);
			curr2 = curr2 -> left;
		}
		if(!st1.empty() && !st2.empty()){
			Node* top1 = st1.top();
			Node* top2 = st2.top();

			if(top1->data < top2->data){
				cout << top1->data << " ";
				curr1 = top1->right; st1.pop();
			}
			else{
				cout << top2->data << " ";
				curr2 = top2->right; st2.pop();
			}
		}
		else{
			if(!st1.empty()){
				cout << (st1.top())->data << " ";
				curr1 = st1.top()->right; st1.pop();
			}
			else if(!st2.empty()){
				cout << (st2.top())->data << " ";
				curr2 = st2.top()->right; st2.pop();
			}
			else return;
		}
	}
}

int main(){
	Node *root1 = NULL, *root2 = NULL;

    /* Let us create the following tree as first tree
            3
        / \
        1 5
    */
    root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    /* Let us create the following tree as second tree
            4
        / \
        2 6
    */
    root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Print sorted nodes of both trees
    merge(root1, root2);
}
