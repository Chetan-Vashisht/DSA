// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {

//     priority_queue<int> maxHeap;
//     maxHeap.push(2);
//     maxHeap.push(5);
//     maxHeap.push(210);
//     maxHeap.push(500);

//     while (!maxHeap.empty())
//     {
//         cout<<maxHeap.top()<<endl;
//         maxHeap.pop();
//     }
    
//     priority_queue<int,vector<int>,greater<int>> minHeap;
    
//     minHeap.push(500);
//     minHeap.push(100);
//     minHeap.push(50);
//     minHeap.push(5);

//     while(!minHeap.empty()){
//         cout<<minHeap.top()<<endl;
//         minHeap.pop();
//     }

//     return 0;
// }
#include <iostream>
#include <queue>      // Required for priority_queue
#include <vector>
#include <functional> // Required for std::greater

using namespace std;

int main() {

    // 🔹 1. Max Heap (Default Behavior)
    // Elements are stored such that the largest element is always on TOP.
    priority_queue<int> maxHeap;

    // 📥 Insertion Operations
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(210);
    
    // ⚡ emplace constructs elements directly in-place
    maxHeap.emplace(500); // Priority Queue: top is 500

    // 🔍 Accessing Top Element
    cout << "Max Heap Top: " << maxHeap.top() << endl; // Outputs: 500

    // 📏 Capacity Operations
    cout << "Size of Max Heap: " << maxHeap.size() << endl; // Outputs: 4

    // 🔁 Traversing and Printing Max Heap (Outputs: 500, 210, 5, 2)
    cout << "Max Heap Elements (Descending Order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop(); // Removes top-most (largest) element
    }
    cout << "\n\n";

    // -------------------------------------------------------------

    // 🔹 2. Min Heap (Custom Comparator)
    // Syntax: priority_queue<Type, Container, Comparator>
    // Using std::greater<int> keeps the smallest element on TOP.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(500);
    minHeap.push(100);
    minHeap.push(50);
    minHeap.push(5);

    // 🔍 Accessing Top Element
    cout << "Min Heap Top: " << minHeap.top() << endl; // Outputs: 5

    // 🔁 Traversing and Printing Min Heap (Outputs: 5, 50, 100, 500)
    cout << "Min Heap Elements (Ascending Order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop(); // Removes top-most (smallest) element
    }
    cout << "\n\n";

    // -------------------------------------------------------------

    // 🔄 3. Swapping Priority Queues
    priority_queue<int> pq1, pq2;
    pq1.push(10);
    pq1.push(20);
    
    pq2.push(100);

    pq1.swap(pq2); // Exchanging contents between pq1 and pq2
    cout << "pq1 top after swap: " << pq1.top() << endl; // Outputs: 100

    return 0;
}
