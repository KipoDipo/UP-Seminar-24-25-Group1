#include <iostream>
#include <cmath>

using namespace std;

unsigned digitCount(unsigned number)
{
    unsigned count = 0;

    while(number != 0)
    {
        count++;
        number /= 10;
    }

    return count;
}

unsigned long long concat(unsigned first, unsigned second)
{
    /*
    unsigned secondDigitCount = digitCount(second);

    unsigned long long powerOf10 = pow(10, secondDigitCount);

    unsigned long long result = first * powerOf10 + second;

    return result;
    */
    
    return ((unsigned long long)pow(10, digitCount(second))) * first + second;;
}

int main()
{
    cout << concat(123, 456);
}