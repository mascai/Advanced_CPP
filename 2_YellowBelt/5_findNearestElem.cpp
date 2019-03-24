#include <bits/stdc++.h>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {

    auto firs_not_less = lower_bound(begin(numbers), end(numbers), border);
    if (begin(numbers) == firs_not_less) {
        return firs_not_less;
    }
    auto less = prev(firs_not_less);
    if (firs_not_less == end(numbers)) {
        return less;
    }
    bool f = (*firs_not_less - border) < (border - *less);
    return f ? firs_not_less : less;
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
