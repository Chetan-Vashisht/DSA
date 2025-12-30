#include <iostream>
using namespace std;
// program to calculate sum and product of all numbers in array
void sumProductOfArray(int arr[], int size)
{

    int sum = 0, product = 1;
    for (int i = 0; i < size; i++)
    {
        int element = arr[i];
        sum += element;
        product *= element;
    }
    cout << "sum is " << sum << " Product is " << product;
}
// program to swap min and max number of array
void swapMinMax(int arr[], int size)
{
    int max = INT32_MIN, min = INT32_MAX;
    int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    swap(arr[minIndex], arr[maxIndex]);

    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i]<<" ";
    // }
}
// program to print all unique in array ;
void uniqueValue(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique == true)
        {
            cout << arr[i] << " ";
            /* code */
        }
    }
    cout << endl;
}
// interseticon of 2 array
void interseticonOfTwoArray(int arr1[], int arr2[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        bool inArray2 = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                inArray2 = true;
                cout << arr1[i] << " ";
                break;
            }
        }
    }
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int size1 = 7;
    int arr2[] = {1, 2, 4, 5};
    int size2 = 4;
    interseticonOfTwoArray(arr1, arr2, size1, size2);
    // uniqueValue(arr1,size1);
    // // sumProductOfArray(arr, size);
    // swapMinMax(arr1, size1);
    // for (int i = 0; i < size1; i++)
    // {
    //     cout << arr[i] << " ";

    return 0;
}