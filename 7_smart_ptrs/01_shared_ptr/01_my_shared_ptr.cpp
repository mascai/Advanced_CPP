#include <bits/stdc++.h>


using namespace std;


template<typename T>
class my_shared_ptr {
public:
    my_shared_ptr() {}

    explicit my_shared_ptr(T* raw_ptr) {
        ptr_ = raw_ptr;
        counter_ = new int(1);
    }

    my_shared_ptr(std::nullptr_t ) {
        ptr_ = nullptr;
        counter_ = nullptr;
    }

    my_shared_ptr(const my_shared_ptr& other) {
        ptr_ = other.ptr_;
        counter_ = other.counter_;

        if (counter_) {
            *counter_ += 1;
        }
    }

    my_shared_ptr(my_shared_ptr&& other) :
        ptr_(std::exchange(other.ptr_, nullptr)),
        counter_(std::exchange(other.counter_, nullptr))
    {}

    my_shared_ptr& operator=(const my_shared_ptr& other) {
        my_shared_ptr temp(other);
        temp.swap(*this);
        return *this;
    }

    my_shared_ptr& operator=(my_shared_ptr&& other) {
        my_shared_ptr temp(std::move(other));
        temp.swap(*this);
        return *this;
    }

    ~my_shared_ptr() {
        if (counter_ and decrement_counter()) {
            delete counter_;
            delete ptr_;
        }
    }

    int use_count() const {
        if (counter_) {
            return *counter_;
        }
        return 0;
    }
private:
    bool decrement_counter() {
        *counter_ -= 1;
        return *counter_ == 0;
    }

    void swap(my_shared_ptr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(counter_, other.counter_);
    }

    friend void swap(my_shared_ptr& l, my_shared_ptr& r) {
        l.swap(r);
    }

private:
    T* ptr_ = nullptr;
    int* counter_ = nullptr;
};

template<typename T, typename... Args>
my_shared_ptr<T> make_my_shared(Args&&... args) {
    auto res = new T(std::forward<Args>(args)...);
    return my_shared_ptr<T>(res);
}

struct A {
    A(int a) { 
        cout << "A(" << a << ")\n";
        a_ = a;
    }
    ~A() { cout << "~A(" << a_ << ")\n";}

    int a_;
};

int main() {
    
    my_shared_ptr<A> a1(new A(1));
    my_shared_ptr<A> a2 = make_my_shared<A>(2);
    my_shared_ptr<A> a3;

    cout << "Log1: " << a2.use_count() << endl;
    a1 = a2;
    cout << "Log2: " << a2.use_count() << endl;
    a3 = a2;
    cout << "Log3: " << a2.use_count() << endl;

    /*
    A(1)
    A(2)
    Log1: 1
    ~A(1)
    Log2: 2
    Log3: 3
    ~A(2)
    */

    return 0;
}
