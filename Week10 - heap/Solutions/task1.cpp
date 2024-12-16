#include <iostream>

using namespace std;

int* halveArray(const int arr[], int size)
{
    int* copy = new int[size / 2];

    for (int i = 0; i < size / 2; i++)
    {
        copy[i] = arr[i];
    }

    return copy;
}

int main()
{
    const int size = 6;

    int arr[size] {1,2,3,4,5,6};

    int* half = halveArray(arr, size);

    for (int i = 0; i < size / 2; i++)
    {
        cout << half[i] << " ";
    }

    delete[] half;    
}