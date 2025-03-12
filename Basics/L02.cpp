#include <iostream>
using namespace std;

int main() {
    //sum form 1 to n which are divisible by 3
    int i=1, n, sum=0;
    cout<<"Enter n :";
    cin>>n;

    for(i=1;i<=n;i++){
        if(i%3==0){
            sum+=i;
        }
    }
    cout<<sum;

    // factorial
    int j=1, m, factorial=1;
    cout<<"Enter n :";
    cin>>m;
    for ( j = 1;j <=m; i++)
    {
        factorial*=i;
    }
    cout<<factorial;
    
    
    return 0;
}