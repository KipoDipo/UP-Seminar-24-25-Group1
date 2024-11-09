#include <iostream>
#include <cmath>

double myRound(double number, int precision)
{
    double t = pow(10, precision);
    return round(number * t) / t; 
}

using namespace std;

void solution()
{
    char buffer[1024];
    char character;

    cout << "Enter string: ";
    // cin >> buffer;
    cin.getline(buffer, 1024);

    cout << "Enter character: ";
    cin >> character;

    int occurances = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == character)
        {
            occurances++;
            buffer[i] = '*';
        }
    }

    cout << "Occurances: " << occurances << endl;
    cout << buffer;
}

int main()
{
    cout << myRound(3.12345678, 3);
}