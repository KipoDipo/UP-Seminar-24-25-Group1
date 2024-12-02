#include <iostream>

bool areOnesAndZeroesEqual(unsigned int number)
{
    int count1 = 0;
    int count0 = 0;

    while (number != 0)
    {
        if (number % 2 == 0)
            count0++;
        else
            count1++;

        number /= 2;
    }

    return count1 == count0;
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