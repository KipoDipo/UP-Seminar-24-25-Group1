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

unsigned int countOf11InBinary(unsigned int number)
{
    unsigned long long binaryNumber = toBaseN(number, 2);

    unsigned int counter = 0;

    while (binaryNumber != 0)
    {
        if (binaryNumber % 100 == 11)
        {
            counter++;
            binaryNumber /= 10;
        }

        binaryNumber /= 10;
    }

    return counter;
}

int main()
{
    cout << countOf11InBinary(821);
}