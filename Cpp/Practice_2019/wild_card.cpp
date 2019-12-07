// leat code wildcard pattern matching

class Node{
    char ch;
    Node* next;
    bool is_final_state;
    
    Node(char ch, bool is_final=false): ch{ch}, is_final_state(is_final),next{nullptr}{}
};

class Solution {
public:
    bool isMatch(string s, string p) {
    	Node* start = Node('', true);
        for(auto ritr = p.rbegin(); ritr != rend(); ritr++){
            Node *temp = new Node(*itr);
            temp->next = start;
            start = temp;
        }
        queue<pair<Node*, string>> q;
        q.push({start, s});
        while(q.size()){
        	pair<Node*, string> temp = q.pop();
        	Node* node = temp.first;
        	string& s = temp.second;
        	if(!s.length() && node.is_final_state)
        		return true;
        	if(node.ch == '*'){
        		if(s.length()){
        			
        		}
        	}
        	
        }
        
    }
};