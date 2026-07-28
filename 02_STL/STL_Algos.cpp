#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort, std::reverse, std::is_sorted, std::next_permutation, std::max_element, std::min_element
#include <utility>   // Required for std::pair
#include <string>

using namespace std;

// 🔹 Custom Comparator Function
// Condition:
// 1. Sort according to the 2nd element in ascending order.
// 2. If the 2nd elements are equal, sort according to the 1st element in DESCENDING order.
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second) 
        return p1.second < p2.second; // Ascending by 2nd element
    return p1.first > p2.first;       // Descending by 1st element
}

int main() {

    // =============================================================
    // 🔹 1. Sorting Standard Vectors & Arrays
    // =============================================================

    vector<int> v = {1, 4, 2, 7, 5};

    // 📈 Ascending Sort (Default)
    sort(v.begin(), v.end()); // v becomes: [1, 2, 4, 5, 7]
    cout << "Ascending Order: ";
    for (auto it : v) cout << it << " ";
    cout << endl;

    // 📉 Descending Sort (Using built-in comparator std::greater<T>())
    sort(v.begin(), v.end(), greater<int>()); // v becomes: [7, 5, 4, 2, 1]
    cout << "Descending Order: ";
    for (auto it : v) cout << it << " ";
    cout << "\n\n";

    // 📍 Sub-range Sorting (Sorting a specific portion)
    vector<int> nums = {10, 50, 20, 40, 30};
    // Sorts only index 1 to 3 ([begin() + 1, begin() + 4)) -> {50, 20, 40}
    sort(nums.begin() + 1, nums.begin() + 4); // nums becomes: [10, 20, 40, 50, 30]

    // =============================================================
    // 🔹 2. Sorting Arrays (Pointers instead of Iterators)
    // =============================================================

    int arr[] = {4, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); // Syntax: sort(start_pointer, end_pointer)

    // =============================================================
    // 🔹 3. Sorting with Custom Comparator
    // =============================================================

    vector<pair<int, int>> p = {{1, 2}, {2, 1}, {4, 1}, {1, 4}};

    // Applying custom comparator
    sort(p.begin(), p.end(), comp);

    cout << "Sorted Pairs (Custom Comparator):\n";
    for (auto itr : p) {
        cout << "{" << itr.first << ", " << itr.second << "}\n";
    }
    cout << endl;

    // =============================================================
    // 🔹 4. Bit Operations (`__builtin_popcount`)
    // =============================================================

    // 💡 Counts the number of set bits (1s) in binary representation
    int a = 6; // Binary of 6: 0110 (two 1s)
    int b = __builtin_popcount(a); // Returns 2
    cout << "Number of set bits (1s) in " << a << " is: " << b << endl;

    // ⚡ For 64-bit integers (`long long`), use `__builtin_popcountll`:
    long long num = 100000000000000LL;
    cout << "Set bits in long long: " << __builtin_popcountll(num) << "\n\n";

    // =============================================================
    // 🔹 5. Permutations (`std::next_permutation` & `prev_permutation`)
    // =============================================================

    string s = "231";
    
    // ⚠️ IMPORTANT: To print ALL lexicographical permutations, 
    // the sequence MUST be sorted in ascending order first!
    sort(s.begin(), s.end()); // s becomes "123"

    cout << "All permutations of string:\n";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    // Output: 123, 132, 213, 231, 312, 321
    
    // 💡 Note: If s is already the last permutation ("321"), 
    // next_permutation() rearranges it back to the first ("123") and returns false.
    cout << endl;

    // =============================================================
    // 🔹 6. Min/Max Elements & Values
    // =============================================================

    vector<int> vtr = {19, 4, 60, 25};

    // 📍 max_element & min_element return ITERATERS (must dereference using *)
    auto maxeli = max_element(vtr.begin(), vtr.end());
    auto mineli = min_element(vtr.begin(), vtr.end());

    cout << "Max element in Vector: " << *maxeli << endl; // Output: 60
    cout << "Min element in Vector: " << *mineli << endl; // Output: 4

    // 💡 Direct Min/Max between variables:
    cout << "Max of 10 & 20: " << max(10, 20) << endl;
    cout << "Min of 10 & 20: " << min(10, 20) << endl;

    // -------------------------------------------------------------

    // =============================================================
    // 🔹 7. Other Essential STL Algorithms
    // =============================================================

    // Check if container is sorted
    bool sorted = is_sorted(vtr.begin(), vtr.end());
    cout << "\nIs vtr sorted? " << (sorted ? "Yes" : "No") << endl;

    // Reverse order
    reverse(vtr.begin(), vtr.end()); // vtr becomes: [25, 60, 4, 19]

    return 0;
}
