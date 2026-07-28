#include <iostream>
using namespace std;
int min(int a, int b)
{
    if (a < b)
    {
        cout << "b is greater than a";
    }
    else
    {
        cout << "a is greater than b";
    }
}
void printSumFrom1ToN(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
}
int factorial(int n)
{
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
int nCr(int n, int r)
{
    int f_n = factorial(n);
    int f_r = factorial(r);
    int f_nmr = factorial(n - r);
    return f_n / (f_r * f_nmr);
}
int isPrime(int n)
{
    if (n <= 1)
    {
        cout << "Number is not prime";
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void printPrime(int n)
{
    for (int i = 2; i < n; i++)
    {

        if (isPrime(i))
        {
            cout << i;
        }
    }
}
int febunachi(int n)
{
    int t1 = 0, t2 = 1, t3;
    for (int i = 2; i < n; i++)
    {
        // cout<<t1<<" ";
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
        // cout<<t3<<" ";
    }
    return t2;
}

int main()

{
    cout << febunachi(10);
    return 0;
}