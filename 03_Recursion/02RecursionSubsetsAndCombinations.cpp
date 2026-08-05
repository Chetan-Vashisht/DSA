#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
===============================================================================
             RECURSION MODULE 2: SUBSETS, COMBINATIONS & DIVIDE-AND-CONQUER
===============================================================================
Key Concepts Covered in this Module:
1. Divide & Conquer Recursion (Recursive Binary Search & Merge Sort)
2. The Pick / Non-Pick Pattern (Generating all subsequences / subsets)
3. Target Sum Subsets (Printing subsets and counting subsets with target sum)
4. Combination Sum I (Unlimited choice / element reuse)
5. Combination Sum II (Handling duplicates with unique subset generation)
===============================================================================
*/

// ============================================================================
// 1. DIVIDE & CONQUER: RECURSIVE BINARY SEARCH & MERGE SORT
// ============================================================================

// Binary Search (Recursive)
// Divide search space into half at each step.
// Time Complexity:  O(log N)
// Space Complexity: O(log N) due to recursive call stack
int recursiveBinarySearch(const vector<int>& arr, int low, int high, int target) {
    // Base Case: Element not found
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] > target) {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
    return recursiveBinarySearch(arr, mid + 1, high, target);
}

// Merge function for Merge Sort
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge elements in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    // Copy remaining left half elements
    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    // Copy remaining right half elements
    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    // Transfer temp array back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Merge Sort (Recursive Divide & Conquer)
// Time Complexity:  O(N log N) in all cases (Best, Average, Worst)
// Space Complexity: O(N) temporary array + O(log N) call stack
void mergeSort(vector<int>& arr, int low, int high) {
    // Base Case: Sub-array of length 1 or 0 is already sorted
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    // Recursive divide steps
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Conquer / Combine step
    merge(arr, low, mid, high);
}


// ============================================================================
// 2. GENERATING ALL SUBSEQUENCES / SUBSETS (PICK / NON-PICK PATTERN)
// ============================================================================
// At each index, we have 2 choices:
//   Choice 1: Include (Pick) current character/element
//   Choice 2: Exclude (Non-pick) current character/element
//
// Total subsequences for array/string of length N = 2^N
// Time Complexity:  O(2^N)
// Space Complexity: O(N) stack depth
void generateSubsequences(int index, string& current, const string& str, vector<string>& result) {
    // Base Case: Processed all characters
    if (index == str.length()) {
        result.push_back(current);
        return;
    }

    // Pick / Include current character
    current.push_back(str[index]);
    generateSubsequences(index + 1, current, str, result);

    // Non-pick / Exclude current character (Backtrack state)
    current.pop_back();
    generateSubsequences(index + 1, current, str, result);
}


// ============================================================================
// 3. SUBSETS WITH TARGET SUM (PRINTING & COUNTING)
// ============================================================================

// Print all subsets whose sum equals target
void printSubsetsWithSum(int index, vector<int>& current, int currentSum, int target, const vector<int>& arr) {
    // Base Case
    if (index == arr.size()) {
        if (currentSum == target) {
            cout << "{ ";
            for (int num : current) cout << num << " ";
            cout << "} ";
        }
        return;
    }

    // Option 1: Pick current element
    current.push_back(arr[index]);
    printSubsetsWithSum(index + 1, current, currentSum + arr[index], target, arr);

    // Option 2: Non-pick current element (Backtrack)
    current.pop_back();
    printSubsetsWithSum(index + 1, current, currentSum, target, arr);
}

// Count number of subsets whose sum equals target (Functional recursion pattern)
int countSubsetsWithSum(int index, int currentSum, int target, const vector<int>& arr) {
    // Base Case: Array exhausted
    if (index == arr.size()) {
        return (currentSum == target) ? 1 : 0;
    }

    // Count when picking current element
    int pickCount = countSubsetsWithSum(index + 1, currentSum + arr[index], target, arr);

    // Count when excluding current element
    int nonPickCount = countSubsetsWithSum(index + 1, currentSum, target, arr);

    return pickCount + nonPickCount;
}


// ============================================================================
// 4. COMBINATION SUM I (UNLIMITED ELEMENT REUSE)
// ============================================================================
// Find all unique combinations where candidate numbers sum to target.
// Each number may be chosen unlimited times.
void combinationSum1(int index, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    // Base Case
    if (index == candidates.size()) {
        if (target == 0) {
            result.push_back(current);
        }
        return;
    }

    // Choice 1: Pick the element (stay at same index if candidate <= target)
    if (candidates[index] <= target) {
        current.push_back(candidates[index]);
        combinationSum1(index, target - candidates[index], candidates, current, result);
        current.pop_back(); // Backtrack
    }

    // Choice 2: Skip to next element
    combinationSum1(index + 1, target, candidates, current, result);
}


// ============================================================================
// 5. COMBINATION SUM II (HANDLING DUPLICATES / UNIQUE COMBINATIONS)
// ============================================================================
// Input may contain duplicates, but each number can only be used ONCE per combination.
// Result must contain no duplicate combinations.
// Strategy: Sort candidates first, and skip duplicates in loop branching.
void combinationSum2(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        // Skip duplicate elements at same depth level to avoid duplicate combinations
        if (i > index && candidates[i] == candidates[i - 1]) continue;

        // If candidate exceeds remaining target, remaining elements also exceed (since sorted)
        if (candidates[i] > target) break;

        current.push_back(candidates[i]);
        combinationSum2(i + 1, target - candidates[i], candidates, current, result);
        current.pop_back(); // Backtrack
    }
}


// ============================================================================
// MAIN FUNCTION - DEMONSTRATIONS & TESTS
// ============================================================================
int main() {
    cout << "====================================================\n";
    cout << "  DSA RECURSION MODULE 2: SUBSETS & COMBINATIONS   \n";
    cout << "====================================================\n\n";

    // 1. Divide & Conquer: Binary Search & Merge Sort
    cout << "--- 1. Divide & Conquer (Binary Search & Merge Sort) ---\n";
    vector<int> unsortedArr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original Array: ";
    for (int x : unsortedArr) cout << x << " ";
    cout << endl;

    mergeSort(unsortedArr, 0, unsortedArr.size() - 1);
    cout << "Sorted Array (Merge Sort): ";
    for (int x : unsortedArr) cout << x << " ";
    cout << "\n";

    int targetVal = 27;
    int foundIdx = recursiveBinarySearch(unsortedArr, 0, unsortedArr.size() - 1, targetVal);
    cout << "Recursive Binary Search for " << targetVal << " -> Found at index: " << foundIdx << "\n\n";

    // 2. Subsequences Generation
    cout << "--- 2. Subsequence Generation (Pick / Non-Pick) ---\n";
    string inputStr = "abc";
    string currentStr = "";
    vector<string> allSubsequences;
    generateSubsequences(0, currentStr, inputStr, allSubsequences);
    cout << "All Subsequences of \"" << inputStr << "\" (" << allSubsequences.size() << " total):\n";
    for (const string& s : allSubsequences) {
        cout << "\"" << s << "\" ";
    }
    cout << "\n\n";

    // 3. Subsets with Target Sum
    cout << "--- 3. Subsets with Target Sum ---\n";
    vector<int> nums = {1, 2, 1, 3};
    int targetSum = 3;
    vector<int> currSubset;
    cout << "Subsets of {1, 2, 1, 3} with sum = " << targetSum << ": ";
    printSubsetsWithSum(0, currSubset, 0, targetSum, nums);
    cout << "\nTotal Count of Subsets with sum = " << targetSum << " is: "
         << countSubsetsWithSum(0, 0, targetSum, nums) << "\n\n";

    // 4. Combination Sum I
    cout << "--- 4. Combination Sum I (Unlimited Reuse) ---\n";
    vector<int> candidates1 = {2, 3, 6, 7};
    int comboTarget1 = 7;
    vector<int> comboCurr1;
    vector<vector<int>> comboAns1;
    combinationSum1(0, comboTarget1, candidates1, comboCurr1, comboAns1);
    cout << "Combinations summing to " << comboTarget1 << " using {2, 3, 6, 7}:\n";
    for (const auto& vec : comboAns1) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "] ";
    }
    cout << "\n\n";

    // 5. Combination Sum II
    cout << "--- 5. Combination Sum II (Unique / Duplicate Handling) ---\n";
    vector<int> candidates2 = {10, 1, 2, 7, 6, 1, 5};
    int comboTarget2 = 8;
    sort(candidates2.begin(), candidates2.end()); // Essential sorting
    vector<int> comboCurr2;
    vector<vector<int>> comboAns2;
    combinationSum2(0, comboTarget2, candidates2, comboCurr2, comboAns2);
    cout << "Unique Combinations summing to " << comboTarget2 << " from {10, 1, 2, 7, 6, 1, 5}:\n";
    for (const auto& vec : comboAns2) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "] ";
    }
    cout << "\n\n";

    cout << "====================================================\n";
    return 0;
}
