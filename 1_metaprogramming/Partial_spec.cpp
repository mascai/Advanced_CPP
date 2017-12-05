#include <bits/stdc++.h>

using namespace std;

template<class Key, class Val>
class Dict {
    Key* keys;
    Val* vals;
    int sz;
    int max_sz;
public:
    Dict(int _max_sz = 0) {
        sz = 0;
        max_sz = _max_sz;
        keys = new Key[max_sz];
        vals = new Val[max_sz];
    }
    void add(Key key, Val val) {
        if (sz + 1 >= max_sz) {
            max_sz *= 2;
            Key *temp_key = new Key[max_sz];
            Val *temp_val = new Val[max_sz];
            int i;
            for (i = 0; i < sz; i++) {
                temp_key[i] = keys[i];
                temp_val[i] = vals[i];
            }
            temp_key[i] = key;
            temp_val[i] = val;
            delete []keys;
            delete []vals;
            keys = temp_key;
            vals = temp_val;
        } else {
            keys[sz] = key;
            vals[sz] = val;
        }
        ++sz;
        return;
    }
    void print() {
        for (int i = 0; i < sz; i++) {
            cout << keys[i] <<": " << vals[i] << endl;
        }
    }
};

template<class Val>
class Dict<bool, Val> {
    bool* keys;
    Val* vals;
    int sz;
    int max_sz;
public:
    Dict(int _max_sz = 0) {
        sz = 0;
        max_sz = _max_sz;
        keys = new bool[max_sz];
        vals = new Val[max_sz];
    }
    void add(bool key, Val val) {
        if (sz + 1 >= max_sz) {
            max_sz *= 2;
            bool *temp_key = new bool[max_sz];
            Val *temp_val = new Val[max_sz];
            int i;
            for (i = 0; i < sz; i++) {
                temp_key[i] = keys[i];
                temp_val[i] = vals[i];
            }
            temp_key[i] = key;
            temp_val[i] = val;
            delete []keys;
            delete []vals;
            keys = temp_key;
            vals = temp_val;
            delete []temp_key;
            delete []temp_val;
        } else {
            keys[sz] = key;
            vals[sz] = val;
        }
        ++sz;
        return;
    }
    void print() {
        cout << "Partial specialization, output  only true keys:" << endl;
        for (int i = 0; i < sz; i++) {
            if (keys[i]) {
                cout << keys[i] <<": " << vals[i] << endl;
            }
        }
    }
};


int main () {
	Dict<int, int>obj;
	obj.add(1, 2);
	obj.add(5, 6);
	obj.print();
	cout << endl;
	Dict<bool, float>special_obj;
	special_obj.add(true, 2);
	special_obj.add(false, 3);
	special_obj.add(true, 4);
	special_obj.print();
	return 0;
}
