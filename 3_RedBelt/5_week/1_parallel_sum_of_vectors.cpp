/*
g++ -std=c++11 -pthread main.cpp -o res.bin
*/
#include "test_runner.h"

#include <bits/stdc++.h>
#include <future>

using namespace std;


int sumTwoVectors(const vector<int>& one, const vector<int>& two) {
    future<int> f = async([&] {
        return accumulate(begin(one), end(one), 0);
    });
    int result = accumulate(begin(two), end(two), 0);
    return  result + f.get();
}

int main() {
    cout << sumTwoVectors({1, 1, 1, 1}, {3, 3, 3}) << endl;
}
