#include <iostream>
using namespace std;

int main()
{

    // now square with continue number
    // 123
    // 456
    // 789

    int n = 3;
    int num = 1;
    // if we put it in inner loop than it will reset every time loop end but if it is in outer loop than it will follow in continuous manner

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
    // Character Verson
    // char ch = 'A';

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ch;
    //         ch++;
    //     }
    //     cout << endl;
    // }

    return 0;
}