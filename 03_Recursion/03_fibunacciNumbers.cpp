#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int Fibunacci(int n);


int main() {
    int n=5 , fn=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            fn+=i+j;
        }
        
    }
    cout<<fn<<endl;






    return 0;
}