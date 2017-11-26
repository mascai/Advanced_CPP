/*
    Return the sum of the squares of integers
    from 1 to N for any nonnegative integer constant value of N.
*/

#include <bits/stdc++.h>

using namespace std;

template <int N>
struct Fun {
    enum {
        res = Fun<N - 1>::res + N * N
    };
};

template<>
struct Fun<1> {
    enum {
        res = 1
    };
};

int main () {
     cout << Fun<10>::res << endl;
     return 0;
}
