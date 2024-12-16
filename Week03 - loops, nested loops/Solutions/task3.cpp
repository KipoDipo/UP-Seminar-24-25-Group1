#include <iostream>

using namespace std;

int main()
{
    unsigned int number;

    cout << "Enter num: ";
    cin >> number;

    unsigned temp = number;

    unsigned int sum = 0;

    while (temp != 0)
    {
        sum += temp % 10;
        
        temp /= 10;
    }

    cout << "Sum of the digits of " << number << " is " << sum;
}