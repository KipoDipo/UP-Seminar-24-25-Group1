#include <iostream>

using namespace std;

int* resize(const int arr[], unsigned size, unsigned newSize)
{
    if (size == 0 || newSize == 0)
    {
        return nullptr;
    }

    int* copy = new int[newSize] {};

    unsigned min = size < newSize ? size : newSize;

    for (int i = 0; i < min; i++)
    {
        copy[i] = arr[i];
    }

    return copy;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int k = 100;
    int* copy = resize(arr, 5, k);

    for (int i = 0; i < k; i++)
    {
        cout << copy[i] << " ";
    }

    delete[] copy;
}