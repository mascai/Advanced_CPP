#include <bits/stdc++.h>

using namespace std;

vector<int>find_all(const string& s, char ch = ' ') {
    vector<int> ans;
    for (auto it = find(begin(s), end(s), ch);
         it != end(s);
         it = find(next(it), end(s), ch)) {
        cout << it - begin(s) << endl;
        ans.push_back(it - begin(s));
    }
    return ans;
}

int main() {
  auto ans = find_all("01234 67 9 ", ' ');
  // ans = [5, 8, 10]
  return 0;
}
