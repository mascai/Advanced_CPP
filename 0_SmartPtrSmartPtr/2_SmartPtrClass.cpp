#include "bits/stdc++.h"

using  namespace std;

template<class T>
class SmartPtr {
private:
    T* ref_;
    unsigned* refCnt_;
public:
    SmartPtr(T* ptr) {
        // initialization of smart pointer
        cout << "Call SmartPtr(T*)" << endl;
        ref_ = ptr;
        refCnt_ = new unsigned(1); // it's pointer because it can be used in different objects of the class
    }
    SmartPtr(const SmartPtr<T>& ptr) {
        cout << "Call SmartPtr(const SmartPtr&)" << endl;
        ref_ = ptr.ref_;
        refCnt_ = refCnt_;
        *refCnt_ += 1; // increase number of owners
    }
    SmartPtr<T>& operator=(SmartPtr<T>& ptr) {
        if (this == &ptr) {
            return *this;
        }
        if (*refCnt_ > 0) {
            remove();
        }
        ref_ = ptr.ref_;
        refCnt_ = ptr.refCnt_;
        ++(*refCnt_);
        return *this;
    }
    ~SmartPtr() {
        cout << "Call ~SmartPtr()" << endl;
        remove();
    }
    void remove() {
        --(*refCnt_);
        if (*refCnt_ == 0) {
            cout << "Delete object" << endl;
            delete ref_;
            delete refCnt_;
            ref_ = nullptr;
            refCnt_ = nullptr;
        }
    }
    T getVal() {
        return *ref_;
    }

};

int main() {
    SmartPtr<int> ptr(new int(5));
    cout << "Create ptr with walue: " << ptr.getVal() << endl;
}


