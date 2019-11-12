/*You are given a function foo() that represents a biased coin. When foo() is called, it returns 0 with 60% probability,
and 1 with 40% probability. Write a new function that returns 0 and 1 with 50% probability each*/

#include <bits/stdc++.h>
using namespace std;

int foo(){
	//dummy
}

int bar(){
	int x = foo();
	int y = foo();
	if(x^y)
		return x;
	return bar();
}
