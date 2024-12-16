#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cout << "Enter amount of numbers to enter: ";
    cin >> n;

    int biggestNegative = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        if (input < 0)
        {
            if (input > biggestNegative)
            {
                biggestNegative = input;
            }
        }
    }
    if (biggestNegative != INT_MIN)
    {
        cout << "Biggest negative: " << biggestNegative;
    }
    else
    {
        cout << "No negative numbers have been inputted.";
    }
}