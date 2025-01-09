#include <iostream>

using namespace std;

void stringResize(char*& str, int newSize)
{
    char* result = new char[newSize + 1] {};

    for (int i = 0; str[i] != '\0' && i < newSize; i++)
    {
        result[i] = str[i];
    }

    delete[] str;
    str = result;
}

int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*(curr++) != '\0');

    return curr - str - 1;
}

bool compareStrings(const char* string1, const char* string2, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (string1[i] != string2[i] || string1[i] == '\0' || string2[i] == '\0') 
        {
            return false;
        }
    }
    return true;
}

char* removedOccurances(const char* from, const char* word)
{
    char* result = new char[stringLength(from) + 1];

    int wordLength = stringLength(word);

    int resultIndex = 0;
    for(int i = 0; from[i] != '\0'; )
    {
        // сравняваме низът from с отметване i
        if (compareStrings(from + i, word, wordLength))
        {
            // ако има попадение, прескачаме цялата дума
            i += wordLength;
        }
        else
        {
            result[resultIndex] = from[i];
            resultIndex++;
            i++;
        }
    }

    result[resultIndex] = '\0'; // resultIndex е и реалният размер на новия низ, тоест колко букви има, освен \0

    stringResize(result, resultIndex);

    return result;
}

int main()
{
    char* test = removedOccurances("hello world hello universe hello", "hello");
    cout << "\"" << test << "\"";

    delete[] test;
}
