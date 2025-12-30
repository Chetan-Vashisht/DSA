#include <iostream>
using namespace std;

int main()
{
    /* Print
        1234
        1234
        1234
        1234 */
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    // for * pattern just replace j with "*"

    // A B C
    // int n = 4;
    for (int i = 0; i < n; i++)
    {
        // why declared inside loop ?? => becuause we want it to reset for every line
        char ch = 'A';
        for (int j = 0; j < n; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    return 0;
}