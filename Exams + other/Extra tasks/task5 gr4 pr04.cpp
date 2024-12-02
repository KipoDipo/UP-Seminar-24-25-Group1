#include <iostream>

using namespace std;

int main()
{
    unsigned n;

    cin >> n;

    int max = INT_MIN;
    int min = INT_MAX;

    int sum = 0;

    
    for (unsigned i = 0; i < n; i++)
    {
        int number;
        cin >> number;

        if (number > max)
        {
            max = number;
        }
        if (number < min)
        {
            min = number;
        }

        sum += number;
    }

    double avg = (double)sum / n;

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Avg: " << avg << endl;
}