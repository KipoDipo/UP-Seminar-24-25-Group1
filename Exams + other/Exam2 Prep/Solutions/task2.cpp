#include <iostream>

using namespace std;

char** createCanvas(int rows, int cols)
{
    char** canvas = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        canvas[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            canvas[i][j] = ' '; // Празен пиксел
        }
    }
    return canvas;
}

void deleteCanvas(char** canvas, int rows)
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] canvas[i];
    }
    delete[] canvas;
}

void displayCanvas(char** canvas, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

void modifyPixel(char** canvas, int row, int col, char value)
{
    canvas[row][col] = value;
}

void fillPixel(char** canvas, int row, int col)
{
    modifyPixel(canvas, row, col, '#');
}

void deletePixel(char** canvas, int row, int col)
{
    modifyPixel(canvas, row, col, ' ');
}

char** resizeCanvas(char** canvas, int& rows, int& cols, int newRows, int newCols) 
{
    char** newCanvas = createCanvas(newRows, newCols);

    // Намираме най-малкия брой редове и колони да копираме
    // това го правим за да ограничим копирането, в случай че новият размер е по-малък
    // в противен случай ще излезем извън границите на матрицата `newCanvas`
    int rowsToCopy = (rows > newRows) ? newRows : rows;
    int colsToCopy = (cols > newCols) ? newCols : cols;

    // Копиране на съществуващите пиксели
    for (int i = 0; i < rowsToCopy; i++) 
    {
        for (int j = 0; j < colsToCopy; j++) 
        {
            newCanvas[i][j] = canvas[i][j];
        }
    }

    // Освобождаване на старата матрица
    deleteCanvas(canvas, rows);

    // Актуализиране на размера
    rows = newRows;
    cols = newCols;

    return newCanvas;
}

int main()
{
    int rows, cols;

    cout << "Enter size of canvas: ";
    cin >> rows >> cols;

    char** canvas = createCanvas(rows, cols);

    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Display the canvas\n";
        cout << "2. Fill a pixel\n";
        cout << "3. Remove a pixel\n";
        cout << "4. Resize\n";
        cout << "0. Exit\n\n";
        cout << ">";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                displayCanvas(canvas, rows, cols);
                break;
            case 2: 
            {
                int r, c;
                cout << "Enter row and column: ";
                cin >> r >> c;
                fillPixel(canvas, r, c);
                break;
            }
            case 3: 
            {
                int r, c;
                cout << "Enter row and column: ";
                cin >> r >> c;
                deletePixel(canvas, r, c);
                break;
            }
            case 4: 
            {
                int newRows, newCols;
                cout << "Enter new size (rows and columns): ";
                cin >> newRows >> newCols;
                canvas = resizeCanvas(canvas, rows, cols, newRows, newCols);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Bad input!\n";
        }
    } while (choice != 0);

    deleteCanvas(canvas, rows);
}