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


void renameFile(char*& path, const char* newName)
{
    char* extention = extentionName(path);

    char* result = new char[stringLength(newName) + stringLength(extention) + 1 + 1] {};
    // + 1 for '.'

    stringConcat(result, newName);
    stringConcat(result, ".");
    stringConcat(result, extention);

    delete[] extention;
    delete[] path;

    path = result;
}

int main()
{
    char* buffer = new char[1024]{};
    stringConcat(buffer, "minecraft.exe");


    std::cout << buffer << "\n";
    
    renameFile(buffer, "fortnite");

    std::cout << buffer << "\n";

    delete[] buffer;
}