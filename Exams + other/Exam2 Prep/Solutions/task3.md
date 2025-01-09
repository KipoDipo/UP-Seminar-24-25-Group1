Има много подходи за да се реши тази задача.   
На пръв поглед, думите могат да се изтрият, а като последен символ да се зададе `\0`. Тоест от  
```
"hello world hello universe hello"
```
махаме `"hello"` и става  
```
" world  universe \0              "

                  ^
```

По този начин, когато ползваме този низ, напр. при `cout`, ще спре да се принтира където е `\0`. Това обаче не е оптимално по памет - все още имаме. За това можем просто да преоразмерим масива до тази `\0`.

---

Първо безсрамно ще копираме функцията за преоразмеряване от `Week11/Solutions/nextTask1.cpp`, като премахнем част от функционалността и за простота

```cpp
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
```

---

След това безсрамно ще си вземем и функцията за взимане на размер на низ от `Week11/Solutions/baseTask0.cpp`

```cpp
int stringLength(const char* str)
{
    const char* curr = str;
    
    while (*(curr++) != '\0');

    return curr - str - 1;
}
```

---

Ще ни трябва и нова функция, с която да сравняваме 2 низа. Искаме такава функция, за да можем да знаем кога да *не* копираме съдържание от оригиналния низ в новия, т.е. когато срещнем думата - да я пропускаме. Съответно освен 2та низа, ще подадем и 3ти параметър - до кога да сравняваме.

```cpp
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
```

Сега тази функция можем да я ползваме по следния начин:
```cpp
char str1[] = "hello world hello universe";
char str2[] = "hello"; 
int length = stringLength(str2);

bool test1 = compareStrings(str1, str2, length); // true, защото сме казали да се гледат само следващите length (5) букви, тук в случая съвпадат
bool test2 = compareStrings(str1 + 3, str, length); // false
// припомняме си че низовете са просто масиви от букви, а масивите са просто указатели към първия елемент
// съответно str1 + 3 се равнява на низът "lo world hello universe"
bool test3 = compareStrings(str1 + 12, str, length); // true
// str + 12 се равнява на "hello universe"
```
---

Сега можем да преминем към писането на главната функция.   

```cpp
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
```