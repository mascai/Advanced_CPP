#include <bits/stdc++.h>
#include <tuple>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool operator <(const Date &left, const Date &right) {
    tuple<const int&, const int&, const int&>t_right
            = tie(right.year, right.month, right.day);
    auto t_left = tie(left.year, left.month, left.day);
    return t_left < t_right; // embedded tuple comparator
}
/* //simpe comparation
bool operator<(const Date& left, const Date& right) {
    if (left.year != right.year) {
        return left.year < right.year;
    }
    if (left.month != right.month) {
        return left.month < right.month;
    } else {
        return left.day < right.day;
    }
}
*/
int main() {
    Date d1{2018, 01, 18},
         d2{2018, 10, 1};
    cout << (d1 < d2); // true
    return 0;
}
