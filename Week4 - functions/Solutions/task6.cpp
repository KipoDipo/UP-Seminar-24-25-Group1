#include <iostream>

using namespace std;

long long toBinary(unsigned number)
{
    long long result = 0;

    long long tenAccumulator = 1;

    while(number != 0)
    {
        result += (number % 2) * tenAccumulator;
        tenAccumulator *= 10;

        number /= 2;
    }

    return result;
}

int main()
{
    unsigned input;
    cout << "Enter a positive integer: ";
    cin >> input;
    
    cout << toBinary(input);
}