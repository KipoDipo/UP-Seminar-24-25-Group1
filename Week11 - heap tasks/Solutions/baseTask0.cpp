#include <iostream>

int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*(curr++) != '\0');

    return curr - str - 1;
}

/*
Alternatively:

int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*curr != '\0')
    {
        curr++;
    }

    return curr - str;
}
*/

int main()
{
}