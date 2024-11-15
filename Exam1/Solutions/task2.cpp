#include <iostream>

unsigned long long convertToBinary(unsigned int number)
{
    unsigned long long result = 0;
    unsigned long long powerOf10 = 1;

    while (number != 0)
    {
        result += (number % 2) * powerOf10;
        powerOf10 *= 10;

        number /= 2;
    }
    
    return result;
}

unsigned int countDigits(unsigned long long number, unsigned int digit)
{
    unsigned int result = 0;

    while (number != 0)
    {
        if (number % 10 == digit)
            result++;

        number /= 10;
    }

    return result;
}

bool areOnesAndZeroesEqual(unsigned int number)
{
    unsigned long long binary = convertToBinary(number);

    return countDigits(binary, 0) == countDigits(binary, 1);
}

int main()
{
    unsigned int input;
    std::cin >> input;

    if (input > 255)
    {
        std::cout << "bad input";
        return -1;
    }

    std::cout << std::boolalpha << areOnesAndZeroesEqual(input);
}