#include <iostream>

using namespace std;

int* copyArr(const int arr[], int size)
{
    int* copy = new int[size];
    for(int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }

    return copy;
}

int main()
{
    int arr[10] {1,2,3,4,5,6,7,8,9,0};
    int* copy = copyArr(arr, 10);
    
    for (int i = 0; i < 10; i++)
    {
        cout << copy[i] << " ";
    }
    delete[] copy;
}