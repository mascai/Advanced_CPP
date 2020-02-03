
#include <bits/stdc++.h>

using namespace std;

template<class T>
class Table {
    vector<vector<T>> data_;
public:
    Table(size_t rows, size_t cols) {
        resize(rows, cols);
    }

    void resize(size_t rows, size_t cols) {
        data_.resize(rows);
        for (auto& row : data_) {
            row.resize(cols);
        }
    }

    vector<T>& operator[] (size_t id) {
        return data_[id];
    }

    const vector<T>& operator[] (size_t id) const {
        return data_[id];
    }

    pair<size_t, size_t> Size() const {
        return {data_.size(), data_.empty() ? 0 : data_[0].size()};
    }
};

int main() {
    Table<int> t(3, 0);
    cout << t.Size().first << ' ' << t.Size().second << endl;

}
