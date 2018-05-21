#include <bits/stdc++.h>

using namespace std;

template<class T>
ostream& operator<< (ostream& out, const vector<T>& vec) {
    cout << "[ ";
    for (const auto& item : vec) {
        out << item << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<double>vec1 = {1.23, 11.2, 43.01};
    vector<string>vec2 = {"abc", "xyz", "lol"};
    cout << vec1 << vec2;
    return 0;
}
