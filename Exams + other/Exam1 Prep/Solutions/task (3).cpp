#include <iostream>

using namespace std;

int main()
{
    double a,b,c;

    cout << "Enter 3 sides: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0)
    {
        cout << "Bad input... :(";
        return -1;
    }

    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
        {
            cout << "All sides are equal";
        }
        else if (a == b || b == c || a == c)
        {
            cout << "Equilateral";
        }
        else 
        {
            cout << "None of the sides are equal";
        }
    }
    else
    {
        cout << "This triangle cannot exist";
    }
}