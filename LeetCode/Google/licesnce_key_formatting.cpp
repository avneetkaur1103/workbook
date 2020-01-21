// https://leetcode.com/explore/interview/card/google/67/sql-2/472/
// Ref.  2-5g-3-J
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int pos = S.find('-');
        if(pos == string::npos)
        	return S;

        string result;
        string head = S.substr(0, pos+1);
        string tail = S.substr(pos+1);
        transform(head.begin(), head.end(), head.begin(), [](auto& ch){ return toupper(ch);});
        ostringstream oss;
        oss << head;

        stringstream ss(tail);
        char ch;
        int _count = 0;

        while(ss.get(ch)){
        	if(_count && _count%K == 0){
        		oss << '-';
        		_count = _count%K;
        	}
        	if(ch!='-'){
        		oss << (char)toupper(ch);
        		_count++;
        	}
        }
        return oss.str();
    }
};
int main(){
    string s = "2-5g-3-J";
    Solution sol;
    cout << sol.licenseKeyFormatting(s, 2) << endl;
}
