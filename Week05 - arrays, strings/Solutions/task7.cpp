#include <iostream>

using namespace std;

int main()
{
    char str[] = "Hello!!";

    const char diff = 'a' - 'A';

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += diff;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= diff;
        }
    }

    cout << str;
}