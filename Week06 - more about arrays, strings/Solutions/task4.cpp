#include <iostream>

bool isArrayPalindrome(const int arr[], int size)
{
    int a = 0, b = size - 1;
    while (a < b)
    {
        if (arr[a] != arr[b])
        {
            return false;
        }

        a++;
        b--;
    }
    return true;

    /*
    
    Alternatively:

    for (int i = 0; i < size / 2; i++)
        if (arr[i] != arr[size - 1 - i])
            return false;

    return true;

    */
}

int main()
{
    int arr[] {1,2,3,2,1};
    std::cout << std::boolalpha << isArrayPalindrome(arr, 4);
}