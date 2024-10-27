#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    if (N < 0)
    {
        cout << "N cannot be negative...";
        return -1;
    }

    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int digitCount = 0;
    int otherCount = 0;

    for (int i = 0; i < N; i++)
    {
        char input;
        cout << "Enter character #" << i + 1 << ": ";
        cin >> input;

        if (input >= 'A' && input <= 'Z')
            upperCaseCount++;
        else if (input >= 'a' && input <= 'z')
            lowerCaseCount++;
        else if (input >= '0' && input <= '9')
            digitCount++;
        else
            otherCount++;
    }

    cout << "Uppercase count: " << upperCaseCount << '\n';
    cout << "Lowercase count: " << lowerCaseCount << '\n';
    cout << "Digit count: " << digitCount << '\n';
    cout << "Other count: " << otherCount << '\n';
}