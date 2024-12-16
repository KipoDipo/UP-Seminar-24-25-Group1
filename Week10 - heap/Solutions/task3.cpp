#include <iostream>

using namespace std;

int** createMatrix(int N, int M)
{
    int** mat = new int*[N];

    for (int i = 0; i < N; i++)
    {
        mat[i] = new int[M] {};
    }

    return mat;
}

void printMatrix(int** mat, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void freeMatrix(int** mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int n = 2, m = 3;
    int** mat = createMatrix(n, m);
    printMatrix(mat, n, m);
    freeMatrix(mat, n);
}