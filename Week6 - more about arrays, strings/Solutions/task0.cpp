#include <iostream>

using namespace std;

void printArray(const int arr[], unsigned int size)
{
    cout << "[";
    for (unsigned int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "]\n";
}

void reverse(int arr[], unsigned int size)
{
    for (unsigned int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    printArray(arr, 5);
    reverse(arr, 5);
    printArray(arr, 5);
}