#include <iostream>

unsigned long long zigzag(unsigned long long number)
{
    unsigned short count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    
    unsigned long long result = 0;

    while (number != 0)
    {
        switch (number % 10)
        {
            case 1: count1++; break;
            case 2: count2++; break;
            case 3: count3++; break;
            case 4: count4++; break;
            case 5: count5++; break;
            default: // if any digit other than [1,2,3,4,5] is present
                return 0;
        }

        number /= 10;
    }

    // if any of the digits [1,2,3,4,5] is not present
    if (count1 == 0 || count2 == 0 || count3 == 0 || count4 == 0 || count5 == 0)
        return 0;

    // order 1 -> 5 -> 2 -> 3 -> 4
    
    for (int i = 0; i < count1; i++)
        result = result * 10 + 1;
    for (int i = 0; i < count5; i++)
        result = result * 10 + 5;
    for (int i = 0; i < count2; i++)
        result = result * 10 + 2;
    for (int i = 0; i < count4; i++)
        result = result * 10 + 4;
    for (int i = 0; i < count3; i++)
        result = result * 10 + 3;

    return result;
}

int main()
{
    unsigned long long test1 = 43251243215;
    unsigned long long test2 = 512244253424;
    unsigned long long test3 = 1224423424;
    unsigned long long test4 = 2234157;

    std::cout << test1 << " \t" << zigzag(test1) << '\n';
    std::cout << test2 << " \t" << zigzag(test2) << '\n';
    std::cout << test3 << " \t" << zigzag(test3) << '\n';
    std::cout << test4 << " \t" << zigzag(test4) << '\n';
}