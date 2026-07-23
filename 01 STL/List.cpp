#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  list<int> ls = {1, 2};
  ls.push_front(5);
  ls.emplace_front(70);
  cout<<"HI";
  for (auto it : ls) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
˳