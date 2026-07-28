// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// int main() {
//     queue<int> q;
//     q.push(1);
//     q.push(011);
//     q.push(99);
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     return 0;
// }
#include <iostream>
#include <queue>

using namespace std;

int main() {

    // 🔹 1. Declaration & Initialization
    queue<int> q; // Creates an empty queue of integers

    // -------------------------------------------------------------

    // 📥 2. Insertion Operations
    q.push(1);       // Queue: [1] (front: 1, back: 1)
    
    // ⚠️ Note: Leading 0 denotes OCTAL notation in C++! 
    // 011 in octal = (1 * 8^1) + (1 * 8^0) = 9 in decimal.
    q.push(011);     // Queue: [1, 9] (front: 1, back: 9)
    
    q.push(99);      // Queue: [1, 9, 99] (front: 1, back: 99)

    // ⚡ emplace constructs elements directly in-place at the back (more efficient)
    q.emplace(150);  // Queue: [1, 9, 99, 150]

    // -------------------------------------------------------------

    // 🔍 3. Accessing Front and Back Elements
    // ⚠️ Note: Never call front() or back() on an empty queue (leads to undefined behavior)
    cout << "Front element: " << q.front() << endl; // Outputs: 1
    cout << "Back element:  " << q.back() << endl;  // Outputs: 150

    // -------------------------------------------------------------

    // 📤 4. Deletion Operations
    q.pop(); // Removes front element (1) -> Queue: [9, 99, 150]
    cout << "New front after pop: " << q.front() << endl; // Outputs: 9

    // -------------------------------------------------------------

    // 📏 5. Capacity Operations
    cout << "Size of queue: " << q.size() << endl; // Outputs: 3
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl; // Outputs: No

    // -------------------------------------------------------------

    // 🔄 6. Swapping Queues
    queue<int> q2;
    q2.push(500);
    q2.push(600);

    q.swap(q2); // Exchanging contents between q and q2
    cout << "New front of q after swap: " << q.front() << endl; // Outputs: 500

    // -------------------------------------------------------------

    // 🔁 7. Traversing and Clearing a Queue
    // ⚠️ Note: std::queue DOES NOT support iterators (no begin()/end())
    // To print/empty all elements, process them front-to-back:
    cout << "Printing and clearing q: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); // Remove processed front element
    }
    cout << endl;

    return 0;
}
