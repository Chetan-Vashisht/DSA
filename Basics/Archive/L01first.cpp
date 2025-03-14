#include <iostream>
using namespace std;
int main() {
    // H.W. Problem
    int a, b;
    cout<<"Enter Value of a and b : ";
    cin>>a>>b;
    int sum=a+b;
    int diff=a-b;
    int product=a*b;
    int div=a/b;
    int mod=a%b;
    cout<<"The sum of a and b is : "<<sum<<endl;
    cout<<"The Difference of a and b is : "<<diff<<endl;
    cout<<"The Product of a and b is : "<<product<<endl;
    cout<<"The Division of a and b is : "<<div<<endl;
    cout<<"The Modulus of a and b is : "<<mod<<endl;
    return 0;
}