#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
void swapnumber(int array[], int size)
{
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

    // int arr[] = {11, 2, 33, 42, 51, 63, 75, 81, 93, 100};
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // int min = 0, max = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (arr[i] < arr[min])
    //     {
    //         min = i;
    //     }
    //     if (arr[i] > arr[max])
    //     {
    //         max = i;
    //     }
    // }
    // swap(arr[min], arr[max]);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // Print unique value of array

    // int arr[] = {1, 2, 2, 2, 7, 9, 1, 2, 5, 6};
    // int size = 10;
    // for (int i = 0; i < size; i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             count++;
    //         }
    //     }
    //     if (count == 1)
    //     {
    //         cout << arr[i] << " ";
    //     }
    // }

    // intersection of 2 array
    int arr1[] = {1, 2, 3};
    int s1 = 3, s2 = 3;
    int arr2[] = {2, 3, 4};
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << "same element are " << arr1[i] << endl;
            }
        }
    }

    return 0;
}