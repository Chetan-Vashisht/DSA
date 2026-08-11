#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int sumOfNNubers(int n)
{
    if (n == 1)
        return 1;
    return n + sumOfNNubers(n - 1);
}

int main()
{

    int n = 5;
    cout << sumOfNNubers(n) << endl;

    

        return 0;
}