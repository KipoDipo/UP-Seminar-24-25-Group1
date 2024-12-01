#include <iostream>

using namespace std;

void printArray(const int arr[], unsigned size)
{
    cout << "[";
    for (unsigned i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "]\n";
}

int secondLargestNumber(const int arr[], unsigned size)
{
    int max = arr[0];
    int max2 = arr[0];

    for (unsigned i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max2 = max;
            max = arr[i];
        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

int main()
{
    int arr[] = {1, 7, 17, 5, 16, 3, 2};
    cout << secondLargestNumber(arr, 7);

    // int arr[] = {1};
    // cout << secondLargestNumber(arr, 1);
}