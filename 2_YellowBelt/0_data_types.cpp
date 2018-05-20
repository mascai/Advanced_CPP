#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main() {
    int x;
    cout << sizeof(int) << endl; // 4
    cout << sizeof(x) << endl;   // 4
    cout << sizeof(int64_t) << endl; // 8
    cout << numeric_limits<int>::min() << ' '
         << numeric_limits<int>::max() << endl;
    // Overflow examples
    cout << numeric_limits<int>::max() + 1 << endl; // -2147...
    cout << numeric_limits<int>::min() - 1 << endl; // +2147..

    // casting
    int8_t a = 2, b = 3;
    cout << sizeof(a * b) << endl; // int8_t * int8_t --> int
    cout << sizeof(static_cast<int>(a)) << endl; // int8_t --> int
    return 0;
}
