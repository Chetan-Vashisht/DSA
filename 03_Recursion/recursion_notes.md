# Recursion in Data Structures and Algorithms (DSA) with C++

Recursion is a fundamental concept in computer science and programming, particularly in the context of data structures and algorithms (DSA). It involves a function calling itself to solve smaller instances of the same problem. This technique is particularly useful for problems that can be broken down into simpler, similar subproblems.

## Key Concepts of Recursion

1. **Base Case**: The condition under which the recursion stops. It prevents infinite recursion and is essential for the function to return a value.
2. **Recursive Case**: The part of the function where the recursion occurs. It typically involves calling the function itself with modified arguments.
3. **Stack Overflow**: A common issue with recursion, occurring when the recursion depth exceeds the call stack limit. This can happen if the base case is not defined correctly or if the recursion goes too deep.

## Examples of Recursion in C++

### Factorial Calculation

The factorial of a non-negative integer $n$ is the product of all positive integers less than or equal to $n$. It can be defined recursively as:

- $factorial(n) = n \times factorial(n - 1)$ for $n > 0$
- $factorial(0) = 1$ (base case)

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) // Base case
        return 1;
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
```

### Fibonacci Sequence

The Fibonacci sequence is another classic example of recursion. Each number in the sequence is the sum of the two preceding ones:

- $F(n) = F(n - 1) + F(n - 2)$ for $n > 1$
- $F(0) = 0$, $F(1) = 1$ (base cases)

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) // Base case
        return 0;
    if (n == 1) // Base case
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int num = 6;
    cout << "Fibonacci of " << num << " is " << fibonacci(num) << endl;
    return 0;
}
```

### Tower of Hanoi

The Tower of Hanoi is a classic problem that illustrates recursion. The objective is to move a stack of disks from one peg to another, following specific rules.

1. Move $n-1$ disks from the source peg to the auxiliary peg.
2. Move the nth disk to the destination peg.
3. Move the $n-1$ disks from the auxiliary peg to the destination peg.

```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) { // Base case
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination); // Recursive case
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source); // Recursive case
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
```

## Advantages of Recursion

- **Simplicity**: Recursive solutions can be more straightforward and easier to understand than their iterative counterparts.
- **Problem Decomposition**: Recursion naturally breaks problems into smaller subproblems, making it easier to solve complex issues.

## Disadvantages of Recursion

- **Performance**: Recursive solutions can be less efficient due to the overhead of multiple function calls and increased memory usage.
- **Stack Overflow**: Deep recursion can lead to stack overflow errors if the recursion depth exceeds the stack limit.

## Conclusion

Recursion is a powerful tool in C++ for solving problems in data structures and algorithms. Understanding how to implement and optimize recursive functions is essential for any programmer. By mastering recursion, you can tackle a wide range of problems more effectively.
