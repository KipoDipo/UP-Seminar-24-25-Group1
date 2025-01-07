#include <iostream>

void stringConcat(char* destination, const char* source)
{
    while (*destination != '\0')
    {
        destination++;
    }

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
    char buffer[1024] {};

    stringConcat(buffer, "Hello, ");
    stringConcat(buffer, "World");
    stringConcat(buffer, "!");

    std::cout << buffer;
}