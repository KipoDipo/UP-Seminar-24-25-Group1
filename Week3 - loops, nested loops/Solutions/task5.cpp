#include <iostream>

using namespace std;

int main()
{
    unsigned int n;

    cout << "Enter num: ";
    cin >> n;

    bool flag = false;

    for (int i = n - 1; i > 1; i--)
    {
        if (n % i == 0)
        {
            flag = true;
            break;
        }
    }

    cout << boolalpha << !flag;
}