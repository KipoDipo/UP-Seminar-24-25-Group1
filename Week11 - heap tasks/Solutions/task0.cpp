#include <iostream>

char* fileName(const char* path)
{
    const char* dot = path;
    while (*dot != '.' && *dot != '\0')
    {
        dot++;
    }

    char* result = new char[(dot - path) + 1] {};
    
    for (int i = 0; path[i] != '.' && path[i] != '\0'; i++)
    {
        result[i] = path[i];
    }

    return result;
}

int main()
{
    char* name = fileName("minecraft.exe");
    std::cout << name;

    delete[] name;
}