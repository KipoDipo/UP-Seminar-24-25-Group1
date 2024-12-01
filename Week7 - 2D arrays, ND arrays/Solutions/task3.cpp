#include <iostream>

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void printMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            std::cout << matrix[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            std::cin >> matrix[y][x];
        }
    }
}

void printCoordsOfNum(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int number)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (matrix[y][x] == number)
            {
                std::cout << "(" << y << ", " << x << ") ";
            }
        }
    }
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS] {};
    int n, m;

    std::cout << "Enter N: ";
    std::cin >> n;
    std::cout << "Enter M: ";
    std::cin >> m;

    inputMatrix(matrix, n, m);

    int number;

    std::cout << "Enter number: ";
    std::cin >> number;

    printCoordsOfNum(matrix, n, m, number);
}