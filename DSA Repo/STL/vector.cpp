#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    // Example: empty vector of ints
    // push_back: add a value to the end (copy)
    // emplace_back: build the value at the end (can be faster)
    vector<int> v;
    v.push_back(2);    // v = {2}
    v.emplace_back(5); // v = {2, 5}
    // Access by index (0-based). operator[] does not check bounds.
    cout << v[0] << v[1]; // Output: 25
    cout << endl;

    // Vector of pairs stores (a,b) items
    // push_back: give a pair
    // emplace_back: pass values to create the pair directly
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});  // pushes a pair constructed from initializer list
    vec.emplace_back(3, 4); // constructs pair<int,int>(3,4) directly in-place
    // Access pair members with .first and .second
    cout << vec[0].first << endl;  // 1
    cout << vec[0].second << endl; // 2
    cout << vec[1].first << endl;  // 3
    cout << vec[1].second << endl; // 4

    // Make vectors with size or a default value
    // vct(5): five zeros
    // vctr(5,10): five elements all = 10
    vector<int> vct(5);
    vector<int> vctr(5, 10);
    cout << vctr[0] << vctr[2]; // Output: 1010
    cout << endl;

    // Example of initializer-lists
    // v1 = {1,2}
    // v2 = v1 copies v1 into v2 (clear and simple)
    vector<int> v1 = {1, 2};
    vector<int> v2 = v1; // copy v1 into v2
    // printing v2[1] prints the second element of the copied vector
    cout << v2[1]; // Output: 2
    cout << endl;

    // Iterators act like pointers to elements
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v3.begin(); // points to first element (1)
    cout << *(it);                         // *it == 1
    cout << *(it + 3);                     // it+3 -> 4th element (4)
    // Output of the two prints above (no space): 14

    // end() points next to the last item
    vector<int>::iterator ite = v3.end();
    // Unsafe: do NOT dereference ite (it is past-the-end)
    // To print the last element safely use end()-1 or back()
    cout << *(ite - 1); // Output: 5 (last element)
    cout << endl;
    cout << v3.back(); // Output: 5 (same as above)

    vector<int> ve = {1, 2, 3, 4, 5};
    for (vector<int>::iterator it = ve.begin(); it != ve.end(); it++) {
        cout << *(it) << " ";
    }
    
    for (auto it = ve.begin(); it != ve.end(); it++) {
        cout << *(it) << " ";
    }
    for (int a : ve) {
        cout << a;
    }
    for (auto it : ve) {
        cout << it << " ";
    }
    // Outputs from the loops above (in order):
    // 1 2 3 4 5 
    // 1 2 3 4 5 
    // 12345
    // 1 2 3 4 5 
    cout << endl;
    ve.erase(ve.begin());
    // erase removes element at position; here remove first element
    cout<<ve[0]; // Output after erase: 2 (new first element)
    ve.erase(ve.begin(), ve.begin() + 3);
    // erase range: removes first three elements (from begin to begin+3)
    for (auto it : ve) {
        cout << it << " "; // print remaining elements (e.g. 5 )
    }
    cout << endl;

    vector<int> vtr(2, 10);
    vtr.insert(vtr.begin(), 300);
    vtr.insert(vtr.begin() + 1, 2, 500);
    for (auto it : vtr) {
        cout << it << " ";
    }
    cout << endl; // Output: 300 500 500 10 10 

    cout << vtr.size() << endl; // Output: 5
    vtr.pop_back();
    for (auto it : vtr) {
        cout << it << " ";
    }
    cout << endl; // Output after pop_back: 300 500 500 10 

    vector<int> v10 = {1, 2}, v20 = {3, 4};
    for (auto it : v10) {
        cout << it << " ";
    }
    for (auto it : v20) {
        cout << it << " ";
    }
    cout << endl; // Output: 1 2 3 4 
    // swap contents of v10 and v20 so their values are exchanged
    v10.swap(v20); // now v10 has {3,4} and v20 has {1,2}
    for (auto it : v10) {
        cout << it << " "; // prints swapped v10
    }
    for (auto it : v20) {
        cout << it << " "; // prints swapped v20
    }
    // Output after swap: 3 4 1 2 

    return 0;
}