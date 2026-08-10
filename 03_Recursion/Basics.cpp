// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// void printNumber(int n){
//     if (n==1)
//     {
//         cout<<n;
//         return;
//     }
//     cout<<n<<endl;
//     return printNumber(n-1);
// }

// int main() {
//     int n=5;
//     printNumber(n);
//     return 0;
// }
#include <iostream>
using namespace std;

// 🔹 Recursive function to print numbers from N down to 1
void printNumber(int n) {
    
    // 🛑 1. Base Case: Stops the recursion when n reaches 1
    if (n == 1) {
        cout << n << endl;
        return; // Exits the function call and starts unwinding the stack
    }

    // 🖨️ 2. Processing Step: Print current value of n
    cout << n << endl;

    // 🔁 3. Recursive Call (Tail Recursion)
    // Calls itself with (n - 1) to move towards the base case
    printNumber(n - 1);
}

int main() {
    int n = 5;

    // 🚀 Calling the recursive function with initial value n = 5
    printNumber(n);

    return 0;
}
