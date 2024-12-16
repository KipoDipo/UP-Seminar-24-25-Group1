#include <iostream>
using namespace std;

bool possibleTriangle(float sideA, float sideB, float sideC)
{
    if (sideA <= 0 || sideB <= 0 || sideC <= 0)
        return false;
    
    return sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA;
}

int main()
{
    cout << boolalpha << possibleTriangle(2, 3, 5) << endl;

    cout << possibleTriangle(4, 3, 5) << endl;
}