#include <iostream>

int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*(curr++) != '\0');

    return curr - str - 1;
}

char* extentionName(const char* path)
{    
    const char* dot = path + stringLength(path);

    int length = 0;
    while (*dot != '.' && dot != path)
    {
        dot--;
        length++;
    }
    char* result = new char[length + 1] {};
    
    dot++;
    for (int i = 0; dot[i] != '\0'; i++)
    {
        result[i] = dot[i];
    }

    return result;
}

int main()
{
    char* name = extentionName("minecraft.exe");
    std::cout << name;

    delete[] name;
}