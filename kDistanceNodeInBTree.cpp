#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node(int x):data(x){
		left = NULL ; right = NULL;
	};
};

void printKDistanceDown(Node* root , int k ,set<int>& result){
	if(root == NULL || k < 0)
		return;
	if(k == 0){
		result.insert(root->data);
		return;
	}
	printKDistanceDown(root->left, k-1, result);
	printKDistanceDown(root->right,k-1,result);
}

int printKDistance(Node* root, int target, int k, set<int>& result){
	if(root == NULL || k < 0) return -1;

	if(root->data == target){
		printKDistanceDown(root, k, result);
		return 0;
	}

	int dl = printKDistance(root->left, target, k, result);
	if(dl != -1){
		if(dl+1 == k)
			result.insert(root->data);
		printKDistanceDown(root->right,k - dl -2,result);
		return 1+dl;
	}
	int dr = printKDistance(root->right, target, k, result);
	if(dr != -1){
		if(dr+1 == k)
		result.insert(root->data);
		printKDistanceDown(root->left,k - dr -2,result);
		return 1+dr;
	}
	return -1;
}

Node* addNode(unordered_map<int,Node*>& treeMap, int x , int y , char dir){
	Node *nodeX , *nodeY;
	if(treeMap.find(x) != treeMap.end())
		nodeX = treeMap[x];
	else{
		nodeX = new Node(x);
		treeMap[x] = nodeX;
	}
	if(dir == 'L'){
		nodeX->left = new Node(y);
		treeMap[y] = nodeX->left;
	}
	else{
		nodeX->right = new Node(y);
		treeMap[y] = nodeX->right;
	}
	return nodeX;
}

int main(){
	int n_tc;
	cin >> n_tc;
	while(n_tc--){
		int n,x,y; char ch; Node* root;
		unordered_map<int, Node*> treeMap;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> x >> y >> ch;
			Node *node = addNode(treeMap,x,y,ch);
			if(i == 0)
				root = node;
		}
		int target , k; set<int> result;
		cin >> target >> k;
		printKDistance(root,target,k,result);
		for(auto i : result)
			cout << i << " ";
		cout << endl;
		for(auto i : treeMap)
			delete i.second;
	}
}
