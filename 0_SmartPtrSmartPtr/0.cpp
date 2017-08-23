#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class SmartPtr {
private:
    T *p;
public:
    SmartPtr(T *_p): p(_p) {};
    operator T*() { return p;};
    T* operator ->() {
        if (p == nullptr){
            p = new T();
            cout << "ERROR" << endl;
        }
        return p;};
};

class Foo {
private:
    int a, b;
public:
    Foo(int _a = 0, int _b = 0) : a(_a), b(_b) {};
    int Sum() { return a + b;}
};

int main() {
    SmartPtr<Foo>p(new Foo(2, 2));
    SmartPtr<Foo>p_bad(nullptr);
    cout << p->Sum() << endl;
    cout << p_bad->Sum();
}
