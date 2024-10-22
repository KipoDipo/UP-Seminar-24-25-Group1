#include <iostream>

using namespace std;

int main()
{
    int day, month;

    cout << "Enter day: ";
    cin >> day;

    cout << "Enter month: ";
    cin >> month;

    if (day < 1 || day > 31)
    {
        cout << "Incorrect day...";
        return -1;
    }
    if (month < 1 || month > 12)
    {
        cout << "Incorrect month...";
        return -1;
    }


    cout << day;

    if ((day >= 4 && day <= 20) || (day >= 24 && day <= 30))
    {
        cout << "th";
    }
    else if (day % 10 == 3)
    {
        cout << "rd";
    }
    else if (day % 10 == 2)
    {
        cout << "nd";
    }
    else
    {
        cout << "st";
    }

    cout << " of ";
    
    switch (month)
    {
    case 1:  cout << "January";     break;
    case 2:  cout << "February";    break;
    case 3:  cout << "March";       break;
    case 4:  cout << "April";       break;
    case 5:  cout << "May";         break;
    case 6:  cout << "June";        break;
    case 7:  cout << "July";        break;
    case 8:  cout << "August";      break;
    case 9:  cout << "September";   break;
    case 10: cout << "October";     break;
    case 11: cout << "November";    break;
    case 12: cout << "December";    break;
    }
}