// https://leetcode.com/explore/interview/card/google/59/array-and-strings/342/

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
    int _size(ListNode *head){
        int count;
        while(head){
            ++count;
            head = head->next;
        }
        return count;
    }
    
    ListNode* _merge(ListNode* l1, ListNode* l2){

        ListNode *head = nullptr, *tail = nullptr;
        while(l1 && l2){
            ListNode *temp;
            if(l1->val < l2->val){
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp = l2;
                l2 = l2->next;
            }
            if(!head)
                head = tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        while(l1){
            ListNode *temp;
            temp = l1;
            l1 = l1->next;
            if(!head)
                head = tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        while(l2){
        	ListNode *temp;
        	temp = l2;
        	l2 = l2->next;

        	if(!head)
        		head = tail = temp;
        	else{
        		tail->next = temp;
        		tail = temp;
        	}
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        for(int i = 0; i < lists.size(); i++){
            result = _merge(result, lists[i]);
        }
        return result;
    }
};