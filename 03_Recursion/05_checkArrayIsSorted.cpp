#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isSorted(int n , vector<int> v){
    if(n==0||n==1)return true;
    if(v[n-1]>=v[n-1]) return true;
    
}

int main() {
   
    vector<int> vec={1,2,3,4,5};
    int sz = vec.size();

    cout<<isSorted(sz,vec);






    return 0;
}