#include <iostream>

char* findInString(char str[], char k)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == k)
        {
            return &str[i];
        }
    }

    return nullptr;
}


int main()
{
    char str[] = "Hello, world!";

    char* ptr = findInString(str, 'w');

    std::cout << str << std::endl;

    if (ptr == nullptr)
    {
        std::cout << "Element not found!";
    }
    else
    {
        std::cout << ptr;
    }
}