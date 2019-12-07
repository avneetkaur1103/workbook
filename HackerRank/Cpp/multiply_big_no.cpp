#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

class Solution {
public:
    void print(vector<int>& v){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
	vector<int> add(vector<int>& v1, vector<int>& v2){
        cout << "Adding: " << endl;
	    print(v1); print(v2);
		vector<int>& small_vec = v1.size() < v2.size() ? v1 : v2;
		vector<int>& big_vec = v1.size() >= v2.size() ? v1 : v2;
		int carry = 0;
		vector<int> result;
		auto big_vec_itr = big_vec.rbegin();
		auto small_vec_itr = small_vec.rbegin();
		while( small_vec_itr != small_vec.rend()){
            int temp = (*small_vec_itr + *big_vec_itr + carry) % 10;
            carry = (*small_vec_itr + *big_vec_itr + carry) / 10;
            result.push_back(temp);
            small_vec_itr++; big_vec_itr++;
		}
		while(big_vec_itr != big_vec.rend()){
            int temp = (*big_vec_itr + carry) % 10;
            carry = (*big_vec_itr + carry) / 10;
            result.push_back(temp);
            big_vec_itr++;
		}
		if(carry)
            result.push_back(carry);
        reverse(all(result));
        cout << "Result: " << endl;;
        print(result);
        return result;
	}
	vector<int> _multiply(vector<int>& v, int num){
        cout << "Multiplying: " << num << endl;
		int carry = 0;
		vector<int> result;
		transform(v.rbegin(), v.rend(), back_inserter(result), [&carry, &num](auto i){ int temp = (i*num + carry)% 10; carry = (i*num + carry)/10; return temp;});
		if(carry)
            result.push_back(carry);
		reverse(all(result));
		return result;
	}
    string multiply(string num1, string num2) {
        vector<int> a;
        vector<int> b;
        transform(num1.rbegin(), num1.rend(), back_inserter(a), [](char ch){ return ch - '0';});
        transform(num2.rbegin(), num2.rend(), back_inserter(b), [](char ch){ return ch - '0';});
        reverse(all(a)); reverse(all(b));
        vector<int> result;
        int na = a.size(); int nb = b.size();
        for(int i = na-1; i >= 0; i--){
        	vector<int> temp = _multiply(b, pow(10,((na-1)-i))*a[i]);
        	cout << "Debug: " << (na-1)-i << " " << pow(10,((na-1)-i)) << endl;
        	cout << "A[i]: " << a[i] << " B: " << endl;
        	print(b);
        	print(temp);
        	result = add(result, temp);
        	print(result);
        }
    string str;
    ostringstream oss(str);
    copy(all(result), ostream_iterator<int>(oss));
    return oss.str();
    }
};