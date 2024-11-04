#include <iostream>

using namespace std;

long long sum(int a, int b)
{
    return (long long)a + b;
}

int main()
{
    cout << sum(8, 42) << endl;
    
    cout << sum(INT_MAX, 42) << endl;
}