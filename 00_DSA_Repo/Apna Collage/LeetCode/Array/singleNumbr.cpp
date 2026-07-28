#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int>a={1,2,1,2,4};
    int size=a.size();
    
    int result =0;
    for(int i=0;i<size;i++){
        result^=a[i];
    }
    cout<<result;

    return 0;
}   