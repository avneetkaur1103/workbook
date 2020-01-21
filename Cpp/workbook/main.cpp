#include <bits/stdc++.h>
using namespace std;

class A{
    public:
    void print(){
        cout << "Hello A" << endl;
    }
};

class B: public A{
    public:
    void print(){
        cout << "Hello B" << endl;
    }
};

int main(){
    B b;
    A* a =  new B();
    a->print();
}
