// https://www.geeksforgeeks.org/sink-odd-nodes-binary-tree/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data): data{data}, left{nullptr}, right{nullptr}{}
};

void sink(Node *root){
	if(!root || !(root->data & 1) || (!root->left && !root->right))
		return;
	if(root->left && !(root->left->data&1)){
		swap(root->data, root->left->data);
		sink(root->left);
	}
	else if(root->right && !(root->right->data&1)){
		swap(root->data, root->right->data);
		sink(root->right);
	}
}

void sink_odds(Node* root){
	if(!root || (!root->left && !root->right))
		return;
	sink_odds(root->left);
	sink_odds(root->right);
	sink(root); //like heapify
}

void levelorder(Node* root){
	if(!root)
		return;

	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int count = q.size();
		while(count--){
			Node *temp = q.front();
			q.pop();
			cout << temp->data << " ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		cout << endl;
	}
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(5);
    root->right    = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
	sink_odds(root);
	levelorder(root);
}
