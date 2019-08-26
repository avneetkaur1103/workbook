#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data):left(nullptr),right(nullptr){
		Node::data = data;
	}
};

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

int getN(list<int>& sortedList, int n){
    int count_  = 0;
    for(auto i : sortedList){
        if(count_ == n )
            return i;
        count_++;
    }
    cout << "Error" << " n = " << n ; exit(1);
}
Node* buildBST(list<int>& sortedList, int low, int high){
	if(low > high) return nullptr;

	int mid = low + (high-low)/2;
	Node *root = nullptr;
	if(low == high)
		root = new Node(getN(sortedList,mid));

	if(low < high){
		root = new Node(getN(sortedList,mid));
		root->left = buildBST(sortedList,low,mid-1);
		root->right= buildBST(sortedList,mid+1,high);
	}
	return root;
}

int main(){
	list<int> sortedList({1,2,3,4,5,6,7});
	Node* root = buildBST(sortedList,0,sortedList.size()-1);
	inOrder(root);
}
