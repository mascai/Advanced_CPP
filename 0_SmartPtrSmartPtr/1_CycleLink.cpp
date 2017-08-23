#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class B;

class A {
public:
    shared_ptr<B>b_ptr;
    int val;
    A() {cout << "A" << endl;}
    ~A() {cout << "~A" << endl;}

};

class B {
public:
    weak_ptr<A>a_ptr;
    B() {cout << "B" << endl;}
    ~B() {cout << "~B" << endl;}

};

int main() {
    shared_ptr<A>a (new A());
    shared_ptr<B>b (new B());
    a->b_ptr = b;
    b->a_ptr = a;
    a->val = 123;
    {
        /*
        lock() возвращает указатель на shared_ptr?,
               если он существует, иначе NULL
        Является "ручным" средством борьбы с циклическими ссылками
        */
        shared_ptr<A>aa = b->a_ptr.lock();
        cout << aa->val << endl;

    }
}
