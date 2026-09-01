#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    vector<int> v={1,2,5,3,6,4};
    int le=v[0],sz=v.size()-1;
    // Brute Foce
        // Just sort the array/vecotr and than print the last element i.e. v.end()-1
        //  T.C. is More than best approach
    // Best Approach
    for(int i=0;i<sz;i++){
        if(v[i]>le)le=v[i];
    }
    cout<<le<<endl;
    






    return 0;
}