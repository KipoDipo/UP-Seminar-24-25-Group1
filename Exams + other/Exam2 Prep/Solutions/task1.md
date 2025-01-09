Според условието, трябва да се прави списък, чийто размер може да е с произволна дължина. Съответно ще трябва да работим с динамична памет. Ще започнем като направим списък с размер 1.

```cpp
int size = 0;
int *scoreboard = new int[size];
```
*Въпреки че изглежда странно, е позволено масив да има размер 0*

Избираме този подход, защото към този момент в него няма никаква информация, и ако някой се опита да го принтира по стандартния начин, няма да успее, защото size=0, следователно цикъла ще бъде пропуснат.

---

Нека имплементираме първата функция - `addNewEntry`. Тя трябва да приеме самия списък *по референция*, както и неговия размер, като освен това трябва и да се вземат точките които трябва да се добавят. Списъкът е референция, защото когато го преоразмерим, искаме реалният указатаел да сочи към ново място в паметта. Съответно сигнатурата на функцията трябва да е:
```cpp
void addNewEntry(int*& scoreboard, int& size, int entry); 
```
*Параметърът `sizе` е подаден по референция, защото ще го увеличим с 1 и искаме това да се отрази върху реалната променлива, която ползваме за да следим размерът*

Първото нещо, което трябва да направим, е да подсигурим достатъчно място в масива. Първоначално размерът му ще е 0, след това ще стане 1, след това 2 и т.н.. Тук е хубаво да си направим функция `resize(...)`, която ще преоразмери масива, като запази оригиналните елементи. Такава функция ще приеме масивът по референция (за да променим реалния указател), неговият размер, и новия размер, който искаме да заема.

```cpp
void resize(int*& array, int size, int newSize)
{
    int* result = new int[newSize];

    if (size > newSize)
    {
        size = newSize; // това го правим за да ограничим копирането, в случай че новият размер е по-малък
                        // в противен случай ще излезем извън границите на масива `result`
    }

    for (int i = 0; i < size; i++)
    {
        result[i] = array[i];
    }

    delete[] array;

    array = result;
}
```

Сега вече можем реално да преминем към писането на функцията `addNewEntry`.

```cpp
void addNewEntry(int*& scoreboard, int& size, int entry)
{
    //преоразмеряваме масива, като пренасочим указателя към ново място, което да може да побере всички елементи
    resize(scoreboard, size, size + 1);
    size++; 

    // слагаме `entry` на последния индекс
    scoreboard[size - 1] = entry;
}
```

---

За втората функция, не трябва да модифицираме нищо. Трябва само да върнем масив от N елемента. Съответно сигнатурата ще е следната:
```cpp
int* getTopNResults(const int* scoreboard, int size, int N);
```

Има много подходи за да намерим най-големите N елемента в масив, но ние ще използваме по-примитивен подход.
1) Ще обходим масива, намирайки най-големия елемент. 
2) След това ще го обхождаме N-1 пъти, за да намерим елементът, който е едновременно най-голям, но и по-малък от предния най-голям.

```cpp
int* getTopNResults(const int* scoreboard, int size, int N)
{
    int* result = new int[N];

    /// ===== 1) =====

    result[0] = INT_MIN; // със сигурност ще намерим число, по-голямо от това
    for (int j = 0; j < size; j++)
    {
        if (scoreboard[j] > result[0])
        {
            result[0] = scoreboard[j];
        }
    }

    /// ===== 2) =====

    for (int i = 1; i < N; i++)
    {
        result[i] = INT_MIN;
        for (int j = 0; j < size; j++)
        {
            // текущото число трябва да е едновременно по-голямо от най-голямото намерено до сега
            // но също така и по-малко от най-голямото намерено на предишната стъпка
            if (scoreboard[j] > result[i] && scoreboard[j] < result[i - 1])
            {
                result[i] = scoreboard[j];
            }
        }
    }

    return result;
}
```
---

За третата функция, трябва само да подадем списъкът и размерът (по референция, тъй като ще ги променим)

```cpp
void removeLowestScore(int*& scoreboard, int& size);
```

Идеята тук е да намерим най-малкият елемент, както и неговият индекс. След това ще "избутаме" най-малкия елемент до последното място. Тоест ако имаме:  
`[5, 2, 6, 20]`  
ще избутаме `2` накрая  
`[5, 6, 20, 2]` 

След това просто ще преоразмерим списъкът с един размер надолу.

```cpp
void removeLowestScore(int*& scoreboard, int& size)
{
    int lowestIndex = 0;
    int lowestValue = scoreboard[0];

    for (int i = 1; i < size; i++)
    {
        if (scoreboard[i] < lowestValue)
        {
            lowestValue = scoreboard[i];
            lowestIndex = i;
        }
    }


    for (int i = lowestIndex; i < size - 1; i++)
    {
        int save = scoreboard[i + 1];
        scoreboard[i + 1] = scoreboard[i];
        scoreboard[i] = save;
    }

    resize(scoreboard, size, size - 1);
    size--;
}
```

--- 

И с това задачата е готова. За да я видим на практика ще напишем и кратка програма, която демонстрира функционалността ѝ.

---

Чакаме потребителя да въведе коя от 3те функции иска да изпълни. Нека го подканим:

```cpp
int size = 0;
int *scoreboard = new int[size];

bool isRunning = true;
while (isRunning)
{
    cout << "1. Print the scoreboard\n";
    cout << "2. Add a new entry\n";
    cout << "3. Get top N results\n";
    cout << "4. Remove lowest score\n";
    cout << "0. Exit\n\n";
    cout << ">";
    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
            for (int i = 0; i < size; i++)
            {
                cout << "Score #" << i + 1 << ": " << scoreboard[i] << "\n";
            }
            break;
        case 2:
        {
            int entry;
            cout << "Enter new score: ";
            cin >> entry;
            addNewEntry(scoreboard, size, entry);
            break;
        }
        case 3:
        {
            int n;
            cout << "N: ";
            cin >> n;
            int* topN = getTopNResults(scoreboard, size, n);
            for (int i = 0; i < n; i++)
            {
                cout << "Top #" << i + 1 << ": " << topN[i] << "\n";
            }
            delete[] topN; // важно! изтриваме заделената памет
                           // в противен случай - теч на памет
            break;
        }
        case 4:
            removeLowestScore(scoreboard, size);
            break;
        case 0: 
            isRunning = false;
            break;
        default:
            cerr << "Bad input...\n";
            break;
    }
}

delete[] scoreboard;
```
