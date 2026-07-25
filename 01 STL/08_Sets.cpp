// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {
//     set<int> st;
//     st.insert(1);
//     st.insert(2);
//     st.insert(2);
//     st.emplace(3);

//     for(auto it:st)cout<<it<<endl;
//     auto it=st.find(1);
//     cout<<*(it)<<endl;
//     auto ite=st.find(6);
//     cout<<*(ite)<<endl;
//     int cnt =st.count(2);
//     cout<<cnt<<endl;
//     st.erase(3);
//     for(auto it:st)cout<<it<<endl;
    
// // Multi set
//     cout<<"Multiset"<<endl;
//     multiset<int> mst;

//     mst.insert(1);
//     mst.insert(1);
//     mst.insert(1);
//     mst.insert(1);
//     mst.insert(2);
//     mst.insert(2);
//     for(auto it1:mst)cout<<it1<<endl;
//     mst.erase(1);
//     cout<<"After Erasing 1"<<endl;
//     for(auto it2:mst)cout<<it2<<endl;




// // Unordered Set
//     cout<<"Unordered Set"<<endl;
//     unordered_set<int> ust;
//     ust.insert(1);
//     ust.insert(1);
//     ust.insert(2);
//     ust.insert(10);
//     ust.insert(19);
//     ust.emplace(1239);

//     for(auto te:ust)cout<<te<<endl;
    
    
//     return 0;
// }
#include <iostream>
#include <set>           // Required for std::set and std::multiset
#include <unordered_set> // Required for std::unordered_set

using namespace std;

int main() {

    // =============================================================
    // 🔹 1. std::set (Sorted & Unique)
    // - Elements are unique and stored in strictly ascending order.
    // - Implemented using Balanced BST (Red-Black Tree).
    // - Time Complexity: O(log N) for insert, erase, and search.
    // =============================================================
    
    cout << "--- 1. std::set ---" << endl;
    set<int> st;

    // 📥 Insertion Operations
    st.insert(1);       // Set: {1}
    st.insert(2);       // Set: {1, 2}
    st.insert(2);       // Ignored! (Duplicates not allowed) -> Set: {1, 2}
    st.emplace(3);      // Set: {1, 2, 3}

    // 🔍 Iterating through std::set
    cout << "Elements in set: ";
    for (auto val : st) cout << val << " ";
    cout << endl; // Output: 1 2 3

    // 🔍 Search Operations (find & count)
    auto it = st.find(1);
    if (it != st.end()) {
        cout << "Found 1: " << *(it) << endl;
    }

    // ⚠️ CRITICAL: De-referencing end() iterator (like finding non-existing element 6)
    // is UNDEFINED BEHAVIOR! Always check `it != st.end()` before printing!
    auto ite = st.find(6);
    if (ite == st.end()) {
        cout << "Element 6 not found in set!" << endl;
    }

    // count(val) returns 1 if element exists, 0 if not
    int cnt = st.count(2); 
    cout << "Count of 2 in set: " << cnt << endl; // Output: 1

    // 📤 Erasure Operations
    st.erase(3); // Erases element with value 3 directly -> Set: {1, 2}
    
    // Erase via iterator
    // auto it_erase = st.find(2);
    // st.erase(it_erase);

    // 📍 Lower & Upper Bounds (Unique to ordered set)
    // lower_bound(x) -> iterator to first element >= x
    // upper_bound(x) -> iterator to first element > x
    st.insert(10);
    st.insert(20);
    cout << "Lower bound of 10: " << *st.lower_bound(10) << endl; // 10
    cout << "Upper bound of 10: " << *st.upper_bound(10) << endl; // 20

    cout << endl;

    // =============================================================
    // 🔹 2. std::multiset (Sorted & Duplicates Allowed)
    // - Elements are stored in strictly ascending order.
    // - Allows duplicate elements!
    // - Time Complexity: O(log N) for insert, erase, and search.
    // =============================================================

    cout << "--- 2. std::multiset ---" << endl;
    multiset<int> mst;

    mst.insert(1);
    mst.insert(1);
    mst.insert(1);
    mst.insert(1);
    mst.insert(2);
    mst.insert(2);

    cout << "Multiset elements: ";
    for (auto it1 : mst) cout << it1 << " ";
    cout << endl; // Output: 1 1 1 1 2 2

    // ⚠️ IMPORTANT: mst.erase(val) erases ALL instances of val!
    mst.erase(1); 
    cout << "After erasing value 1 (all instances): ";
    for (auto it2 : mst) cout << it2 << " ";
    cout << endl; // Output: 2 2

    // 💡 To erase ONLY A SINGLE instance of a duplicate element:
    mst.insert(5);
    mst.insert(5);
    mst.insert(5); // Multiset: {2, 2, 5, 5, 5}
    
    mst.erase(mst.find(5)); // Erases only the FIRST instance of 5

    cout << "After erasing single instance of 5: ";
    for (auto val : mst) cout << val << " ";
    cout << "\n\n";

    // =============================================================
    // 🔹 3. std::unordered_set (Unordered & Unique)
    // - Elements are unique, but stored in NO particular order.
    // - Implemented using Hash Tables.
    // - Time Complexity: Average O(1), Worst case O(N) due to hash collisions.
    // =============================================================

    cout << "--- 3. std::unordered_set ---" << endl;
    unordered_set<int> ust;

    ust.insert(1);
    ust.insert(1); // Ignored!
    ust.insert(2);
    ust.insert(10);
    ust.insert(19);
    ust.emplace(1239);

    cout << "Unordered Set elements: ";
    for (auto te : ust) cout << te << " ";
    cout << endl; // Output: Elements printed in randomized order

    return 0;
}
