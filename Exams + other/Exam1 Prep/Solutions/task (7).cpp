#include <iostream>

using namespace std;

unsigned long long toBaseN(unsigned int number, unsigned int base)
{
    unsigned long long result = 0;

    unsigned int power = 1;

    while(number != 0)
    {
        unsigned int remainder = number % base;

        result += remainder * power;

        power *= 10;

        number /= base;
    }

    return result;
} 

int main()
{
    cout << toBaseN(94, 8);
}