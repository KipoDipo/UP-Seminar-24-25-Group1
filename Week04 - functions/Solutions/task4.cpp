#include <iostream>

using namespace std;

unsigned reverse(unsigned number)
{
   unsigned result = 0;

   while (number != 0)
   {
        result *= 10;
        result += (number % 10);

        number /= 10;
   }

   return result;
}

int main()
{
    cout << reverse(12345);
}