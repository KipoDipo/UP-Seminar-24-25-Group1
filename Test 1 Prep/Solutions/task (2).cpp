#include <iostream>

using namespace std;

int main()
{
    unsigned int userInput;

    cout << "Enter cents: ";
    cin >> userInput;


    // 81
    // 3*25 + 0*10 + 1*5 + 1

    unsigned int quarters = userInput / 25;
    unsigned int tens = (userInput % 25) / 10;
    unsigned int fives = ((userInput % 25) % 10) / 5;
    unsigned int cents = userInput - (quarters*25 + tens*10 + fives*5);

    cout << "Quarters: " << quarters << endl;
    cout << "Tens: " << tens << endl;
    cout << "Fives: " << fives << endl;
    cout << "Cents: " << cents << endl;
}