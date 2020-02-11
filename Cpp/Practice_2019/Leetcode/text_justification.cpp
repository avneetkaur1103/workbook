// https://leetcode.com/problems/text-justification/

class Solution {
public:
    string getstring(vector<string>& words, int l, int r, int count, int maxw){
        string result;
        int nw = r - l;
        if(nw == 1)
            return getlast(words, l, l, count, maxw);
        int spaced = (maxw - count) / (nw - 1);
        int spacer = (maxw - count) % (nw - 1);
        for(int i = l; i < r; i++){
            int spaceinbetween = 1 + spaced + (spacer > 0 ? 1: 0);
            result += words[i];
            if(i != r-1)
                result += string(spaceinbetween, ' ');
            spacer--;
        }
        return result;
    }
    string getlast(vector<string>& words, int l, int r, int count, int maxw){
        string result;
        for(int i = l; i <= r; i++){
            result += words[i];
            if(i != r)
                result += " ";
            else
                result += string(maxw-count, ' ');
        }
        return result;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int left = 0, right = -1;
        int count = 0;
        vector<string> result;
        while(right < n-1){
            ++right;
            if(count + words[right].length() > maxWidth){
                string stri = getstring(words, left, right, count-1, maxWidth);
                result.push_back(stri);
                count = 0; left = right;
            }
            count += words[right].length() + 1;
            
            if(right == n-1){
                string last = getlast(words, left, right, count-1, maxWidth);
                result.push_back(last);
            } 
        }
        return result;
    }
};