#include <iostream>
#include <climits>
using namespace std;
void reverseArray(int arr[],int sz){
    int j=sz-1;
    int i =0;
    while(<sz){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    
    

}

int main() {
    int arr[]= {1,2,3,4,5,6,7};
    int sz = 7;
    // for (int i = 0; i < sz; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    reverseArray(arr,sz);
    for (int i = 0; i < sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
}