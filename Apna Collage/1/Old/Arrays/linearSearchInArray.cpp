#include <iostream>
using namespace std;
//  Linear Search 
int linearSearch(int arr[],int size , int givenValue){
    for (int  i = 0; i < size; i++)
    {
        if (arr[i]==givenValue)
        {
            return i;
        }
        
    }return -1;// -1 means index that dont exist 
    
}

int main() {
    int  arr[]={1, 2, 3, 4, 5};
    int size =5;
    // or ve can use target
    int givenValue =400;
    cout<<linearSearch(arr,size,givenValue);
    
    return 0;
}