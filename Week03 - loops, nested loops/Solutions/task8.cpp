#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << '0';
            else if (i > j)
                cout << '-';
            else
                cout << '+';
        }
        cout << '\n';
    }
}