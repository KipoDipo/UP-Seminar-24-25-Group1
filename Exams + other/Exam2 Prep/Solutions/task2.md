Целта е да създадем програма, която позволява на потребителя да рисува върху динамично създадено поле (матрица от символи). Полето може да бъде уголемявано и променяно по желание. Всеки символ представлява "пиксел", който може да бъде запълнен или изтрит.

---

Първо ще направим променливи, които ще съдържат височината и широчината на платното.
```cpp
int rols, cols
```

След това ще декларираме матрицата, която т.к. е динамична, ще представлява указател към указател към `char`
```cpp
char** canvas;
```

---

Най-лесно ще е, ако разбием всяка функционалност в отделна функция, за да избегнем преписването на код. Първата таква функция ще е за създаване на платно.

```cpp
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
```

---

Няколко пъти ще ни се наложи да я изтриваме (при преоразмеряването например), за това още сега ще си направим функция, която да освобождава паметта.

```cpp
void deleteCanvas(char** canvas, int rows)
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] canvas[i];
    }
    delete[] canvas;
}
```

---


Нека направим и функция за принтиране на платното.

```cpp
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
```

---

Сега ще напишем функция, която променя определен пиксел от платното.

```cpp
void modifyPixel(char** canvas, int row, int col, char value)
{
    canvas[row][col] = value;
}
```

От нея следват функциите за съответно запълване и изтриване на пиксел.

```cpp
void fillPixel(char** canvas, int row, int col)
{
    modifyPixel(canvas, row, col, '#');
}
```

```cpp
void deletePixel(char** canvas, int row, int col)
{
    modifyPixel(canvas, row, col, ' ');
}
```

---

Сега вече можем да преминем към преоразмеряването. Тъй като ще променяме някои параметри, ще ги подадем по референция.

```cpp
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
```

---

С това задачата е готова. Отново ще направим примерна програма за да покажем функционалността.

```cpp
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
```