#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <memory>

using namespace std;

class FileDeleter {
private:
    string name_;
public:
    FileDeleter(const string& name) : name_(name) {};
    void operator()(ofstream* fp) {
        delete fp;
        remove(name_.data());
    }
};

int main() {
    shared_ptr<ofstream> fp(new ofstream("tmp.txt"),
                            FileDeleter("tmp.txt"));
    *fp << "hello";
    return 0;
}
