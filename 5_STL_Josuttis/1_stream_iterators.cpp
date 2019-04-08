/*
 *    Input and output container elements    
 *    with stream iterators
 *    
 */

#include "bits/stdc++.h"

using  namespace std;

int main() {
  vector<string> v;
  copy(istream_iterator<string>(cin),
       istream_iterator<string>(),
       back_inserter(v));

  cout << "########################\n";
  sort(begin(v), end(v));
  unique_copy(begin(v), end(v),
              ostream_iterator<string>(cout, "\n"));
  return 0;
}
