// Cracking the coding intreview Q - 4.9
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

class Node{
public:
	int data;
	Node* left, *right;
	Node(int data):data{data}, left(nullptr), right{nullptr}{}
};

void _copy(vector<vector<int>>& result, int data, vector<int>& v1, vector<int>& v2){
	int n1 = v1.size();
	int n2 = v2.size();
	// cout << "n1: " << n1 << " n2: " <<n2 << endl;
	vector<int> temp;
	temp.push_back(data);
	copy(v1.begin(), v1.end(), back_inserter(temp));
	copy(v2.begin(), v2.end(), back_inserter(temp));
	result.push_back(temp);
}

void _copy(vector<vector<int>>& result, int data, vector<int>& v1){
	int n1 = v1.size();
	// cout << "n1: " << n1 << endl;
	vector<int> temp;
	temp.push_back(data);
	copy(v1.begin(), v1.end(), back_inserter(temp));
	result.push_back(temp);
}

vvi print_arrays(Node* root){
	if(!root){
		vvi result;
		return result;
	}

	vvi left = print_arrays(root->left);
	vvi right = print_arrays(root->right);
	vvi result;

	if(!left.size() && !right.size()){
		vector<int> v = {root->data};
		result.push_back(v);
	}
	else if(left.size() && right.size()){
		for(auto vl: left){
			for(auto vr: right){
				_copy(result, root->data, vl, vr);
				_copy(result, root->data, vr, vl);
			}
		}
	}
	else if(left.size()){
        for(auto vl: left)
            _copy(result, root->data, vl);
	}
	else if(right.size()){
		for(auto vr: right)
            _copy(result, root->data, vr);
	}
	return result;
}
int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vvi result = print_arrays(root);
    for(auto v: result){
        for(auto i: v){
            cout << i << " ";
        }
        cout << "\n";
    }
}
