#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'collapseString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING inputString as parameter.
 */

string collapseString(string inputString) {
    string result = "";
    if(!inputString.size())
        return result;
    int left = 0, right = 0;
    int count = 0;
    while(right < n){
    	if(inputString[left] == inputString[right])
    		count++;
    	else{
    		result += to_string(count) + inputString[left];
    		count = 1;
    		left = right;
    	}
    	if(right == n-1){
    		result += to_string(count) + inputString[left];
    	}
    	++right;
    }
    return result;

}

int main()