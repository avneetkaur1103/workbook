// https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data = 0): data{data}, next{nullptr}, prev{nullptr}{}
};

int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if((*head_ref) != NULL)
    (*head_ref)->prev = new_node ;
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->prev);
    preOrder(node->next);
}

Node* sortedListToBSTUtil(Node*& head, int n){ // n = size
	if(!n)
		return nullptr;
	Node* left = sortedListToBSTUtil(head, n/2);
	Node *root = head;
	head = head->next;
	root->prev = left;
	root->next = sortedListToBSTUtil(head, n - n/2 - 1);
}

Node *sortedListToBST(Node *head){
	int n = countNodes(head);
	return sortedListToBSTUtil(head, n);

}

int main()
{
    Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 7->6->5->4->3->2->1 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout<<"Given Linked List\n";
    printList(head);

    /* Convert List to BST */
    Node *root = sortedListToBST(head);
    cout<<"\nPreOrder Traversal of constructed BST \n ";
    preOrder(root);

    return 0;
}
