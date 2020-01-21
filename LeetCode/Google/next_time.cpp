// https://leetcode.com/explore/interview/card/google/59/array-and-strings/471/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution {
public:
    set<string> all_numbers;
    string next_greater(int num){
        auto itr = upper_bound(all(all_numbers), to_string(num));
        return (itr == all_numbers.end() ? "" : *itr);
    }
    void init(string& time, int& hr, int& mn, string& hours, string& minutes){
        int pos = time.find(':');
        minutes = time.substr(pos+1);
        hours = time.substr(0, pos);
        cout << "Hrs: " << hours << "Min: " << minutes << endl;
        hr = stoi(hours);
        mn = stoi(minutes);
        time.erase(pos, 1); // delets 1 char
        int n = time.size();
        cout << "Time: " << time << endl;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string n1 = string() + time[i] + time[j];
                string n2 = string() + time[j] + time[i];
                if(n1 < "60")
                    all_numbers.insert(n1);
                if(n2 < "60")
                    all_numbers.insert(n2);
            }
        }
        for(auto i: all_numbers){
            cout << i << " ";
        }
        cout << endl;
    }
    string nextClosestTime(string time) {
        int hr, mn;
        string minutes, hours;
        init(time, hr, mn, hours, minutes);


        int carry = (mn+1)/60;
        if(!carry && next_greater(mn)!= ""){
            minutes = next_greater(mn);
        }
        else{
            mn = 0;
            minutes = next_greater(mn);
            hr = (hr + carry) % 24;
            hours = next_greater(hr);
        }
        return hours + ":" + minutes;


    }
};
int main(){
    string s = "01:37";
    Solution sol;
    cout << sol.nextClosestTime(s);
}
