#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int Fibunacci(int n);
// fibunacci using recurison
int Fibunacci(int n){
    if(n==0||n==1){
        return n;
    }
    return Fibunacci(n-1) + Fibunacci(n-2);
}


int main() {
    // int n=5 , fn=0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         fn+=i+j;
    //     }
        
    // }
    // cout<<fn<<endl;
    int n=4;
    cout<<Fibunacci(n)<<endl;






    return 0;
}