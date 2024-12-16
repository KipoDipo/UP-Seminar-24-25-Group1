#include <iostream>

using namespace std;

bool isArrayPalindrome()
{
    unsigned n;
    int array[50];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < (n/2); i++)
    {
        if (array[i] != array[(n - 1) - i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << isArrayPalindrome();
}