#include <iostream>
using namespace std;

short sumOfDigits(unsigned int number)
{
    short sum = 0;

    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main()
{
    cout << sumOfDigits(1234);
}