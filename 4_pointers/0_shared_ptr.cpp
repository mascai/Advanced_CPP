#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <memory>

using namespace std;


int main() {
    // два способа создания shared_ptr 
    shared_ptr<string> pNico(new string("nico"),
                             [](string* p) {
                                 cout << "DELETE " <<  *p << endl;
                             });
    shared_ptr<string> pJut = make_shared<string>("jut");

    (*pNico)[0] = 'N';

    vector<shared_ptr<string>> vec;
    vec.push_back(pJut);
    pJut->replace(0, 1, "J");
    vec.push_back(pJut);
    vec.push_back(pNico);
    vec.push_back(pJut);
    vec.push_back(pNico);
    vec.pop_back();

    for (auto ptr : vec) {
        cout << *ptr << endl;
    }
    *pNico = "Nikolay"; // теперь во втором цикле вывод будет Nikolay (поменяли содержимое участка памяти)
    cout << "-------------\n";
    pNico.reset(new string("Alex")); //теперь pNico указывает на другой участок памяти
    for (auto ptr : vec) {
        cout << *ptr << endl;
    }
    cout << "JUT " << vec[0].use_count() << endl;
    cout << "Nico " << vec[2].use_count() << endl;
    
    return 0;
}
