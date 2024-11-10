#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

    double d = b*b - 4*a*c;

    if (d > 0)
    {
        int x1 = (-b + sqrt(d)) / 2*a;
        int x2 = (-b - sqrt(d)) / 2*a;

        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2;
    }
    else if (d == 0)
    {
        int x = -b / 2*a;
        cout << "x1,x2: " << x;
    }
    else
    {
        cout << "No real solutions";
    }
}