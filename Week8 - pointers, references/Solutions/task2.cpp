#include <iostream>

int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    return sum;
}

int findMin(int arr1[], int size1,
             int arr2[], int size2,
             int** ptr)
{
    int length1 = sumArray(arr1, size1);
    int length2 = sumArray(arr2, size2);

    *ptr = (length1 < length2) ? arr1 : arr2;
    return (length1 < length2) ? size1 : size2;
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int main()
{
    int* ptr = nullptr;

    int arr1[3] {1, 2, 3};
    int arr2[4] {0, 10, 2, 3};

    int size = findMin(arr1, 3, arr2, 4, &ptr);

    printArray(ptr, size);
}