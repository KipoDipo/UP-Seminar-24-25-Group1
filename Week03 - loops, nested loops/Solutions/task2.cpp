#include <iostream>

using namespace std;

int main()
{
    int input;
    int prod = 1;

    do
    {
        cin >> input;

        prod *= input;
    } while(input != 1);

    cout << "Prod: " << prod;
}