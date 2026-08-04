#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
===============================================================================
                     RECURSION BASICS - COMPREHENSIVE GUIDE
===============================================================================
What is Recursion?
A function calling itself directly or indirectly to solve a smaller instance 
of the same problem until a stopping condition (Base Case) is met.

Every Correct Recursive Function Requires:
1. Base Case: The condition where recursion stops (prevents stack overflow).
2. Recursive Case: The breakdown of the problem into smaller sub-problems, 
   moving toward the base case.
===============================================================================
*/

// ============================================================================
// 1. PRINT N TO 1 & PRINT 1 TO N (ORDER OF EXECUTION)
// ============================================================================

// Pre-order processing: Work is done BEFORE the recursive call.
// Call sequence: printNto1(5) -> prints 5 -> printNto1(4) -> ... -> prints 1
void printNto1(int n) {
    // Base Case
    if (n == 0) return;

    // Work done before recursive call
    cout << n << " ";

    // Recursive Call (towards base case)
    printNto1(n - 1);
}

// Post-order processing: Work is done AFTER the recursive call unwinds.
// Call sequence goes down to 0, and as stack unwinds, printing occurs 1, 2, ..., N.
void print1toN(int n) {
    // Base Case
    if (n == 0) return;

    // Recursive Call first
    print1toN(n - 1);

    // Work done after recursive call unwinds
    cout << n << " ";
}


// ============================================================================
// 2. FACTORIAL (SINGLE BRANCH RECURSION)
// ============================================================================
// Mathematical Definition:
// n! = n * (n - 1)! for n > 0
// 0! = 1
//
// Time Complexity:  O(N) -> N recursive calls
// Space Complexity: O(N) -> Call stack depth of N
long long factorial(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive Case: combine current input with result of subproblem
    return n * factorial(n - 1);
}


// ============================================================================
// 3. SUM OF FIRST N NATURAL NUMBERS
// ============================================================================

// Approach A: Functional Recursion (returns result)
// Time: O(N), Space: O(N)
int sumFunctional(int n) {
    if (n == 0) return 0;
    return n + sumFunctional(n - 1);
}

// Approach B: Parameterized Recursion (accumulates result in parameter)
// Time: O(N), Space: O(N)
void sumParameterized(int n, int currentSum) {
    if (n == 0) {
        cout << "Sum (Parameterized): " << currentSum << endl;
        return;
    }
    sumParameterized(n - 1, currentSum + n);
}


// ============================================================================
// 4. FIBONACCI NUMBER (MULTIPLE BRANCH RECURSION)
// ============================================================================
// Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
// fib(0) = 0, fib(1) = 1
// fib(n) = fib(n - 1) + fib(n - 2)
//
// Time Complexity:  O(2^N) (Exponential due to overlapping subproblems)
// Space Complexity: O(N)   (Max height of the call tree / call stack depth)
int fibonacci(int n) {
    // Base Cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // Multiple branching calls
    return fibonacci(n - 1) + fibonacci(n - 2);
}


// ============================================================================
// 5. POWER FUNCTION (EXPONENTIATION)
// ============================================================================

// Naive Linear Power: a^b = a * a^(b-1)
// Time: O(b), Space: O(b)
double powerLinear(double a, int b) {
    if (b == 0) return 1;
    if (b < 0) return 1.0 / powerLinear(a, -b);
    return a * powerLinear(a, b - 1);
}

// Fast Exponentiation (Binary Exponentiation)
// If b is even: a^b = (a^(b/2))^2
// If b is odd:  a^b = a * (a^(b/2))^2
// Time: O(log b), Space: O(log b)
double powerFast(double a, long long b) {
    if (b == 0) return 1.0;
    if (b < 0) return 1.0 / powerFast(a, -b);

    double half = powerFast(a, b / 2);
    if (b % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}


// ============================================================================
// 6. REVERSE AN ARRAY / STRING (TWO POINTER RECURSION)
// ============================================================================
void reverseArray(vector<int>& arr, int left, int right) {
    // Base Case: when pointers cross or meet
    if (left >= right) return;

    // Swap elements at left and right indices
    swap(arr[left], arr[right]);

    // Recursive step moving inward
    reverseArray(arr, left + 1, right - 1);
}


// ============================================================================
// 7. PALINDROME CHECK (RECURSIVE)
// ============================================================================
bool isPalindrome(const string& str, int left, int right) {
    // Base Case: pointers crossed without mismatches
    if (left >= right) return true;

    // Character mismatch found
    if (str[left] != str[right]) return false;

    // Recursive call for inner substring
    return isPalindrome(str, left + 1, right - 1);
}


// ============================================================================
// MAIN FUNCTION - DEMONSTRATIONS & TESTS
// ============================================================================
int main() {
    cout << "====================================================\n";
    cout << "           DSA RECURSION BASICS MODULE              \n";
    cout << "====================================================\n\n";

    // 1. Order of Execution
    cout << "--- 1. Order of Execution ---\n";
    cout << "Print 5 to 1 (Pre-order / Work before call): ";
    printNto1(5);
    cout << "\nPrint 1 to 5 (Post-order / Work after call): ";
    print1toN(5);
    cout << "\n\n";

    // 2. Factorial
    cout << "--- 2. Factorial ---\n";
    int nFactorial = 6;
    cout << "Factorial of " << nFactorial << " = " << factorial(nFactorial) << "\n\n";

    // 3. Sum of N numbers
    cout << "--- 3. Sum of First N Numbers ---\n";
    int nSum = 10;
    cout << "Sum (Functional) of 1 to " << nSum << " = " << sumFunctional(nSum) << endl;
    sumParameterized(nSum, 0);
    cout << "\n";

    // 4. Fibonacci
    cout << "--- 4. Fibonacci Numbers ---\n";
    int fibTerms = 8;
    cout << "First " << fibTerms << " Fibonacci numbers: ";
    for (int i = 0; i < fibTerms; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << "\n\n";

    // 5. Fast Exponentiation vs Linear
    cout << "--- 5. Power Function (Fast Exponentiation) ---\n";
    double base = 2.0;
    int exp = 10;
    cout << base << "^" << exp << " (Linear): " << powerLinear(base, exp) << endl;
    cout << base << "^" << exp << " (Fast O(log N)): " << powerFast(base, exp) << "\n\n";

    // 6. Reverse Array
    cout << "--- 6. Reverse Array ---\n";
    vector<int> numbers = {10, 20, 30, 40, 50};
    cout << "Original Array: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    reverseArray(numbers, 0, numbers.size() - 1);
    cout << "Reversed Array: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n\n";

    // 7. Palindrome Check
    cout << "--- 7. Palindrome Check ---\n";
    string s1 = "racecar";
    string s2 = "recursion";
    cout << "\"" << s1 << "\" is palindrome? " << (isPalindrome(s1, 0, s1.length() - 1) ? "Yes" : "No") << endl;
    cout << "\"" << s2 << "\" is palindrome? " << (isPalindrome(s2, 0, s2.length() - 1) ? "Yes" : "No") << endl;

    cout << "\n====================================================\n";
    return 0;
}
