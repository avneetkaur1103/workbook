#include <bits/stdc++.h>
using namespace std;

vector<int> points = {1, 2, 3};
int formations(int n){
    static vector<int> v;
    if(!n){
        for(auto x: v)
            cout << x << " ";
        cout << endl;
    }
    for(int p: points){
        if(n >= p){
            v.push_back(p);
            formations(n-p);
            v.pop_back();
        }
    }
}
int main(){
	formations(5);
}
