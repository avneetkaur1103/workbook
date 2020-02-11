// https://leetcode.com/problems/brace-expansion-ii/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
class Solution { // ex : R("a{b,c}{d,e}f{g,h}")
public:
	vector<string> op_product(vector<string>& v1, vector<string> v2){
		vector<string> result;
		for(auto str1: v1){
			for(auto str2: v2){
				result.push_back(str1+str2);
			}
		}
		return result;
	}
	void op_union(vector<string>& v1, vector<string>& v2){
		copy(all(v2), back_inserter(v1));
		v2.clear();
	}
	void print(vector<string> vec){
        for(auto v: vec)
            cout << v << " ";
        cout << endl;
	}
	vector<string> eval(string expression, int& pos, int n){
		vector<string> result;
        vector<string> left;
		while(pos < n && expression[pos] != '}'){
            cout << "pos: " << pos << " char: " << expression[pos] << endl;
            cout << "left ";
            print(left);
			if(expression[pos] == '{'){
                ++pos;
				auto right = eval(expression, pos, n);
				if(left.size())
					left = op_product(left, right);
				else
					op_union(left, right);
			}
			else if(expression[pos] == ','){
				op_union(result, left);
			}
			else{
				if(!left.size())
					left.push_back(string()+expression[pos]);
				else{
					vector<string> right = {string()+expression[pos]};
					left = op_product(left, right);
				}
			}
			++pos;
		}
        op_union(result, left);
        cout << "returning: ";
        print(result);
        return result;
	}
    vector<string> braceExpansionII(string expression) {
        expression = '{' + expression + '}';
        int pos = 0; int n = expression.length();
        auto result = eval(expression, pos, n);
        sort(all(result));
        result.erase(unique(all(result)), result.end());
        return result;
    }
};
int main() {
    Solution sol;
    string expr = "{{a,z},a{b,c},{ab,z}}";
    auto result = sol.braceExpansionII(expr);
    for(auto val: result)
        cout << val << " ";
    cout << endl;
  return 0;
}