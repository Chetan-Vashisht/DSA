#include <iostream>
using namespace std;

int main() {
    int n=8;
    int i;
    bool isPrime=true;
    for ( i = 1; i*i< n; i++)
    {
        isPrime=false;
        break;
    }
    if (isPrime==true)
    {
        cout<<"prime number";
    }
    else{
        cout<<"not prime";
    }
    
    
    return 0;
}