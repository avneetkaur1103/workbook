/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	int _size(ListNode* head){
		int count = 0;
		while(head){
			count++;
			head = head->next;
		}
		return count;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(_size(l2) > _size(l1))
        	swap(l1, l2);

        ListNode *head = l1, *tail = l1;
        int carry = 0;
        while(l1 && l2){
        	long _sum = l1->val+l2->val+carry;
        	carry = _sum/10;
        	l1->val = _sum%10;
        	tail = l1;
        	l1 = l1->next; l2 = l2->next;
        }

        while(l1){
        	long _sum = l1->val+carry;
        	carry = _sum/10;
        	l1->val = _sum%10;
        	tail = l1;
        	l1 = l1->next;
        }
        

        if(carry){
            ListNode *temp = new ListNode(carry);
            tail->next = temp;
        }
        return head;
    }
};