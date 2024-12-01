#include <iostream>

const int ROWS = 3;
const int COLS = 4;

void printMatrix(const int matrix[ROWS][COLS])
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            std::cout << matrix[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

int findMaxInMatrix(const int matrix[ROWS][COLS])
{
    int max = matrix[0][0];

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            if (matrix[y][x] > max)
            {
                max = matrix[y][x];
            }
        }
    }

    return max;
}

int main()
{
    int matrix[ROWS][COLS]
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2}
    };

    printMatrix(matrix);
    std::cout << findMaxInMatrix(matrix);
}