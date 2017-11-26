/*
    Return the sum of the first N elements of the array
    static constexpr int a[] = {1,5,-3, 4, 6};
*/

#include <bits/stdc++.h>

using namespace std;

static constexpr int a[] = {1,5,-3, 4, 6};

template <int N>
struct ArraySum {
    enum {
        r = ArraySum<N - 1>::r + a[N - 1]
    };
};

template<>
struct ArraySum<1> {
    enum {
        r = a[0]
    };
};

int main () {
     cout << ArraySum<3>::r << endl;
     return 0;
}
