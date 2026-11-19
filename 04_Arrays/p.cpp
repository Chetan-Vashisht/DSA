#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    // find largest in array
    // vector<int> v={1,2,5,3,8,10,4};
    // int j=INT_MIN;
    // for(int i:v){
    //     if(i>=j)j=i;
    // }
    // cout<<j<<endl;
    // T.C.  O(n) and S.C(1)

    // second largest
    vector <int> v={1,4,6,7,2,3,9};
    int le=INT_MIN,sle=INT_MIN;
    // for(int i=0;i<v.size();i++){
    //     if(v[i]>le ) le=v[i];
    // }
    // for(int i=0;i<v.size();i++){
    //     if(v[i]>sle && v[i]<le) sle=v[i];
    // }
    // // cout<<"le: "<<le<<"  sle: "<<sle<<endl;
    
    // optimal approach
    for(int i=0;i<v.size();i++){
        if(v[i]>le){
            sle=le;
            le=v[i];
        }
    }
    cout<<"le: "<<le<<"  sle: "<<sle<<endl;




    return 0;
}