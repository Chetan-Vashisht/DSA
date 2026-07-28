// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {
//   list<int> ls = {1, 2};
//   ls.push_front(5);
//   ls.push_front(50);
//   ls.emplace_front(70);
//   // ls.clear();
//   list<int> l1= ls;
//   l1.push_back(100);
//   for (auto it : l1) {
//     cout << it << " ";
//   }
//   cout << endl;
//   return 0;
// }
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {

    // 🔹 1. Declaration & Initialization
    list<int> ls = {1, 2};        // Initializer list setup
    list<int> ls2(5, 100);        // Creates: [100, 100, 100, 100, 100]
    list<int> l1 = ls;            // Copy list ls into l1 -> l1 = {1, 2}

    // -------------------------------------------------------------

    // 📥 2. Insertion Operations
    ls.push_front(5);      // Add to front -> [5, 1, 2]
    ls.push_front(50);     // Add to front -> [50, 5, 1, 2]
    
    // ⚡ emplace_front constructs directly in memory at the front
    ls.emplace_front(70);  // [70, 50, 5, 1, 2]
    
    ls.push_back(100);     // Add to back  -> [70, 50, 5, 1, 2, 100]
    ls.emplace_back(200);  // Add to back  -> [70, 50, 5, 1, 2, 100, 200]

    // 📍 Insert at specific iterator position
    auto it = ls.begin();
    advance(it, 2);        // Move iterator forward by 2 positions
    ls.insert(it, 99);     // Inserts 99 at index 2

    // -------------------------------------------------------------

    // 📤 3. Deletion Operations
    ls.pop_front();        // Removes front element (70)
    ls.pop_back();         // Removes back element (200)

    // 🎯 Remove by value directly (Unique to std::list!)
    ls.remove(50);         // Finds and removes all instances of value 50

    // -------------------------------------------------------------

    // 🔍 4. Accessing Elements
    // ⚠️ Note: std::list DOES NOT support random access operators like ls[i] or ls.at(i)
    cout << "Front element: " << ls.front() << endl; // 50 (or current front)
    cout << "Back element:  " << ls.back() << endl;  // 100

    // -------------------------------------------------------------

    // 🔁 5. Iteration Methods
    cout << "List Elements: ";
    for (auto val : ls) {
        cout << val << " ";
    }
    cout << "\n\n";

    // -------------------------------------------------------------

    // ⚙️ 6. Built-in Member Algorithms (Faster than std:: algorithms)
    list<int> numbers = {5, 2, 8, 1, 3, 2};

    numbers.sort();        // Sorts list in-place -> [1, 2, 2, 3, 5, 8]
    numbers.unique();      // Removes consecutive duplicates (must be sorted first) -> [1, 2, 3, 5, 8]
    numbers.reverse();     // Reverses order -> [8, 5, 3, 2, 1]

    cout << "Processed Numbers List: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n\n";

    // -------------------------------------------------------------

    // 📏 7. Capacity & Cleaning
    cout << "Size of ls: " << ls.size() << endl;
    cout << "Is ls empty? " << (ls.empty() ? "Yes" : "No") << endl;

    ls.clear();            // Clears all elements, size becomes 0
    cout << "Size after clear: " << ls.size() << endl;

    return 0;
}
