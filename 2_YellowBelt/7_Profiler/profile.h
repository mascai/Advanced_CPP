#pragma once

#include "bits/stdc++.h"
#include <chrono>

#define forn(i, n) for (int i = 0; i < (n); ++i)

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define LOG_DURATION(msg) \
    LogDuration UNIQ_ID(__LINE__){msg};

using namespace std;
using namespace std::chrono;

class LogDuration {
    string msg_;
    steady_clock::time_point start_;
public:
    explicit LogDuration(const string& msg = "") : start_(steady_clock::now()), msg_(msg + ": ") {};
    ~LogDuration() {
        auto finish = steady_clock::now();
        auto diff = finish - start_;
        cerr << msg_ << duration_cast<milliseconds>(diff).count() << " ms" << endl;
    }
};
