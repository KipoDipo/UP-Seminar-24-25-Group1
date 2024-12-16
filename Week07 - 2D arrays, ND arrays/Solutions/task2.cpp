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

int sumRow(int matrix[MAX_ROWS][MAX_COLS], int cols, int row)
{
    int result = 0;
    for (int i = 0; i < cols; i++)
    {
        result += matrix[row][i];
    }
    return result;
}

int sumCol(int matrix[MAX_ROWS][MAX_COLS], int rows, int col)
{
    int result = 0;
    for (int i = 0; i < rows; i++)
    {
        result += matrix[i][col];
    }
    return result;
}


bool isMatrixMagic(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    const int magicSum = sumRow(matrix, cols, 0);

    for (int i = 1; i < rows; i++)
    {
        if (magicSum != sumRow(matrix, cols, i))
            return false;
    }

    for (int i = 0; i < cols; i++)
    {
        if (magicSum != sumCol(matrix, rows, i))
            return false;
    }

    return true;
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

    std::cout << std::boolalpha << isMatrixMagic(matrix, n, m);


}