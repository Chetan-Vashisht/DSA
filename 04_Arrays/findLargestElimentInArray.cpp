// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {
//     vector<int> v={1,2,5,3,6,4};
//     int le=v[0],sz=v.size()-1;
//     // Brute Foce
//         // Just sort the array/vecotr and than print the last element i.e. v.end()-1
//         //  T.C. is More than best approach
//     // Best Approach
//     for(int i=0;i<sz;i++){
//         if(v[i]>le)le=v[i];
//     }
//     cout<<le<<endl;
    






//     return 0;
// }




#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    // find Largest 
    // vector<int> v={1,2,4,2,6,7,19,8};
    // int size=v.size(),le=v[0];
    // for(int i=0;i<size;i++){
    //     if(v[i]>le)le=v[i];
    // }
    // cout<<le<<endl;

    // find Second Largest
    vector<int> v={1,2,3,5,8,19,299,783};
    int sz=v.size(),le=v[0],sle=v[0];
    for(int i=0;i<sz;i++){
        if(v[i]>le)le=v[i];
    }
    cout<<le<<endl;
    for(int i=0;i<sz;i++){
        if(v[i]>sle && v[i]<le)sle=v[i];
    }
    cout<<sle<<endl;


    // find largest and than second largest 
    // vector<int> v={2,3,5,34,2,242345,88};
    // int le=v[0],sle=v[0];
    // for (auto  i:v){
    //     if(i>le)le=i;
    // }
    // for(int i:v) if(i>sle && i<le)sle=i;

    // cout<<le<<" "<<sle<<endl;

    return 0;
}