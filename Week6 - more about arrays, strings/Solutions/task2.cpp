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

void rotate(int arr[], unsigned size, unsigned k)
{
    for (unsigned j = 0; j < k; j++)
    {
        int temp = arr[0];
        for (unsigned i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }
}


int main()
{
    int arr[] = {1,2,3,4,5};
    printArray(arr, 5);
    rotate(arr, 5, 3);
    printArray(arr, 5);
}