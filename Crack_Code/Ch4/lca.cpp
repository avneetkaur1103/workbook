// Cracking the coding interiew Q - 4.8

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left, *right;
	Node(int data):data{data}, left(nullptr), right{nullptr}{}
};

pair<bool, bool> lca(Node* root, int n1, int n2, Node*& result){ // => This in O(n) we visit all nodes
	if(!root)
		return {false, false};

	pair<bool, bool> left = lca(root->left, n1, n2, result);
	pair<bool, bool> right = lca(root->right, n1, n2, result);

	bool bool_n1_left = left.first;
	bool bool_n2_left = left.second;
	bool bool_n1_right = right.first;
	bool bool_n2_right= right.second;


	if(result){
		return {true, true};
	}
	else if((bool_n1_left || bool_n1_right) && (bool_n2_left || bool_n2_right)){
		result = root;
		return {true, true};
	}
	else{
		if(root->data == n1){
			bool bool_n1 = true;
			if (bool_n1 && (bool_n2_left || bool_n2_right))
                result = root;
			return {bool_n1, bool_n2_left || bool_n2_right};
		}
		else if(root->data == n2){
			bool bool_n2 = true;
			if((bool_n1_left || bool_n1_right) && bool_n2)
                result = root;
			return {bool_n1_left || bool_n1_right, bool_n2};
		}
	}
	return {(bool_n1_left || bool_n1_right), (bool_n2_left || bool_n2_right)};
}
int find_lca(Node* root, int n1, int n2){
    Node *result = nullptr;
    lca(root, n1, n2, result);
    return result? result->data:-1;
}

int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << find_lca(root, 4, 5) << endl;
    cout << "LCA(4, 6) = " << find_lca(root, 4, 6) << endl;
    cout << "LCA(3, 4) = " << find_lca(root, 3, 4) << endl;
    cout << "LCA(2, 4) = " << find_lca(root, 2, 4) << endl;
    return 0;
}
