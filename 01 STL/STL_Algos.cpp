// #include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// bool comp(pair<int,int>p1,pair<int,int>p2){
//         if(p1.second<p2.second)return true;
//         if(p1.second>p2.second)return false;
//         // if they are same than compair 1st element
//         if(p1.first>p2.first)return true;
//         else return false;
//     }

// int main() {
//     vector<int> v={1,4,2,7,5};
//     // sort funciton
//     auto a=v.begin();
//     // cout<<"vector Befor Sort\n";
//     // for(auto it:v)cout<<it<<" "<<endl;
//     // sort(a,a+5);
//     // cout<<"vector After Sort\n";
//     // for(auto it:v)cout<<it<<" "<<endl;
//     // sort(a,a+5,greater<int>());
//     // cout<<"vector After Sort Descending\n";
//     // for(auto it:v)cout<<it<<" "<<endl;
    
//     // cout<<"vector Befor Sort\n";
//     // for(auto it:v)cout<<it<<" "<<endl;
//     // sort(v.begin(),v.end());
//     // cout<<"vector After Sort\n";
//     // for(auto it:v)cout<<it<<" "<<endl;

//     //Custom comparator
//     // condition:
//         // sort in accoding to 2nd element,
//         // if 2nd element is same than sort in,
//         // according of 1st order but in decreasing order

//     //Using custom comparator 
    
//     vector<pair<int, int>> p = {{1, 2}, {2, 1}, {1, 4}};
//     auto b=p.begin();
//     sort(b,b+3,comp);
//     cout<<"Using custom Comprator\n";
//     for(auto itr:p)cout<<itr.first<<" "<<itr.second<<endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort, std::reverse, std::is_sorted
#include <utility>   // Required for std::pair

using namespace std;

// 🔹 Custom Comparator Function
// Condition:
// 1. Sort according to the 2nd element in ascending order.
// 2. If the 2nd elements are equal, sort according to the 1st element in DESCENDING order.
bool comp(pair<int, int> p1, pair<int, int> p2) {
    // Primary criteria: Compare second elements
    if (p1.second < p2.second) return true;  // p1 comes before p2
    if (p1.second > p2.second) return false; // p2 comes before p1

    // Secondary criteria (when second elements are equal):
    // Higher first element should come first (descending)
    if (p1.first > p2.first) return true;
    return false;
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

    // 📍 Sub-range Sorting (Sorting a specific portion of vector/array)
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
    // Output:
    // {4, 1} -> 2nd elem is 1 (1st elem 4 > 2)
    // {2, 1} -> 2nd elem is 1
    // {1, 2} -> 2nd elem is 2
    // {1, 4} -> 2nd elem is 4
    cout << endl;

    // =============================================================
    // 🔹 4. Useful Algorithms Built on Sorting Concept
    // =============================================================

    // Check if container is sorted
    bool sorted = is_sorted(v.begin(), v.end());
    cout << "Is vector v sorted? " << (sorted ? "Yes" : "No") << endl;

    // Reverse container order
    reverse(v.begin(), v.end());

    return 0;
}
