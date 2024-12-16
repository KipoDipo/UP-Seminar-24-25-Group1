#include <iostream>

void swapPtr(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swapRef(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    // swapPtr(&a, &b);
    swapRef(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}