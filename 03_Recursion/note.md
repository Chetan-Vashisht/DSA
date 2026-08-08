
# Recursion Notes (DSA)

## Code Modules in this Directory

1. [01RecursionBasics.cpp](file:///Users/chetan/Developer/DSA/03_Recursion/01RecursionBasics.cpp) - Order of Execution, Factorial, Fibonacci, Sum of N numbers, Fast Exponentiation, Two-Pointer Reversing & Palindromes.
2. [02RecursionSubsetsAndCombinations.cpp](file:///Users/chetan/Developer/DSA/03_Recursion/02RecursionSubsetsAndCombinations.cpp) - Divide & Conquer (Binary Search & Merge Sort), Subsequences (Pick / Non-Pick), Target Sum Subsets, Combination Sum I & II.
3. [03RecursionBacktracking.cpp](file:///Users/chetan/Developer/DSA/03_Recursion/03RecursionBacktracking.cpp) - Permutations (Visited & In-place Swapping), N-Queens with O(1) Hash diagonals, Rat in a Maze, Generate Parentheses, Sudoku Solver.

## Topic Goal

Master recursion so you can confidently solve recursion, backtracking, tree, and DP foundation problems.

Recommended effort:

- Duration: 3 to 4 days
- Daily time: 1 to 3 hours
- Difficulty: Medium

## What Is Recursion?

A function calling itself on a smaller input until it reaches a stopping condition.

A correct recursive function always has:

1. Base case: when recursion stops
2. Recursive case: how problem gets smaller

If base case is missing or unreachable, recursion keeps going and causes stack overflow.

## Core Concepts You Must Cover

### 1) Base Case

Stopping condition (example: factorial(0) = 1).

### 2) Recursive Case

Function calls itself with smaller input (example: factorial(n) = n * factorial(n - 1)).

### 3) Call Stack

Every recursive call gets its own stack frame with local variables.

### 4) Call Tree

Visual tree of all recursive calls. Draw this first to avoid bugs.

### 5) Return Flow

Results return from deepest call (base case) back to the original call.

### 6) Single vs Multiple Recursive Branches

- Single branch example: factorial
- Multiple branch example: fibonacci (much slower due to repeated work)

### 7) Tail Recursion

Recursive call is the last operation in function. Sometimes compiler can optimize this.

## Golden Rules Before Coding

1. Write base case first.
2. Define exactly how input gets smaller.
3. Ensure recursion moves toward base case every call.
4. Draw call tree for one sample input.
5. Estimate time + space complexity.

## Standard Recursion Template (C++)

```cpp
ReturnType solve(InputType input) {
    // 1) Base case
    if (base_condition) {
        return base_value;
    }

    // 2) Work before recursive call (optional)

    // 3) Recursive call on smaller input
    ReturnType smallAns = solve(smaller_input);

    // 4) Work after recursive call (optional)
    return combine(current_input, smallAns);
}
```

## Dry Run Example: factorial(4)

Call order:

- factorial(4)
- factorial(3)
- factorial(2)
- factorial(1)
- factorial(0) -> 1

Return order:

- factorial(1) = 1 * 1 = 1
- factorial(2) = 2 * 1 = 2
- factorial(3) = 3 * 2 = 6
- factorial(4) = 4 * 6 = 24

## Complexity Intuition

- If each call makes 1 recursive call and reduces input by 1: usually O(n)
- If each call makes 2 recursive calls: often exponential (like fibonacci O(2^n))
- Recursive stack space is usually equal to recursion depth

## Must-Know Problems To Cover

### 1) Factorial

- Focus: base case + return bubbling
- Expected complexity: O(n) time, O(n) stack

### 2) Fibonacci (naive recursion)

- Focus: repeated subproblems and why it is slow
- Expected complexity: O(2^n) time, O(n) stack depth
- Important: run for n = 40 to feel the slowdown

### 3) Print 1 to n (recursion only)

- Focus: recursion order (before/after recursive call)

## Concept Questions With Answers

### Q1. What is a base case and what happens if you forget it?

Base case is the stop condition where function returns without further recursive calls. Without it (or if never reached), recursion becomes infinite and causes stack overflow.

### Q2. Draw call stack for factorial(4) and return values.

Calls go 4 -> 3 -> 2 -> 1 -> 0.
Then returns: 1, 2, 6, 24 while unwinding.

### Q3. Why is naive recursive fibonacci so bad?

Because it recomputes the same subproblems many times. Branching factor is about 2, so time becomes exponential O(2^n).

### Q4. How does call stack differ between factorial and fibonacci?

Factorial has one chain of calls (linear tree). Fibonacci creates two branches at most nodes (branching tree), causing many more calls.

### Q5. How to convert recursion to iteration generally?

Identify recursive state, then simulate it using:

- loop + variables (for simple recursion), or
- explicit stack data structure (for complex recursion/backtracking)

## Common Mistakes and Fixes

1. Missing base case

- Fix: write and test base case first

2. Wrong smaller input

- Fix: ensure each call moves closer to base case

3. Wrong return combination

- Fix: verify how child result contributes to parent result

4. Printing in wrong place

- Fix: print before recursive call for preorder-like behavior, after for postorder-like behavior

5. Ignoring complexity

- Fix: count total calls from call tree, and stack depth separately

## Before Moving On Checklist

You should be able to do all of these without help:

- Trace any recursive function on paper
- Identify base case and recursive case in any recursion code
- Explain why missing base case causes infinite recursion
- Implement factorial and print 1 to n recursively from memory
- Explain why naive fibonacci is exponential

## Stretch (Good to Have)

- Convert a simple recursive function into iterative using explicit stack
- Compare recursion vs memoized recursion for fibonacci

## Practice Set (LeetCode / Similar)

1. Factorial (basic recursion)
2. Fibonacci Number
3. Print N to 1 and 1 to N (recursion only)
4. Power function (fast exponentiation recursion)
5. Climbing Stairs (compare recursion and DP)

## Quick Revision Box

- Recursion = base case + smaller subproblem
- Always move toward base case
- Draw call tree before coding
- Analyze both time and stack space
- Naive branching recursion often explodes exponentially
