#include <iostream>

using namespace std;

void printCharNTimes(char c, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << c;
    }
}

int main()
{
    char str[] = {'B', 'B', 'A', 'A', 'C', 'A'};
    // BBAACA
    // AAABBC

    for (int i = 0; i < 6; i++)
    {
        cout << str[i];
    }

    cout << endl;

    int aCounter = 0, bCounter = 0, cCounter = 0;

    for (int i = 0; i < 6; i++)
    {
        switch(str[i])
        {
            case 'A': aCounter++; break;
            case 'B': bCounter++; break;
            case 'C': cCounter++; break;
        }
    }

    printCharNTimes('A', aCounter);
    printCharNTimes('B', bCounter);
    printCharNTimes('C', cCounter);
}