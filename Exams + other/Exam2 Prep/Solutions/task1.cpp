#include <iostream>

using namespace std;

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

void addNewEntry(int*& scoreboard, int& size, int entry)
{
    //преоразмеряваме масива, като пренасочим указателя към ново място, което да може да побере всички елементи
    resize(scoreboard, size, size + 1);
    size++; 

    // слагаме `entry` на последния индекс
    scoreboard[size - 1] = entry;
}

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


int main()
{
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

}