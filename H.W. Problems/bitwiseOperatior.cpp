#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    // Check if n is greater than 0 and satisfies the power-of-2 condition
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of 2." << endl;
    } else {
        cout << num << " is not a power of 2." << endl;
    }

    return 0;
}
