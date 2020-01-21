#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data): data{data}, left(nullptr), right{nullptr}{}
};

void print(vector<int>& v){
    for(auto i: v)
        cout << i << " ";
    cout << endl;
}
vector<int> extract(vector<int> lo, vector<int> in, int start, int end){
    cout << "Start: " <<  start << "End: " << end  << endl;
	if(start > end)
		return {};
	vector<int> result;
	for(int i = 1; i < lo.size(); i++){
		if(find(in.begin()+start, in.begin()+end+1, lo[i]) != in.begin()+end+1){
			result.push_back(lo[i]);
		}
	}
	return result;
}

Node *build_tree(vector<int>& inorder, vector<int>& lorder, int start, int end){
	if(start > end)
		return nullptr;

	Node *root = new Node(lorder[0]);
	if(start == end)
		return root;

	int index = find(all(inorder), lorder[0]) - inorder.begin();
	vector<int> leftlo = extract(lorder, inorder, start, index-1);
	vector<int> rightlo = extract(lorder, inorder, index+1, end);
	cout << "leftlo: "; print(leftlo);
	cout << "rightlo: "; print(rightlo);
	root->left = build_tree(inorder, leftlo, start, index-1);
	root->right = build_tree(inorder, rightlo, index+1, end);
	return root;
}

void print_inorder(Node* root){
    if(root){
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);
    }
}

int main(){
	vector<int> inorder = {4, 8, 10, 12, 14, 20, 22};
	vector<int> lorder = {20, 8, 22, 4, 12, 10, 14};
	int n = inorder.size();
	Node *root = build_tree(inorder, lorder, 0, n-1);
	print_inorder(root);
}

