#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n=10;
    // for (int i = 0; i < n/2; i++)
    // {
    //     for(int j=0;j<n/2-i;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<i*2;j++){
    //         cout<<"-";
    //     }
    //     for(int j=0;j<n/2-i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    for (int i = 0; i < n/2; i++)
    {
        for(int j=0;j<=i;j++)cout<<"*";
        for(int j=0;j<=n-i;j++)cout<<"-";
        for(int j=0;j<=i;j++)cout<<"*";
        cout<<endl;
    }
    
    
    
    return 0;
}