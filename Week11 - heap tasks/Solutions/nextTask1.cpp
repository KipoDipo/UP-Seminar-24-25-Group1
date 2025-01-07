#include <iostream>

void stringResize(char*& str, int newSize, char fill = '\0')
{
    char* result = new char[newSize + 1];
    for (int i = 0; i < newSize; i++)
    {
        result[i] = fill;
    }
    result[newSize] = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        result[i] = str[i];
    }

    delete[] str;
    str = result;
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

int main()
{
    char* buffer = new char[20] {};
    stringCopy(buffer, "Hello, world");

    stringResize(buffer, 100, '.');

    std::cout << buffer;
}