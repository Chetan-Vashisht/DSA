#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isSorted(vector<int>v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1])return false;
    }
    return true;
}

int main() {

    vector <int>v={2,4,6,5,9,20,1};
    cout<<isSorted(v)<<endl;
    






    return 0;
}