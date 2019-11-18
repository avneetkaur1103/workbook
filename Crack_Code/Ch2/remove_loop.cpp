// Cracking the coding interview - Q -2.8

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int data = 0): data{data}, next{nullptr}{}
};

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

int length(Node* head){
	int cnt = 0;
	while(head){
		++cnt;
		head = head->next;
	}
	return cnt;
}

void print(Node* head){
	while(head != nullptr){
		cout << head->data <<"->";
		head = head->next;
	}
	cout << "X" << endl;
}

void remove_cycle(Node* head){
	Node* slow = head; Node* fast = head;
	while(true){
		if(slow && fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		if(slow == fast)
			break;
	}
	slow = head;
	while(fast->next != slow->next){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = nullptr;
}
int main(){
	Node* ll = nullptr;
	int random_node = rand()%10;
	Node* cycle_start = nullptr;
	Node* last = nullptr;
	for(int i = 0 ; i < 10; i++){
		insert(ll, i);
		if(i == random_node)
			cycle_start = ll;
		if(i == 0)
			last = ll;
	}

	last->next = cycle_start;

	remove_cycle(ll);
	print(ll);

}
