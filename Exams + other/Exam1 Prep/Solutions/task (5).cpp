#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int secret = rand() % 100 + 1;

    int input;
    
    bool hasGuessed = false;

    for (int i = 0; i < 10; i++)
    {
        cin >> input;

        if (input < secret)
        {
            cout << "Go higher!\n";
        }
        else if (input > secret)
        {
            cout << "Go lower!\n";
        }
        else
        {
            hasGuessed = true;
            cout << "You guessed the secret number\n";
            break;
        }
    }

    if (!hasGuessed)
    {
        cout << "You ran out of guesses!";
    }
}