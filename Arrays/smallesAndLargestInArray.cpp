#include <iostream>
#include <climits> // Include this header for INT_MAX

using namespace std;
// in cpp we use INT_MAX to represent +infinity
int main()
{
    int arr[5] = {3, 5, -6, 2, 1};
    int size = 5;
    int smallest = INT_MAX; // means +infiinty
    int largest = INT_MIN;  // means -infinity
    // now we have to print the index of the smallest value
    int idx; // starts with invalid index like -1 good practice
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            idx = i;
        }

        // we can also use min function insted of this loop
        // smallest = min(arr[i],smallest);
    }
    cout << idx;

    // cout << smallest;
    for (int i = 0; i < size; i++)
    {
        largest = max(arr[i], largest);
        // if (arr[i]>largest)
        // {
        //     largest = arr[i];
        // }
    }
    // cout << largest;

    return 0;
}