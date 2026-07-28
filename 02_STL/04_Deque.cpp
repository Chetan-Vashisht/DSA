// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {

//     deque<int> dq;
//     dq.push_front(1);
//     dq.push_front(12);
//     dq.emplace_front(48);
//     dq.pop_front();
//     dq.pop_back();
//     cout<<dq.back();
//     cout<<dq.front();

//     // for(auto it:dq)cout<<it<<endl;
//     return 0;
// }
#include <iostream>
#include <deque>
#include <algorithm> // Required for std::sort and std::reverse

using namespace std;

int main() {

    // 🔹 1. Declaration & Initialization
    deque<int> dq;               // Empty deque
    deque<int> dq2(5, 10);       // Creates: [10, 10, 10, 10, 10]
    deque<int> dq3 = {1, 2, 3};  // Initializer list setup

    // -------------------------------------------------------------

    // 📥 2. Insertion Operations
    dq.push_front(1);       // Deque: [1]
    dq.push_front(12);      // Deque: [12, 1]
    dq.push_back(100);      // Deque: [12, 1, 100]
    
    // ⚡ Emplace constructs elements directly in-place (more efficient)
    dq.emplace_front(48);   // Deque: [48, 12, 1, 100]
    dq.emplace_back(200);   // Deque: [48, 12, 1, 100, 200]

    // 📍 Insert at a specific iterator position
    // Inserts 99 at index 2 (position 3) -> Deque: [48, 12, 99, 1, 100, 200]
    dq.insert(dq.begin() + 2, 99); 

    // -------------------------------------------------------------

    // 📤 3. Erasure Operations
    dq.pop_front();  // Removes 48 from front -> Deque: [12, 99, 1, 100, 200]
    dq.pop_back();   // Removes 200 from back -> Deque: [12, 99, 1, 100]

    // 📍 Erase at a specific position
    dq.erase(dq.begin() + 1); // Removes 99 -> Deque: [12, 1, 100]

    // 📍 Erase range: erase(start, end) -> [start, end)
    // dq.erase(dq.begin(), dq.begin() + 2); // Would erase first two elements

    // -------------------------------------------------------------

    // 🔍 4. Accessing Elements
    cout << "Front element: " << dq.front() << endl; // Outputs: 12
    cout << "Back element:  " << dq.back() << endl;  // Outputs: 100
    cout << "At index 1:    " << dq[1] << endl;      // Outputs: 1 (No bounds check)
    cout << "At index 1:    " << dq.at(1) << endl;   // Outputs: 1 (Safe, with bounds check)

    // -------------------------------------------------------------

    // 📏 5. Capacity & Utility Methods
    cout << "Size of deque: " << dq.size() << endl;   // Current element count
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

    // -------------------------------------------------------------

    // 🔁 6. Iteration Methods

    // Standard Range-Based Loop
    cout << "Elements (Range Loop): ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Standard Iterator
    cout << "Elements (Forward Iterator): ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse Iterator
    cout << "Elements (Reverse Iterator): ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // -------------------------------------------------------------

    // ⚙️ 7. Algorithms & Modifications
    sort(dq.begin(), dq.end());    // Sorts elements in ascending order
    reverse(dq.begin(), dq.end()); // Reverses current order

    // -------------------------------------------------------------

    // 🧹 8. Clearing Deque
    dq.clear(); // Removes all elements, size becomes 0
    cout << "Size after clear: " << dq.size() << endl;

    return 0;
}
