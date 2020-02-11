// https://leetcode.com/problems/remove-duplicate-letters/
#define all(c) c.begin(), c.end()
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int n = s.length();
        unordered_map<char, int> lastseen;
        for(int i = 0; i < n; i++){
            lastseen[s[i]] = i;
        }
        vector<bool> visited(26, false);
        for(int i = 0; i < n; i++){
            if(visited[s[i] - 'a'])
                continue;
            while(!st.empty() && st.top() > s[i] && lastseen[st.top()] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string result;
        while(!st.empty()){
            result += st.top(); st.pop();
        }
        reverse(all(result));
        return result;
    }
};