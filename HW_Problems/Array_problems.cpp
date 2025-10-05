#include <iostream>
#include <climits>
using namespace std;
void swapnumber(int array[], int size){
    
}

int main()
{
    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = 10;
    // int sum = 0, product = 1;
    // for (int i = 0; i < size; i++)
    // {
    //     sum += array[i];
    //     product *= array[i];
    // }
    // cout << sum << " is the sum of array" << endl;
    // cout << product << " is the product of the array" << endl;

    //  swap min and max of array

    int array[] = {11, 2, 33, 42, 51, 63, 75, 81, 93, 100};
    int min = INT_MAX,max=INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        if (min>array[i])
        {
            min = array[i];
        }
        if (max<array[i])
        {
            max=array[i];
        }
        
        
    }
    swap(min,max);
    cout<<"max "<<max<<endl;
    cout<<"min "<<min<<endl;
    




    return 0;
}