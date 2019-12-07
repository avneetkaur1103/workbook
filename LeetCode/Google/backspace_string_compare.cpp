// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3060/
class Solution {
public:
    stack<char> _transform(string s){
        stack<char> st;
        for(auto ch: s){
            if(ch == '#'){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(ch);
        }
        return st;
    }
    bool _compare(stack<char>& st1, stack<char>& st2){
        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top())
                return false;
            st1.pop(); st2.pop();
        }
        return st1.empty() && st2.empty();
    }

    bool backspaceCompare(string S, string T) {
        stack<char> st1 = _transform(S);
        stack<char> st2 = _transform(T);
        return _compare(st1, st2);
    }
};