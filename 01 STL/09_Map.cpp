// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {

//     map<int,int>mp;
//     mp[1]=2;
//     mp.insert({3,5});
//     mp.insert({2,4});

//     for(auto itr:mp)cout<<itr.first<<" "<<itr.second<<endl;
//     cout<<endl;
    
    
    
    
//     // MUltimap
//     multimap<int,string> mm;
//     mm.insert({1,"Ram"});
//     mm.insert({2,"Shayam"});
//     mm.insert({1,"Sahil"});
    
//     for(auto it:mm)cout<<it.first<<" "<<it.second<<endl;
//     cout<<endl;
    
    
//     //Unordered Map
//     unordered_map<int,string>um;
//     um.insert({1,"Apple"});
//     um.insert({2,"Samsung"});
//     um.insert({1,"MI"});
//     um.insert({3,"Poco"});
    
//     for(auto ite:um)cout<<ite.first<<" "<<ite.second<<endl;
//     cout<<endl;
//     return 0;
// }
#include <iostream>
#include <map>           // Required for std::map and std::multimap
#include <unordered_map> // Required for std::unordered_map
#include <string>

using namespace std;

int main() {

    // =============================================================
    // 🔹 1. std::map (Sorted & Unique Keys)
    // - Stores key-value pairs sorted in ascending order of KEYS.
    // - Keys are strictly UNIQUE.
    // - Implemented using Balanced BST (Red-Black Tree).
    // - Time Complexity: O(log N) for insertion, lookup, and deletion.
    // =============================================================

    cout << "--- 1. std::map ---" << endl;
    map<int, int> mp;

    // 📥 Insertion Methods
    mp[1] = 2;                  // Bracket syntax (creates key 1 with value 2)
    mp.insert({3, 5});          // Initializer list insertion
    mp.insert(make_pair(2, 4)); // make_pair helper
    mp.emplace(4, 10);          // Constructs pair in-place

    // 🔁 Iterating through std::map (Keys are sorted: 1, 2, 3, 4)
    cout << "Map contents (Key Value):" << endl;
    for (auto itr : mp) {
        cout << itr.first << " -> " << itr.second << endl;
    }
    cout << endl;

    // 🔍 Access & Lookup Operations
    cout << "Value at key 2 (using []): " << mp[2] << endl;   // Outputs: 4
    cout << "Value at key 3 (using at()): " << mp.at(3) << endl; // Outputs: 5

    // ⚠️ Check before accessing non-existent keys!
    // Using mp[100] will accidentally INSERT key 100 with default value 0!
    auto search_it = mp.find(3);
    if (search_it != mp.end()) {
        cout << "Found key 3 with value: " << search_it->second << endl;
    }

    // 📤 Deletion Operations
    mp.erase(4); // Erases key 4 and its mapped value
    cout << endl;

    // =============================================================
    // 🔹 2. std::multimap (Sorted & Duplicate Keys Allowed)
    // - Keys are sorted, but MULTIPLE elements can have the SAME key.
    // - Implemented using Balanced BST.
    // - Time Complexity: O(log N).
    // - ⚠️ Does NOT support operator[] or at()!
    // =============================================================

    cout << "--- 2. std::multimap ---" << endl;
    multimap<int, string> mm;

    mm.insert({1, "Ram"});
    mm.insert({2, "Shayam"});
    mm.insert({1, "Sahil"}); // Duplicate key 1 allowed!

    cout << "Multimap contents:" << endl;
    for (auto it : mm) {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << endl; // Output sorted by key: (1 -> Ram), (1 -> Sahil), (2 -> Shayam)

    // 🔍 Finding range of elements with equal keys
    auto range = mm.equal_range(1); // Returns pair of iterators [lower_bound, upper_bound)
    cout << "All values associated with key 1: ";
    for (auto i = range.first; i != range.second; ++i) {
        cout << i->second << " ";
    }
    cout << "\n\n";

    // =============================================================
    // 🔹 3. std::unordered_map (Unordered & Unique Keys)
    // - Keys are UNIQUE, but stored in NO particular order.
    // - Implemented using Hash Tables.
    // - Time Complexity: Average O(1), Worst case O(N) (due to collisions).
    // =============================================================

    cout << "--- 3. std::unordered_map ---" << endl;
    unordered_map<int, string> um;

    um.insert({1, "Apple"});
    um.insert({2, "Samsung"});
    
    // ⚠️ Standard insert ignores duplicate keys if key 1 already exists!
    um.insert({1, "MI"}); // Ignored! Key 1 remains "Apple"
    
    // 💡 To overwrite an existing key's value, use []:
    // um[1] = "MI"; // This would update key 1 to "MI"

    um.insert({3, "Poco"});

    cout << "Unordered map contents:" << endl;
    for (auto ite : um) {
        cout << ite.first << " -> " << ite.second << endl;
    }
    cout << endl; // Output in randomized hash order

    return 0;
}
