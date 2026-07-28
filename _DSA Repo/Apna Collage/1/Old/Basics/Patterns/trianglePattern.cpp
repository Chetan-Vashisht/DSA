#include <iostream>
using namespace std;

int main()
{
    /* *
     **
     ***
     ****
     */
    // int n = 4;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << "*";
    //         // for printing numbers like 1 22 333 triangle just replace "*" with i+1 as i will start form 0
    //     }
    //     cout << endl;
    // }

    // int n = 5;
    // char ch = 'A';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << ch;
    //     }
    //     ch++;
    //     cout << endl;
    // }

    /*  Notes:
    FOR PRINTING STAR PATTERN    use I+1 [because i=0 so we need to start i with 1]
    FOR PRINTING STAR PATTERN OF CHARACTERS    use CH+1 above endl because need to update ch after every line
    */

    // int n = 5;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= i + 1; j++)
    //     {
    //         cout << j;
    //     }
    //     // ch++;
    //     cout << endl;
    // }

// reverse pattern
/*    
int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j >0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
        */
// reverse pattern Pattern verson
    int n=5;
    for (int i = 0; i < n; i++)
    {
        char ch='A'+1;
        for ( int j = i; j >=0; j--)
        {
            cout<<ch;
            ch--;
        }
        cout<<endl;
        
    }
    


// Floyds Triangle Pattern
    /*
    int n = 4;
    int num=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j >0; j--)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
    */
// Floyds Triangle Pattern character verson
    /*
    int n=4;
    char ch='A'; 
    for(int i=0; i<n ;i++){
        for(int j=i+1;j>0;j--){
            cout<<ch;
            ch++;
        }
        cout<<endl;

    }
        */
    return 0;
}