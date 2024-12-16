#include <iostream>

using namespace std;

bool solution()
{
    int n;

    int array[500];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // int ctr = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (array[i] == 0)
    //     {
    //         ctr++;
    //         if (ctr == 2)
    //         {
    //             return true;
    //         }
    //     }
    //     else
    //     {
    //         ctr = 0;
    //     }     
    // }

    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] == 0 && array[i + 1] == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << boolalpha << solution();
}