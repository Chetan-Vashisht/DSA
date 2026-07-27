// Subarray: continuous part of any large sub array , mahematical formula is : subarray=n*(n+1)/2
// how to print all subarray of an give array

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int>a={1,2,3,4,5};
    int n = a.size();
    
    // Printing all sub array 
    // for(int start=0;start<n;start++){
    //     for(int end=0;end<n;end++){
    //         for(int i=start;i<end;i++){
    //             cout<<a[i]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    
    // Brute Force which has time complexity n^3

    // int finalsum=0; not to use zero as it will not work if array contains -ve elements so insted use 
    // int finalsum=INT_MIN;
    // for(int start=0;start<n;start++){
    //     for(int end=0;end<n;end++){
    //         int currentsum=0;
    //         for(int i=start;i<end;i++){
    //             currentsum+=a[i];
    //         }
    //         finalsum=max(currentsum,finalsum);

    //     }
    // }
    // cout<<finalsum;
    
    //  so simple Optimisation in Brute force to decrese it time complexity to n^2 for n^3
    
    // insted of creating 3 loops this time we just create 2 loops and add just the last emement to final sum to get new current sum
    // example : we have 1,2,3,4 so currentSum is 3 so now we can just add arr[end] which is 3 to this to get 6 insted of 1+2+3=6
    // int finalsum=INT_MIN;
    // for(int start=0;start<n;start++){
    //     int currentsum=0;
    //     for(int end=0;end<n;end++){
    //         currentsum+=a[end]; // this just add sum of elements for 0 to end so small sub array
    //         finalsum=max(currentsum,finalsum);
    //     }
    // }
    // cout<<finalsum;

    // KADANES ALGORITHM
    // approach : if we add and small +ve number to big -ve number answer is always -ve so insted of thsi just reset to current sum to zero 
    int currentSum=0, finalSum=INT_MIN;
    for (int i = 0; i < n; i++)
    {   
        currentSum+=a[i];
        // why first this finalsum and then compare , due to edge case if all elements are -ve so result must be -ve but if we reset currentSum to zero first so it will give wrong answers
        finalSum=max(currentSum,finalSum);
        // reset it because any big -ve number appeared 
        if (currentSum<0)
        {
            currentSum=0;
        }
        
    }
    cout<<finalSum;
    


    
    return 0;
}