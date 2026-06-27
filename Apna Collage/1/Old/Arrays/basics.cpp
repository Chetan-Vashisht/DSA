#include <iostream>
using namespace std;

int main()
{
    // creating a simple array without fillint it
    // int arr[10];
    // now storing marks as well
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // size of array
    int size =10;
    int newArr[10] = {2, 4, 6, 8};
    // indexing for 0 to size-1
    cout << arr[3];


    // to find size of array
    cout << sizeof(arr)<<endl; // as 10*4
    
    // print all element of arr using loop
    for (int i = 0; i <size;i++){
        cout<<arr[i]<<' ';
    }
    // input  element in arr using loop
    // for (int i = 0; i <size;i++){
    //     cin>>arr[i]<<endl;
    // }



    return 0;
}