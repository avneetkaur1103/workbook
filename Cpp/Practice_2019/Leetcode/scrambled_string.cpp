// https://leetcode.com/problems/scramble-string/
#include <bits/stdc++.h>
using namespace std;

#define all(c) c.begin(), c.end()
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.size() == 1 || s1.size() != s2.size())
            return false;

        vector<int> counter(26, 0);
        for(int i = 0; i < s1.size(); i++){
            //cout << s1[i] << " " << s2[i] << endl;
            counter[s1[i]-'a']++;
            counter[s2[i]-'a']--;
        }

        if(count(all(counter), 0) != 26){
            //cout << "Char Mismatch" << endl;
            return false;
        }

        int len = s1.size();
        int mid = len/2;

            //cout << "w1 " << s1.substr(0, mid) << " w2 " << s2.substr(0,mid) << endl;
            //cout << "w1 " << s1.substr(mid) << " w2 " << s2.substr(mid) << endl;
            //cout << "-------1---------" << endl;
        if(isScramble(s1.substr(0, mid), s2.substr(0,mid)) && isScramble(s1.substr(mid), s2.substr(mid))){
            return true;
        }
        if(true){
                //cout << "w1 " << s1.substr(0, mid) << " w2 " << s2.substr(mid) << endl;
                //cout << "w1 " << s1.substr(mid) << " w2 " << s2.substr(0, mid) << endl;
                //cout << "-------2---------" << endl;
            if(isScramble(s1.substr(0, mid), s2.substr(mid)) && isScramble(s1.substr(mid), s2.substr(0, mid))){
                return true;
            }
        }
        if(true){
                //cout << "w1 " << s1.substr(0, mid) << " w2 " << s2.substr(mid+1) << endl;
                //cout << "w1 " << s1.substr(mid) << " w2 " << s2.substr(0, mid+1) << endl;
                //cout << "-------3---------" << endl;
            if(isScramble(s1.substr(0, mid), s2.substr(mid+1)) && isScramble(s1.substr(mid), s2.substr(0, mid+1))){
                return true;
            }
        }
        if(true){
               
            if(isScramble(s1.substr(0, mid+1), s2.substr(mid)) && isScramble(s1.substr(mid+1), s2.substr(0, mid))){
                return true;
            }
        }
        return false;
    }
};
