#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int main() {
    // vector<int>a={1,-2,3,4,-5,8,10,-111};
    // int size = a.size();
    // int currentSum=0,finalSum=INT_MIN;
    // for (int i = 0; i < size; i++)
    // {
    //     currentSum+=a[i];
    //     finalSum=max(currentSum,finalSum);
    //     if (currentSum<0)
    //     {
    //         currentSum=0;
    //     }
        
        
    // }
    // cout<<finalSum;

    // single number 
    vector<int>a={1,2,1,2,90};
    int size=a.size();
    int singleNum=0;
    for(int i=0;i<size;i++){
        singleNum^=a[i];

    }
    cout<<singleNum;
    return 0;
}