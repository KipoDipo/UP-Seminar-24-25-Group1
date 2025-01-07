#include <iostream>

char** tokenizePath(const char* path, int& length)
{
    int arrayLength = 0;
    for (int i = 0; path[i] != '\0'; i++)
    {
        if (path[i] == '/')
        {
            arrayLength++;
        }
    }
    arrayLength++;
    length = arrayLength;

    char** result = new char * [arrayLength];

    int index = 0;
    int beginIndex = 0;
    int wordLength = 0;
    for (int i = 0; path[i] != '\0'; i++)
    {
        if (path[i] == '/')
        {
            result[index] = new char[wordLength + 1] {};

            for (int j = 0; j < wordLength; j++)
            {
                result[index][j] = path[beginIndex + j];
            }

            beginIndex += wordLength + 1;
            index++;
            wordLength = 0;
        }
        else
        {
            wordLength++;
        }
    }

    result[index] = new char[wordLength + 1] {};

    for (int j = 0; j < wordLength; j++)
    {
        result[index][j] = path[beginIndex + j];
    }


    return result;
}

int main()
{
    const char path[] = "C:/Windows/System32/notepad.exe";
    int length = 0;


    char** tokens = tokenizePath(path, length);

    for (int i = 0; i < length; i++)
    {
        std::cout << tokens[i] << "\n";
    }

    std::cout << "Total components: " << length;

    for (int i = 0; i < length; i++)
    {
        delete[] tokens[i];
    }
    delete[] tokens;
}