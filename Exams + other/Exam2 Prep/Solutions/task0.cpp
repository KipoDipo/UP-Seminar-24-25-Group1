#include <iostream>

using namespace std;

unsigned numLength(unsigned number)
{
    unsigned counter = 0;
    while (number != 0)
    {
        counter++;
        number /= 10;
    }
    return counter;
}

char* unsignedToString(unsigned number)
{
    unsigned length = numLength(number);

    char* result = new char[length + 1] {}; // всички елементи са \0

    /* 
        най-лесното обхождане на число е наобратно, тоест да взимаме цифрите му от дясно наляво.
        това означава, че ще е най-разумно да обходим масива наобратно, за да записваме числото в правилния ред
    */

   for (int i = length - 1; i >= 0; i--)
   {
        result[i] = (number % 10) + '0'; // number % 10 е последната цифра на числото, като добавим + '0' ще вземем ASCII стойността на това число
        number /= 10;
   }

   return result;
}


int main()
{
    unsigned number = 123456;
    char* str = unsignedToString(number);

    //...
    //... използваме str
    //...

    delete[] str;

    //...
    //... вече не използваме str, или го променяме на друг низ
    //...
}