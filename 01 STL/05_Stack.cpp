// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// int main() {
//     stack<int> st;
//     st.push(1);
//     st.push(2);
//     st.emplace(3);
//     st.emplace(4);
//     cout<<st.top();
//     cout<<st.size();
//     st.pop();
//     cout<<st.empty();
//     return 0;
// }
#include <iostream>
#include <stack>

using namespace std;

int main() {

    // 🔹 1. Declaration & Initialization
    stack<int> st; // Creates an empty stack of integers

    // -------------------------------------------------------------

    // 📥 2. Insertion Operations
    st.push(1);       // Stack: [1] (bottom: 1, top: 1)
    st.push(2);       // Stack: [1, 2]
    
    // ⚡ emplace constructs elements directly in-place (more efficient than push)
    st.emplace(3);    // Stack: [1, 2, 3]
    st.emplace(4);    // Stack: [1, 2, 3, 4] (top is 4)

    // -------------------------------------------------------------

    // 🔍 3. Accessing Top Element
    // ⚠️ Note: Never call top() on an empty stack (leads to undefined behavior)
    cout << "Top element: " << st.top() << endl; // Outputs: 4

    // -------------------------------------------------------------₹`

    // 📏 4. Capacity Operations
    cout << "Size of stack: " << st.size() << endl; // Outputs: 4
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl; // Outputs: No

    // -------------------------------------------------------------

    // 📤 5. Deletion Operations
    st.pop(); // Removes top element (4) -> Stack: [1, 2, 3]
    cout << "New top element after pop: " << st.top() << endl; // Outputs: 3

    // -------------------------------------------------------------

    // 🔄 6. Swapping Stacks
    stack<int> st2;
    st2.push(100);
    st2.push(200);

    st.swap(st2); // Exchanging contents between st and st2
    cout << "New top of st after swap: " << st.top() << endl; // Outputs: 200

    // -------------------------------------------------------------

    // 🔁 7. Traversing and Clearing a Stack
    // ⚠️ Note: std::stack DOES NOT support standard iterators (no begin()/end())
    // To print/empty all elements, process them top-to-bottom:
    cout << "Printing and clearing st: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop(); // Remove processed top element
    }
    cout << endl;

    return 0;
}
