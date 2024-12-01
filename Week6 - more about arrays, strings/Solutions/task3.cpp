#include <iostream>

void concatSorted(const int arr1[], int size1, 
                  const int arr2[], int size2,
                  int result[])
{
    int indexA = 0, indexB = 0;
    int indexC = 0;
    while (indexA < size1 && indexB < size2)
    {
        result[indexC++] = (arr1[indexA] < arr2[indexB]) ? arr1[indexA++] : arr2[indexB++]; 
    }
    if (indexA >= size1)
    {
        while (indexB < size2)
        {
            result[indexC++] = arr2[indexB++];
        }
    }
    else
    {
        while (indexA < size1)
        {
            result[indexC++] = arr1[indexA++];
        }
    }
}

int main()
{
    int arr1[5] {1, 1, 3, 6, 10};
    int arr2[2] {2, 7};

    int sorted[7] {};

    concatSorted(arr1, 5, arr2, 2, sorted);

    for (int i = 0; i < 7; i++)
    {
        std::cout << sorted[i] << " ";
    }
}