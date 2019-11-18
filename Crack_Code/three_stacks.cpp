// Cracking the coding interview Q - 3.1
// using it with the parent pointers for 3 hierarchy
#include <bits/stdc++.h>
using namespace std;

class KStack
{
	vector<int> next;
	vector<int> top;
	int free;
	vector<int> store;
public:
	KStack(int k, int n){
		store.reserve(n);
		for(int i = 0; i< k; i++){
            top.push_back(-1);
		}
		for(int i = 0; i < n; i++){
			if(i == n-1){
				next.push_back(-1); 		// end of storage
			}
			next.push_back(i+1);
		}
		free = 0;
	}
	void push(int val, int sn){
		if(free == -1){
			cout << "Stack Overflow" << endl;
			return;
		}
		int pos = free;
		free = next[free];
		store[pos] = val;
		next[pos] = top[sn-1];
		top[sn-1] = pos;
	}
	int pop(int sn){
		if(top[sn-1] == -1){
			cout << "Stack Underflow" << endl;
			return -1;
		}
		int curr = top[sn-1];
		top[sn-1] = next[curr]; //set to parent
		next[curr] = free;
		free = curr;
		return store[curr];
	}
};

int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    KStack ks(k, n);

    ks.push(15, 3);
    ks.push(45, 3);

    ks.push(17, 2);
    ks.push(49, 2);
    ks.push(39, 2);
    
    ks.push(11, 1);
    ks.push(9, 1);
    ks.push(7, 1);

    cout << "Popped element from stack 3 is " << ks.pop(3) << endl;
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;

    return 0;
}
