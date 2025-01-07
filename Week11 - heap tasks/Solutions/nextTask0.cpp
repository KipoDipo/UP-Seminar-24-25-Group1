#include <iostream>

int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*(curr++) != '\0');

    return curr - str - 1;
}

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

char* stringDuplicate(const char* source)
{
    int length = stringLength(source);

    char* result = new char[length + 1] {};

    stringCopy(result, source);

    return result;
}

int main()
{
    char str[] = "Hello, world!";
    char* copy = stringDuplicate(str);

    copy[0] = 'W';
    std::cout << str << std::endl << copy;

    delete[] copy;
}