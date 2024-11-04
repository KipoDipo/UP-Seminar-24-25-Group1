#include <iostream>
using namespace std;

long long factorial(unsigned int number)
{
    long long result = 1;

    while(number != 1)
    {
        result *= number--;
        // result *= number;
        // number--
    }

    return result;
}

int main()
{
    cout << factorial(5);
}