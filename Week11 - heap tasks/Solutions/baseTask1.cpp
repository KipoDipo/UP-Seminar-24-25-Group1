#include <iostream>

void stringCopy(char* destination, const char* source)
{
    while (*source != '\0')
    {
        *destination = *source;
        
        destination++;
        source++;
    }
    *destination = '\0';
}

int main()
{

}