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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode *first = head, *second = head;
    	for(int i = 0 ; i < n; i++){
    		second = second -> next;
    	}
        
        if(!second && first){ // for head to be deleted
            head = head -> next;
            return head;
        }
        
    	while(second-> next){
    		first = first->next;
    		second = second->next;
    	}
    	first->next = first->next->next;
        return head;
    }
};