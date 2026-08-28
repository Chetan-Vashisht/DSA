// // #include <bits/stdc++.h>
// // #include <iostream>
// // using namespace std;

// // /*
// // Notes: Fibonacci using recursion
// // --------------------------------
// // 1) Fibonacci definition:
// //     F(0) = 0, F(1) = 1
// //     F(n) = F(n-1) + F(n-2) for n >= 2

// // 2) Recursion idea:
// //     - Break the problem into two smaller subproblems.
// //     - Keep calling until base cases (0 or 1) are reached.

// // 3) Complexity of this recursive approach:
// //     - Time: O(2^n) (many repeated calls)
// //     - Space: O(n) (recursion call stack depth)

// // 4) Better approach for larger n:
// //     - Use DP (memoization/tabulation) to reduce time to O(n).
// // */
// // // int Fibunacci(int n);
// // // fibunacci using recurison
// // int Fibunacci(int n){
// //      // Base case: return n directly for 0 and 1.
// //     if(n==0||n==1){
// //         return n;
// //     }
// //      // Recursive relation: F(n) = F(n-1) + F(n-2)
// //     return Fibunacci(n-1) + Fibunacci(n-2);
// // }


// // int main() {
// //     // int n=5 , fn=0;
// //     // for (int i = 0; i < n; i++)
// //     // {
// //     //     for (int j = 0; j < i; j++)
// //     //     {
// //     //         fn+=i+j;
// //     //     }
        
// //     // }
// //     // cout<<fn<<endl;

// //     // Example: find 4th Fibonacci number.
// //     int n=4;
// //     cout<<Fibunacci(n)<<endl;


// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// int fibnaci(int n){
//     if(n==0||n==1) return 1;
//     return fibnaci(n-1) + fibnaci(n-2);
// }

// int main() {
//     cout<<fibnaci(3)<<endl;
    






//     return 0;
// }