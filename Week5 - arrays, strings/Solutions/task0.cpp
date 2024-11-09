#include <iostream>

using namespace std;

void solution()
{
    int n;

    double array[100];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    double max = array[0];
    double min = array[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }

        if (array[i] < min)
        {
            min = array[i];
            minIndex = i;
        }
    }

    cout << "Max: " << max << " at index " << maxIndex;
    cout << "\nMin: " << min << " at index " << minIndex;
}

int main()
{
    solution();
}