#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Factorial using Recursion
int Factorial(int n)
{
    if (n == 0)
        return 1;
    return n * Factorial(n - 1);
}
int calculateFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}
int main()
{

    // Factorial using Loop
    // int n=5, Factorial=1;
    // for (int i = n; i >0; i--)
    // {
    //     Factorial*=i;
    // }
    // cout<<Factorial<<endl;

    int n = 5;
    // cout<<Factorial(n)<<endl;
    cout << calculateFactorial(n);

    return 0;
}