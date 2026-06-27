#include <iostream>
using namespace std;

int main()
{
    // 1. Signed Modifier:
    // Can hold both positive and negative values.
    signed int a = -10;
    cout << "Signed int: " << a << endl;

    // 2. Unsigned Modifier:
    // Can hold only positive values.
    unsigned int b = 100;
    cout << "Unsigned int: " << b << endl;

    // 3. Short Modifier:
    // Takes less memory than standard int.
    short int c = 32000;
    cout << "Short int: " << c << endl;

    // 4. Long Modifier:
    // Takes more memory than standard int or double.
    long int d = 100000L;
    cout << "Long int: " << d << endl;

    // 5. Const Modifier:
    // Value cannot be changed after initialization.
    const int e = 42;
    cout << "Const int: " << e << endl;

    // Uncommenting the next line will cause a compile-time error
    // e = 50;

    return 0;
}
