#include "profile.h"


// Реализуйте шаблон класса Paginator


int main() {
    {
        cout << "Start\n";
        LOG_DURATION("input");
        ofstream of("data.txt");
        for (int i = 0; i < 10000; ++i) {
            of << i*i << endl;
        }
        of.close();
    }

    {
        LOG_DURATION("output");
        ifstream f("input.txt");
        for (int i = 0; i < 10000; ++i) {
            string s;
            f >> s;
            //cout << s << endl;
        }
        f.close();
    }
}
