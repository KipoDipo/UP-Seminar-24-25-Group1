# Функции
Функцията е парче код, който има име и връща стойност.

```cpp
<тип> <име>(<параметър1>, <параметър2>, ...)
{
    // код
    return <стойност>;
}
```

Типът на изразa, който връщаме, задължително трябва да е същият като типа на функцията! 

Пример:

```cpp
int makeItDouble(int x)
{
    return x * 2;
}
```

```cpp
float halveIt(float x)
{
    return x / 2;
}
```

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

```cpp
bool isEven(int x)
{
    return x % 2 == 0;
}
```

```cpp
void sayHello()
{
    cout << "Hello!";
}
``` 
*void е тип, който не съдържа информация, следователно return не е задължителен. Когато се използва return при void, се пише само ``return;`` без израз/стойност.*

```cpp
void sayHelloOnlyIfEven(int x)
{
    if (!isEven(x))
        return;
    
    cout << "Hello!";
}
``` 

Входната функция на програмата е специална, тя ще бъде задължително извикана при стартиране на програмата и не може да липсва.

```cpp
int main()
{
    return 0;
}
```

За да използваме функция, тя трябва да бъде *декларирана* над мястото, където ще бъде повикана. Функциите **НЕ** могат да се *декларират* или *дефинират* вътре в друга функция.\
\
*Декларацията* и *дефиницията* не задължително се случват на едно и също място.

```cpp
int sum(int a, int b) // declaration + definition
{
    return a + b;
}

int main()
{
    cout << sum(11, 53); // OK
    return 0;
}
```

```cpp
int sum(int a, int b); // declaration

int main()
{
    cout << sum(11, 53); // OK
    return 0;
}

int sum(int a, int b) // definition
{
    return a + b;
}
```

```cpp
int main()
{
    cout << sum(11, 53); // ERROR!!!
    return 0;
}

int sum(int a, int b) // declaration + definition
{
    return a + b;
}
```