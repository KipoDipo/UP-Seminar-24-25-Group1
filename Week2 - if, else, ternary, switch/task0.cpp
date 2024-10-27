#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float r;
    float x, y;

    cout << "Enter radius: ";
    cin >> r;

    cout << "Enter x and y coordinates: ";
    cin >> x >> y;

    float distance = sqrt(x*x + y*y); // or sqrt(pow(x, 2) + pow(y, 2))
    // remember: sqrt, pow, abs etc. come from <cmath>

    cout << boolalpha << (distance <= r);
    // keep in mind that boolalpha comes from std!!!
    // std::boolalpha
}