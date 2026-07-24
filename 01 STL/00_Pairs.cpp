
// #include <bits/stdc++.h>
// #include <utility> // library used to use pairs
// using namespace std;
// int main() {
//     // simple pair
//     pair<int, int> p = {1, 2};
//     cout << "p.first: " << p.first << '\n';
//     cout << "p.second: " << p.second << "\n\n";

//     // nested pair 
//     pair<int, pair<int, int>> np = {1, {2, 3}};
//     cout << "np.first: " << np.first << '\n';
//     cout << "np.second.first: " << np.second.first << '\n';
//     cout << "np.second.second: " << np.second.second << "\n\n";

//     // array of pairs
//     pair<int, int> arr[] = {{1, 2}, {3, 4}};
//     cout << "arr[0].first: " << arr[0].first << "  arr[0].second: " << arr[0].second << '\n';
//     cout << "arr[1].first: " << arr[1].first << "  arr[1].second: " << arr[1].second << '\n';
//     return 0;
// }
#include <iostream>
#include <utility>   // Required for std::pair and std::make_pair
#include <algorithm> // Required for std::sort
#include <vector>

using namespace std;

int main() {

    // 🔹 1. Simple Pair (Declaration & Initialization)
    pair<int, int> p1 = {1, 2};            // Initializer list syntax
    pair<int, string> p2(10, "Chetan");   // Direct initialization
    pair<int, double> p3 = make_pair(5, 3.14); // Using make_pair helper function

    // Accessing elements
    cout << "p1.first: " << p1.first << '\n';   // Output: 1
    cout << "p1.second: " << p1.second << "\n\n"; // Output: 2

    // -------------------------------------------------------------

    // 🔹 2. Nested Pair (Storing more than 2 elements)
    pair<int, pair<int, int>> np = {1, {2, 3}};

    cout << "np.first: " << np.first << '\n';               // Output: 1
    cout << "np.second.first: " << np.second.first << '\n';   // Output: 2
    cout << "np.second.second: " << np.second.second << "\n\n"; // Output: 3

    // -------------------------------------------------------------

    // 🔹 3. Array of Pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << "arr[0].first: " << arr[0].first << "  arr[0].second: " << arr[0].second << '\n';
    cout << "arr[1].first: " << arr[1].first << "  arr[1].second: " << arr[1].second << "\n\n";

    // -------------------------------------------------------------

    // 🔹 4. Comparison Operations
    // Pairs are compared lexicographically: first element primary, second element secondary.
    pair<int, int> a = {1, 5};
    pair<int, int> b = {1, 10};

    cout << "Is a < b? " << (a < b ? "True" : "False") << "\n\n"; // Output: True (1==1, but 5 < 10)

    // -------------------------------------------------------------

    // 🔹 5. Sorting Array/Vector of Pairs
    vector<pair<int, int>> vec = {{3, 10}, {1, 20}, {1, 5}};
    
    // Sorts automatically by .first in ascending order; if .first is equal, sorts by .second
    sort(vec.begin(), vec.end());

    cout << "Sorted Vector of Pairs:\n";
    for (auto p : vec) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << "\n\n"; // Output: {1, 5} {1, 20} {3, 10}

    // -------------------------------------------------------------

    // 🔹 6. Swapping Pairs
    pair<int, int> pA = {10, 20};
    pair<int, int> pB = {30, 40};
    
    pA.swap(pB); // Swaps values of pA and pB
    cout << "pA after swap: {" << pA.first << ", " << pA.second << "}\n"; // Output: {30, 40}

    return 0;
}

