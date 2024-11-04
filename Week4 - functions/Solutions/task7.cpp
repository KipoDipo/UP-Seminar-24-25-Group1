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
long long reverse(long long number)
{
   long long result = 0;

   while (number != 0)
   {
        result *= 10;
        result += (number % 10);

        number /= 10;
   }

   return result;
}

bool isPalindrome(long long number)
{
    return number == reverse(number);
}
bool isBinaryPalindrome(long long number)
{
    return isPalindrome(toBinary(number));
}

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (isBinaryPalindrome(i))
        {
            cout << i << '\t' << toBinary(i) << '\n';
        }
    }
}