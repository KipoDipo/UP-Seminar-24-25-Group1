#include <iostream>

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
    solution();
}