// https://leetcode.com/problems/basic-calculator-iii/

class Solution {
public:
    long getval(long op1, long op2, char op){
        switch(op){
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/' : return op1/op2;
            default: cout << "invalid oprator " << op << endl; return 0;
        }
    }
    int preceed(char op){
        switch(op){
            case '+':
            case '-': return 0;
            case '*': 
            case '/' : return 1;
            default: cout << "invalid input"; return -1;
        }
    }
    int calculate(string s) {
        stack<long> nums;
        stack<char> op;
        int i = 0, n = s.length();
        while(i < n){
            if(s[i] == '-' && (i == 0 || (i > 0 && s[i-1] == '('))){
                cout << "-ve no" << endl;
                ++i;
                size_t len = 0;
                long val = (int)stol(s.substr(i), &len);
                i += len-1;
                nums.push(-1* val);
            }
            else if(s[i] == ' '){
                ++i; continue;
            }
            else if(isdigit(s[i])){
                size_t len = 0;
                long val = (int)stol(s.substr(i), &len);
                i += len-1;
                nums.push(val);
            }
            else if(s[i] == '(')
                op.push(s[i]);
            else if(s[i] == ')'){
                while(!op.empty()){
                    char opr = op.top(); op.pop();
                    if(opr == '(')
                        break;
                    int op2 = nums.top(); nums.pop();
                    int op1 = nums.top(); nums.pop();
                    int result = getval(op1, op2, opr);
                    nums.push(result);
                }
            }
            else{
                while(!op.empty() && op.top() != '(' && preceed(s[i]) <= preceed(op.top())){ // = is important for left to right associativity of no in case of -ve no on the left
                    char opr = op.top(); op.pop();
                    int op2 = nums.top(); nums.pop();
                    int op1 = nums.top(); nums.pop();
                    int result = getval(op1, op2, opr);
                    nums.push(result);
                }
                op.push(s[i]);
            }
            ++i;
        }
        while(!op.empty()){
            char opr = op.top(); op.pop();
            int op2 = nums.top(); nums.pop();
            int op1 = nums.top(); nums.pop();
            int result = getval(op1, op2, opr);
            nums.push(result);
        }
        return nums.top();
    }
};