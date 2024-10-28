#include <iostream>

using namespace std;

int main()
{
    long long n;
    cout << "Enter n: ";
    cin >> n;

    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    cout << n << "! = " << result;
}