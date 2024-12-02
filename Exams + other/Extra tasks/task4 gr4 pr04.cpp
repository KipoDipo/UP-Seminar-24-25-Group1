#include <iostream>

using namespace std;

unsigned count(unsigned number, unsigned check)
{
    unsigned counter = 0;

    while (number != 0)
    {
        if (number % 10 == check)
        {
            counter++;
        }

        number /= 10;
    }

    return counter;
}

unsigned mostCommonDigit(unsigned number)
{
    unsigned mostCommon = 1; 
    unsigned mostCommonCount = 0;

    for (unsigned i = 0; i < 10; i++)
    {
        unsigned occurances = count(number, i);

        if (occurances >= mostCommonCount)
        {
            mostCommonCount = occurances;
            mostCommon = i;
        }
    }

    return mostCommon;
}

int main()
{
    unsigned number;
    cin >> number;
    cout << mostCommonDigit(number);
}