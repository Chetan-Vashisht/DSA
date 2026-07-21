#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    // Example: empty vector of ints
    // push_back: add a value to the end (copy)
    // emplace_back: build the value at the end (can be faster)
    vector<int> v;
    v.push_back(2);       // v = {2}
    v.emplace_back(5);    // v = {2, 5}
    // Access by index (0-based). operator[] does not check bounds.
    cout << v[0] << v[1]; // prints both values next to each other, e.g. 25
    cout << endl;

    // Vector of pairs stores (a,b) items
    // push_back: give a pair
    // emplace_back: pass values to create the pair directly
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});    // pushes a pair constructed from initializer list
    vec.emplace_back(3, 4);   // constructs pair<int,int>(3,4) directly in-place
    // Access pair members with .first and .second
    cout << vec[0].first<<endl;   // 1
    cout << vec[0].second<<endl;  // 2
    cout << vec[1].first<<endl;   // 3
    cout << vec[1].second<<endl;  // 4

    // Make vectors with size or a default value
    // vct(5): five zeros
    // vctr(5,10): five elements all = 10
    vector<int> vct(5);
    vector<int> vctr(5,10);
    cout<<vctr[0]<<vctr[2]; // prints: 1010 (two elements)
    cout<<endl;
    
    // Example of initializer-lists
    // v1 = {1,2}
    // v2 = {v1} is confusing and not a usual copy — avoid this pattern
    vector<int> v1={1,2};
    vector<int> v2={v1};
    // printing v2[1] may not do what you expect here
    cout<<v2[1];
    cout<<endl;


    // Iterators act like pointers to elements
    vector<int> v3={1,2,3,4,5};
    vector<int>::iterator it=v3.begin(); // points to first element (1)
    cout<<*(it);        // *it == 1
    cout<<*(it+3);      // it+3 -> 4th element (4)
    cout<<endl;
    
    // end() points past the last item — do NOT dereference it
    vector<int>::iterator ite=v3.end();
    // Unsafe: cout<<*(ite) is undefined behavior and may crash
    cout<<*(ite) << " ";
    cout<<*(ite-1); // safe: element before end() is the last element
    cout<<endl;
    cout<<v3.back(); // safe: gets the last element

    return 0;
}