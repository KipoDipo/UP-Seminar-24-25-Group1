#include <iostream>

int strLength(const char* str)
{
    const char* curr = str;
    while (*curr++);
    return curr - str - 1;
}

void strConcat(char* to, const char* from)
{
    while (*to) 
    {
        to++;
    };

    while (*from)
    {
        *to++ = *from++;
    }
}

char** pathArray(const char* str, int& size)
{
    size = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '/' || str[i + 1] == '\0')
            size++;
    }

    char** result = new char*[size];

    int beginIndex = 0;
    for (int i = 0; i < size; i++)
    {
        int stringLength = 0;
        for (int j = beginIndex; str[j] != '/' && str[j] != '\0'; j++)
            stringLength++;

        result[i] = new char[stringLength + 1] {};
        
        for (int j = 0; j < stringLength; j++)
            result[i][j] = str[beginIndex + j];

        beginIndex += stringLength + 1;
    }
    return result;
}

void strAppend(char*& to, const char* from)
{
    char* result = new char[strLength(to) + strLength(from) + 1] {};
    strConcat(result, to);
    strConcat(result, from);
    delete[] to;
    to = result;
}

int main()
{
    char root[] = "C:/";
    char* path = new char[strLength(root) + 1] {};
    strConcat(path, root);

    strAppend(path, "Hello/");
    std::cout << path << "\n";
    strAppend(path, "World/");
    std::cout << path << "\n";

    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << arr[i] << "\n";
    // }
    
}