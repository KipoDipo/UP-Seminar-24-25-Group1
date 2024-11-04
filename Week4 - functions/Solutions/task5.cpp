#include <iostream>

using namespace std;

bool isPrime(unsigned number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isPrime(121) << endl;
    cout << isPrime(11);
}