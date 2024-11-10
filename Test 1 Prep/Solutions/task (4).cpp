#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0); 
}

int main()
{
    int year;
    cout << "Enter year: ";
    cin >> year;

    cout << isLeapYear(year);
}