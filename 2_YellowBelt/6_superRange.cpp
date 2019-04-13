/*
https://www.coursera.org/learn/c-plus-plus-red/lecture/p0EYh/avtomatichieskii-vyvod-tipa-vozvrashchaiemogho-funktsiiei
*/

#include "bits/stdc++.h"

#define forn(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

template<class T>
struct IterRange {
    T first;
    T last;
    T begin() const{
        return first;
    }
    T end() const {
        return last;
    }
};

// порождающая функция, преимущество - не нужно писать тип при инстанциировании
template<class T>
IterRange<T> makeRange(T begin, T end) {
    return IterRange<T>{begin, end};
}

template<class Container>
IterRange<class Container::iterator> Head(Container& v, size_t n) {
    return {v.begin(), next(v.begin(), min(n, v.size()))};
}

int main() {
    vector<int> v{1, 2, 4, 5, 6, 7};
    for (int i : Head(v, 3)) {
        cout << i << ' ';
    }
    cout << "\nSECOND HALF: ";
    auto secondHalf = makeRange(v.begin() + v.size() / 2, v.end());
    for (auto i : secondHalf) {
        cout << i << ' ';
    }
    cout << "\nPRINT SET: ";
    set<float> mSet{1, 2, 4};
    for (float x: Head(mSet, 2)) {
        cout << x << ' ';
    }
}


