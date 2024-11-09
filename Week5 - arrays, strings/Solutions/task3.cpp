#include <iostream>

using namespace std;

int solution()
{
    int n;

    int array[250];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            int sum = 0;

            if (i == n - 1)
                return INT_MIN;

            for (int j = i + 1; j < n; j++)
            {
                sum += array[j];    
            }

            return sum;
        }
    }

    return INT_MIN;
}

int main()
{
    int result = solution();

    if (result == INT_MIN)
    {
        cout << "Every number is negative or only last is positive!";
        return -1;
    }

    cout << result;
}