#include <iostream>

using namespace std;

void solution()
{
    int n;

    int array[250];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << array[i] << ' ';
    }
}

int main()
{
    solution();
}