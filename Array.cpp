#include <iostream>
using namespace std;
int currentSize = 0;
bool isFull(int *arr, int size)
{
    if (size == currentSize)
        return true;
    else
        return false;
}
bool isEmpty(int *arr, int size)
{
    if (currentSize == 0)
        return true;
    else
        return false;
}
void print(int *arr, int size)
{
    int i = 0;
    cout << "Elements are :";
    for (i = 0; i < currentSize; i++)
    {
        cout << arr[i];
    }
}
void insertAtBeginning(int *arr, int size, int ele)
{
    if (isFull(arr, size))
    {
        cout << "Full";
        return;
    }
    for (int i = currentSize - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = ele;
    currentSize++;
}

void deleteAtBeginning(int *arr, int size)
{
    if (isEmpty(arr, size))
        return;
    for (int i = 1; i < currentSize; i++)
    {
        arr[i - 1] = arr[i];
    }
    currentSize--;
}

void insertAtEnt(int *arr, int size, int ele)
{
    if (isFull(arr, size))
        return;
    arr[currentSize] = ele;
    currentSize++;
}

void deleteAtEnd(int *arr, int size)
{
    if (isEmpty(arr, size))
        return;
    currentSize--;
}

void insertAtIndex(int *arr, int size, int ele, int idx)
{
    if (isFull(arr, size))
        return;
    if (idx > currentSize && idx < size)
    {
        arr[idx] = ele;
        currentSize++;
        return;
    }
    for (int i = currentSize - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[idx] = ele;
    currentSize++;
}
void deletaAtIndex(int *arr, int idx, int size)
{
    if (isEmpty(arr, size))
        return;
    if (idx <= currentSize - 1)
        return;
    if (idx <= currentSize - 1 & idx >= 0)
    {
        for (int i = idx + 1; i < currentSize; i++)
        {
            arr[i - 1] = arr[i];
            currentSize--;  
        }
    }
}
int main()
{

    return 0;
}