#include <iostream>
#include<climits>
#include <vector>
using namespace std;
int findMax(int arr[],int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max>arr[i])max=arr[i];
        
    }
    return max;
    
}
void findEvenAndCountEven(int arr[],int size){
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]%2==0){
            cout<<arr[i]<<" is even Number"<<endl;
            count++;
        }
    }
    cout<<"Total Even No in array is : "<<count;
    
}
void reverseArray(int arr[],int size){
    int start=0,end=size-1;
    while (start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    cout<<"Printing reversed array";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }

    
}
void arraySum(int arr[],int size){
    int sum=0;
    for (int i = 0; i < sum; i++)
    {
        sum+=arr[i];
    }
    cout<<"Sum of Array is "<<sum;
    
}
void sortedArrayCheck(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i]<=arr[j]|arr[i]>=arr[j])
            {
                continue;
            }
            else{
                cout<<"not Sorted";
                break;
            }
            
        }
        
    }
    // cout<<"sorted";
    
    

}

int main() {
    // int size ;
    // cout<<"enter array size";
    // cin>>size;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     cin>>arr[i];
    // }
    // cout<<"Your array is ";
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<"\t";
    // }
    // cout<<endl;
    int arr[5]={1,2,8,4,5};
    int size=5;

    sortedArrayCheck(arr,size);
    
    
    return 0;
}