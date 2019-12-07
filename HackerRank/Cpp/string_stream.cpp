#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> v;
    if(str == "")
        return v;

	// Complete this function
    stringstream ss(str);
    char ignore; int x;
    ss >> x;
    v.push_back(x);
    while(ss >> ignore){
        ss >> x;
        v.push_back(x);
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

