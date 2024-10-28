#include <iostream>

using namespace std;

int main()
{
    for (char i = 'A'; i <= 'Z'; i++)
    {
        switch (i)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            break;

            default:
            cout << i << ' ';
            break;
        }

        // if (i != 'A' && i != 'E' && i != 'U' && i != 'I' && i != 'O')
        // {
        //     cout << i << ' ';
        // }
    }
}