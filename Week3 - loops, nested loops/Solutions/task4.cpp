#include <iostream>

using namespace std;

int main()
{
    int a, n, result;
    cout << "Enter number: ";
    cin >> a;
    result = 1;


    cout << "Enter power: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        result *= a;
    }

    cout << a << "^" << n << " = " << result;
}