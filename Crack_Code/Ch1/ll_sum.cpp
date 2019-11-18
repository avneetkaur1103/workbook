// Cracking the coding interview Q - 2.5

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int data = 0){
        this->data = data;
        next = nullptr;
	}
};

int length(Node* head){
	int cnt = 0;
	while(head){
		++cnt;
		head = head->next;
	}
	return cnt;
}

int sum(Node* h1, Node* h2, int diff){
	if(!h1 && !h2)
		return 0;
	if(!h1 || !h2)
		throw "Bad Point";

	if(diff > 0){
		int carry = sum(h1->next, h2, diff-1);
		int result_sum= (h1->data + carry);
		h1->data = result_sum%10;
		return result_sum/10;
	}
	else{
		int carry = sum(h1->next, h2->next, diff);
		int result_sum = (h1->data + h2->data + carry);
		h1->data = result_sum%10;
		return result_sum/10;
	}
}

Node* sum(Node* h1, Node* h2){
	int n = length(h1);
	int m = length(h2);
	int diff = n - m;
	if(diff<0)
		swap(h1, h2);
	int carry = sum(h1, h2, abs(diff));
	Node* result = h1;
	if (carry){
		Node* temp = new Node(carry);
		temp->next = result;
		result = temp;
	}
	return result;
}

void print(Node* head){
	while(head != nullptr){
		cout << head->data <<"->";
		head = head->next;
	}
	cout << "X" << endl;
}

void insert(Node*& h1, int val){
    if(!h1){
        h1 = new Node(val);
        h1->next = nullptr;
        return;
    }
	Node* temp = new Node(val);
	temp->next = h1;
	h1 = temp;
}

int main(){
	Node* h1 = nullptr;
	Node* h2 = nullptr;
	insert(h1, 7); insert(h1, 1); insert(h1, 6);
	insert(h2, 5); insert(h2, 9); insert(h2, 2); insert(h2, 6);
	print(h1);
	print(h2);
	h1 = sum(h1, h2);
	print(h1);
}
