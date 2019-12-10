// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3073/

class Solution {
public:
    string multiply(int n, string& s){
        string result;
        for(int i = 0; i < n; i++){
            result += s;
        }
        return result;
    }
    int extract_multiplier(string& s, int& i){
        size_t len = 0;
        int result = stoi(s.substr(i), &len);
        i += len;
        return result;
    }
    string dfs(string& s, int& i, int n){
        string result;
        int multiplier = 1;
        multiplier = extract_multiplier(s, i);
        i += 1; // remove '['
        while(i < n){
            if(isdigit(s[i])){
                result += dfs(s, i, n);
            }
            else if(s[i] == ']'){
                i++;
                break;
            }
            else
                result += s[i++];
        }
        cout << "multiplier: " << multiplier << " result: " << result << endl;
        return multiply(multiplier, result);
    }
    string decodeString(string s) {
        int i = 0; int n = s.length();
        string result;
        while(i < n){
            if(isdigit(s[i]))
                result += dfs(s, i, n);
            else
                result += s[i++];
        }
        return result;
    }
};