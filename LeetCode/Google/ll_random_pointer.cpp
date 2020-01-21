// https://leetcode.com/explore/interview/card/google/60/linked-list-5/3066/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dup = nullptr, *orig = head, *duphead = nullptr;
        if(!head)
            return nullptr;

        while(orig){ // Node creation part
            Node *temp = new Node(orig->val, nullptr, nullptr);
            temp->next = orig->next;
            orig->next = temp;
            orig = temp->next;
        }
        orig = head;
        dup = orig->next;
        while(orig){
            dup->random = orig->random->next;
            orig = dup->next;
            if(orig)
                dup = orig->next;
        }
        orig = head;
        duphead = dup = orig->next;
        while(orig){
            orig->next = dup->next;
            orig = orig->next;
            dup->next = orig?orig->next:nullptr;
            dup = dup->next;
        }
        return duphead;
    }
};
int main(){
    Node *l1;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1.random = l1->next;
    l1->next->random = l1->next;
    Solution sol;
    Node *result = sol.copyRandomList(l1);
    while(result){
        cout << "{" << result->val << "," < result->next << "," << result->random << "}" << endl;
        result = result->next
    }
}