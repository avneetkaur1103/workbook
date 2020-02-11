#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

struct TreeNode{
	int val;
	Treenode* left;
	TreeNode* right;
	TreeNode(): val{0}, left{nullptr}, right{nullptr}{}
};

TreeNode* findNthNode(TreeNode* root, int n){
	if(root && n > 0){
		if(root->val+1 < n)
			return nullptr;
		if(root->left && root->left->val+1 >= n)
			return findNthNode(root->left, n);
		if(root->left && root->left->val+2 == n || n == 1)
			return root;
		if(root->right)
			return findNthNode(root->right, n- root->left->val-2);
	}
	return nullptr;
}

int main(){
	
}

what kind of test cases?
TC:
N = 0, -ve with valid tree/nulltree
N = valid range , valid tree/nulltree
N = out of range , valid tree/nulltree



big O notation, what is time complexity for that?
worst case: skewed tree  + 1st node => O(n);
best case: last node or root[O(1)] node & tree is complete tree + last Node [(log n)[avg] - O(n)[worst]]

Given a binary tree where each node knows the total count of its descendants, write FindNthNode(root, N), where N is the node's index based on in-order traversal. 

          A(5) N = 5
         /    \
       B(3)   C(0) c is the 6th node.
       /  \
    D(0)  E(1)
           /
         F(0)

FindNthNode, inputs are: root node, N, return a node.

What is the in-order traversal result of this tree?

D B F E A C

Strategy 1: 
	static counter during inorder traversal 
	as we hit counter == N 
return root; 

Strategy2:
	N = 5
if root->left->val >= N:
	goleft
if(N - (root->left->val+2) == 0)
	return root
else
	goright , N - (root->left->val+2)


# --------------------
There are n warriors in a war. Each warrior has a power P and a Direction d(left or right). 
Two warriors moving in opposite direction will collide and the warrior with more power will kill the warrior with lesser power. 
Find the warriors left after all the coliisions are complete.


W1    W2     W3
->    <-      <-


W1 8
W2 7
W3 10

Final Warrior Left : W3

vector<int> dir = [0,1,1];
W1 W2 =>  W1
W1 W3 => W3

10 elements index = 10 20

W1    W2     W3
->    ->     ->

Insertion  => for each element => O(1)*n
Deletion from stack => for each element => O(1)*n
Space => O(n) / Time = O(n);

stack<int> warriorsAlive(vector<string> warriors, vector<int>& dir, vector<int>& power){
    stack<int> st;
    int n = warriors.size();
    for(int i = 0; i < n; i++){
        while(!st.empty()){
            int tmp = st.top();
            if(dir[tmp] == 0 && dir[i] == 1){
                if(power[i] > power[tmp])
                    st.pop(); 
                else{
                    break; 
                }
            }
            else
                break;
        }
        if(stack.empty() || !(dir[st.top()] ^ dir[i])  || dir[tmp] == 1 && dir[i] == 0)
            st.push(i); 
    }
    return stack;
}

