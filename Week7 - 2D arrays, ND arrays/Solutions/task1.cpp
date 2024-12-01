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

int sumMainDiagonal(int matrix[MAX_ROWS][MAX_COLS], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {  
        result += matrix[i][i];
    }
    return result;
}

int sumSecondaryDiagonal(int matrix[MAX_ROWS][MAX_COLS], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {  
        result += matrix[i][n - 1 - i];
    }
    return result;
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS] {};
    int n;

    std::cout << "Enter N: ";
    std::cin >> n;

    inputMatrix(matrix, n, n);

    std::cout << "\n\n";

    std::cout << "Sum of Main Diagonal: " <<sumMainDiagonal(matrix, n);
    std::cout << "\nSum of Secondary Diagonal: " << sumSecondaryDiagonal(matrix, n);
}