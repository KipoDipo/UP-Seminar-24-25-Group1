#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter amount of rows: ";
    cin >> n;

    int counter = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << counter << ' ';
            counter++;
        }
        cout << '\n';
    }
}