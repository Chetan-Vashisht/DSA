#include <iostream>
using namespace std;

/**
 * Function: isPowerOfTwo
 * ----------------------
 * Checks whether a given number is a power of two.
 *
 * @param n: The integer to check.
 * @return: true if the number is a power of two, false otherwise.
 */
bool isPowerOfTwo(int n)
{
    // A number is a power of 2 if it is greater than 0
    // and has only one '1' bit in its binary representation.
    return (n > 0) && ((n & (n - 1)) == 0);
}

/**
 * Function: reverseNum
 * --------------------
 * Reverses the digits of the given integer.
 *
 * @param num: The integer to reverse.
 * @return: The reversed integer.
 */
int reverseNum(int num)
{
    int newNum = 0; // Initialize the reversed number to 0.

    // Process each digit of the number.
    while (num > 0)
    {
        int n1 = num % 10;         // Extract the last digit of the number.
        newNum = newNum * 10 + n1; // Add the digit to the reversed number.
        num /= 10;                 // Remove the last digit from the number.
    }

    return newNum; // Return the fully reversed number.
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num))
    {
        cout << num << " is a power of 2." << endl;
    }
    else
    {
        cout << num << " is not a power of 2." << endl;
    }

    // Test the reverseNum function with a sample input.
    cout << "Reversed number: " << reverseNum(842) << endl;

    return 0;
}
