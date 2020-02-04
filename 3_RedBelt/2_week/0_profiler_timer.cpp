#include <vector>
#include <iostream>
#include <iterator>
#include <chrono>

using namespace std;
using namespace std::chrono;


class LogDuration {
public:
    explicit LogDuration(const string& msg = "") : start(steady_clock::now()), msg_(msg + ": ") {}

    ~LogDuration() {
        auto diff = steady_clock::now() - start;
        cerr << msg_ << duration_cast<milliseconds>(diff).count() << " ms" << endl;
    }
private:
    steady_clock::time_point start;
    string msg_;
};

int main() {
    LogDuration ob("Timer name");
    vector<int> v;
    for (int i = 1; i < 10000; ++i) {
        v.insert(begin(v), i);
    }

}
