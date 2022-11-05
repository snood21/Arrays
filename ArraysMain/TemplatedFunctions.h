#pragma once
#include "stdafx.h"
#include "constants.h"
#include "Service.h"
#include "NavigatingByMenu.h"

template <typename T> T* CreateArray(const int ArraySize);
template <typename T> T** CreateArray(const int ArrayStrings, const int ArrayColumns);

template <typename T> void DeleteArray(T* Array);
template <typename T> void DeleteArray(T** Array, const int ArrayStrings);

template <typename T> void menu(int ArraySize);
template <typename T> void menu(int ArrayColumns, int ArrayStrings);
template <typename T> void FillRand(T*& Array, const int ArraySize, int MinRand = 0, int MaxRand = 1000);
template <typename T> void FillRand(T**& Array, const int ArrayColumns, const int ArrayStrings, int MinRand = 0, int MaxRand = 1000);
template <typename T> void Print(T* Array, const int ArraySize, int& ActiveString);
template <typename T> void Print(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> void ReversePrint(T* Array, const int ArraySize, int& ActiveString);
template <typename T> void ReversePrint(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> T Sum(T* Array, const int ArraySize);
template <typename T> T Sum(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> double Avg(T* Array, const int ArraySize);
template <typename T> double Avg(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> T minValueIn(T* Array, const int ArraySize);
template <typename T> T minValueIn(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> T maxValueIn(T* Array, const int ArraySize);
template <typename T> T maxValueIn(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> void shiftLeft(T*& Array, const int ArraySize, int ShiftValue);
template <typename T> void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue);
template <typename T> void shiftRight(T*& Array, const int ArraySize, int ShiftValue);
template <typename T> void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue);
template <typename T> void Sort(T*& Array, const int ArraySize, const bool SortByAscending);
template <typename T> void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending);
template <typename T> void Search(T* Array, const int ArraySize, int& ActiveString);
template <typename T> void Search(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> void UniqueRand(T*& Array, const int ArraySize, int MinRand = 0, int MaxRand = 1000);
template <typename T> void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, int MinRand = 0, int MaxRand = 1000);
template <typename T> bool ValueInArray(T* Array, const T ArrayValue, const int ArrayIndex);
template <typename T> bool ValueInArray(T** Array, const T ArrayValue, const int IndexString, const int IndexColumn, const int ArrayColumns);

template <typename T> void Split(T* Array, const int ArraySize, int& ActiveString);

template <typename T> void push_back(T*& Array, int& ArraySize, const T AddedValue);
template <typename T> void push_string_back(T**& Array, int& ArrayStrings, const int ArrayColumns);
template <typename T> void push_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns);
template <typename T> void push_front(T*& Array, int& ArraySize, const T AddedValue);
template <typename T> void push_string_front(T**& Array, int& ArrayStrings, const int ArrayColumns);
template <typename T> void push_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns);
template <typename T> void insert(T*& Array, int& ArraySize, const T AddedValue, const int InsertIndex);
template <typename T> void insert_string(T**& Array, int& ArrayStrings, const int ArrayColumns, const int InsertStringIndex);
template <typename T> void insert_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int InsertColumnIndex);

template <typename T> void pop_back(T*& Array, int& ArraySize);
template <typename T> void pop_string_back(T**& Array, int& ArrayStrings);
template <typename T> void pop_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns);
template <typename T> void pop_front(T*& Array, int& ArraySize);
template <typename T> void pop_string_front(T**& Array, int& ArrayStrings);
template <typename T> void pop_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns);
template <typename T> void erase(T*& Array, int& ArraySize, const int EraseIndex);
template <typename T> void erase_string(T**& Array, int& ArrayStrings, const int EraseStringIndex);
template <typename T> void erase_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int EraseColumnIndex);

template <typename T> void FillColumnRand(T**& Array, const int ArrayStrings, const int FillColumnIndex, int MinRand = 0, int MaxRand = 1000);

template <typename T>
T* CreateArray(const int ArraySize)
{
    T* Array = new T[ArraySize]{};
    return Array;

}

template <typename T>
T** CreateArray(const int ArrayStrings, const int ArrayColumns)
{
    T** Array = new T* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = CreateArray<T>(ArrayColumns);
    }
    return Array;
}

template <typename T>
void DeleteArray(T* Array)
{
    delete[] Array;
}

template <typename T>
void DeleteArray(T** Array, const int ArrayStrings)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        DeleteArray(Array[i]);
    }
    delete[] Array;
}

template <typename T>
void menu(int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    T* Array = CreateArray<T>(ArraySize);

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 22;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Разделить на массивы четных и нечетных элементов";
    MenuList[15] = "Добавить значение в конец массива";
    MenuList[16] = "Добавить значение в начало массива";
    MenuList[17] = "Добавить значение в массив по указанному индексу";
    MenuList[18] = "Удалить последний элемент массива";
    MenuList[19] = "Удалить первый элемент массива";
    MenuList[20] = "Удалить значение из массива по указанному индексу";
    MenuList[21] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArraySize); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: PrintString("Текущий массив: ", ActiveString); Print(Array, ArraySize, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 2: PrintString("Текущий массив в обратном порядке: ", ActiveString); ReversePrint(Array, ArraySize, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 3:
                PrintString("Сумма элементов массива: "+to_string(Sum(Array, ArraySize)), ActiveString, true); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 4:
                PrintString("Среднее арифметическое элементов массива: "+to_string(Avg(Array, ArraySize)), ActiveString, true); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 5:
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 6:
                PrintString("Максимальное значение в массиве: "+to_string(maxValueIn(Array, ArraySize)), ActiveString, true);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 7:
                {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 8:
                {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 9: UniqueRand(Array, ArraySize, ActiveString); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: Sort(Array, ArraySize, true); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 11: Sort(Array, ArraySize, false); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 12: FillRand(Array, ArraySize, 0, ArraySize - 1); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: Search(Array, ArraySize, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 14: Split(Array, ArraySize, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 15:
                {
                T AddedValue;
                PrintString("Введите значение для добавления: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                push_back(Array, ArraySize, AddedValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 16:
                {
                T AddedValue;
                PrintString("Введите значение для добавления: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                push_front(Array, ArraySize, AddedValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 17:
                {T AddedValue;
                int InsertIndex;
                PrintString("Введите значение для вставки: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                PrintString("Введите индекс втавляемого значения: ", ActiveString);
                cin >> InsertIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert(Array, ArraySize, AddedValue, InsertIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 18: pop_back(Array, ArraySize); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 19: pop_front(Array, ArraySize); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 20:
                {
                int EraseIndex;
                PrintString("Введите индекс удаляемого элемента: ", ActiveString);
                cin >> EraseIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase(Array, ArraySize, EraseIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 21: quit = true; DeleteArray(Array); break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

template <typename T>
void menu(int ArrayColumns, int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    T** Array = CreateArray<T>(ArrayStrings,ArrayColumns);

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 29;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Добавить строку в конец массива";
    MenuList[15] = "Добавить строку в начало массива";
    MenuList[16] = "Добавить строку в массив по указанному индексу";
    MenuList[17] = "Удалить последнюю строку массива";
    MenuList[18] = "Удалить первую строку массива";
    MenuList[19] = "Удалить строку из массива по указанному индексу";
    MenuList[20] = "Добавить колонку в конец массива";
    MenuList[21] = "Добавить колонку в начало массива";
    MenuList[22] = "Добавить колонку в массив по указанному индексу";
    MenuList[23] = "Удалить последнюю колонку массива";
    MenuList[24] = "Удалить первую колонку массива";
    MenuList[25] = "Удалить колонку из массива по указанному индексу";
    MenuList[26] = "Заполнить строку массива по указанному индексу случайными числами";
    MenuList[27] = "Заполнить колонку массива по указанному индексу случайными числами";
    MenuList[28] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArrayColumns, ArrayStrings); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: PrintString("Текущий массив:", ActiveString, true); Print(Array, ArrayColumns, ArrayStrings, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 2: PrintString("Текущий массив в обратном порядке:", ActiveString, true); ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 3:
                PrintString("Сумма элементов массива: "+to_string(Sum(Array, ArrayColumns, ArrayStrings)), ActiveString, true); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 4:
                PrintString("Среднее арифметическое элементов массива: "+to_string(Avg(Array, ArrayColumns, ArrayStrings)), ActiveString, true);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 5:
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 6:
                PrintString("Максимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 7:
                {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 8:
                {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ActiveString); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: Sort(Array, ArrayColumns, ArrayStrings, true); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 11: Sort(Array, ArrayColumns, ArrayStrings, false); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 12:
                FillRand(Array, ArrayColumns, ArrayStrings, 0, ArrayColumns + ArrayStrings - 1);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                break;
            case 13: Search(Array, ArrayColumns, ArrayStrings, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 14: push_string_back(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 15: push_string_front(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 16:
                {
                int InsertStringIndex;
                PrintString("Введите индекс вставляемой строки: ", ActiveString);
                cin >> InsertStringIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert_string(Array, ArrayStrings, ArrayColumns, InsertStringIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 17: pop_string_back(Array, ArrayStrings); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 18: pop_string_front(Array, ArrayStrings); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 19:
                {
                int EraseStringIndex;
                PrintString("Введите индекс удаляемой строки: ", ActiveString);
                cin >> EraseStringIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase_string(Array, ArrayStrings, EraseStringIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 20: push_column_back(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 21: push_column_front(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 22:
                {
                int InsertColumnIndex;
                PrintString("Введите индекс вставляемой колонки: ", ActiveString);
                cin >> InsertColumnIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert_column(Array, ArrayStrings, ArrayColumns, InsertColumnIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 23: pop_column_back(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 24: pop_column_front(Array, ArrayStrings, ArrayColumns); PrintString("Выполнено!", ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 25:
                {
                int EraseColumnIndex;
                PrintString("Введите индекс удаляемой колонки: ", ActiveString);
                cin >> EraseColumnIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase_column(Array, ArrayStrings, ArrayColumns, EraseColumnIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 26:
                {
                int FillStringIndex;
                PrintString("Введите индекс строки для заполнения: ", ActiveString);
                cin >> FillStringIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                FillRand(Array[FillStringIndex],ArrayColumns);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 27:
                {
                int FillColumnIndex;
                PrintString("Введите индекс колонки для заполнения: ", ActiveString);
                cin >> FillColumnIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                FillColumnRand(Array,ArrayStrings,FillColumnIndex);
                PrintString("Выполнено!", ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                }
                break;
            case 28: quit = true; DeleteArray(Array, ArrayStrings); break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

template<typename T>
void FillRand(T*& Array, const int ArraySize, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
    }
}

template<typename T>
void FillRand(T**& Array, const int ArrayColumns, const int ArrayStrings, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        FillRand(Array[i],ArrayColumns,MinRand,MaxRand);
    }
}

template<typename T>
void Print(T* Array, const int ArraySize, int& ActiveString)
{
    setlocale(LC_ALL, "*");
    for (int i = 0; i < ArraySize; i++)
    {
        cout << Array[i] << "\t";
    }
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "Rus");
}

template <typename T>
void Print(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        Print(Array[i],ArrayColumns,ActiveString);
    }
}

template <typename T>
void ReversePrint(T* Array, const int ArraySize, int& ActiveString)
{
    setlocale(LC_ALL, "*");
    for (int i = ArraySize - 1; i >= 0; i--)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "Rus");
}

template <typename T>
void ReversePrint(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        ReversePrint(Array[i],ArrayColumns,ActiveString);
    }
}

template <typename T>
T Sum(T* Array, const int ArraySize)
{
    T ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

template <typename T>
T Sum(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        ArraySum += Sum(Array[i],ArrayColumns);
    }
    return ArraySum;
}

template <typename T>
double Avg(T* Array, const int ArraySize)
{
    T ArraySum = Sum(Array, ArraySize);

    return (double)ArraySum / ArraySize;
}

template <typename T>
double Avg(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (double)ArraySum / (ArrayColumns + ArrayStrings);
}

template <typename T>
T minValueIn(T* Array, const int ArraySize)
{
    T MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

template <typename T>
T minValueIn(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T MinValue = minValueIn(Array[0],ArrayColumns);

    for (int i = 1; i < ArrayStrings; i++)
    {
        T MinValueInString = minValueIn(Array[i],ArrayColumns);
        if (MinValueInString < MinValue) MinValue = MinValueInString;
    }
    return MinValue;
}

template <typename T>
T maxValueIn(T* Array, const int ArraySize)
{
    T MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

template <typename T>
T maxValueIn(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T MaxValue = maxValueIn(Array[0],ArrayColumns);

    for (int i = 0; i < ArrayStrings; i++)
    {
        T MaxValueInString = minValueIn(Array[i],ArrayColumns);
        if (MaxValueInString > MaxValue) MaxValue = MaxValueInString;
    }
    return MaxValue;
}

template <typename T>
void shiftLeft(T*& Array, const int ArraySize, int ShiftValue)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        T CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
}

template <typename T>
void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        T FirstValue = Array[0][0];
        for (int j = 0; j < ArrayStrings; j++)
        {
            for (int k = 0; k < ArrayColumns; k++)
            {
                if (k == ArrayColumns - 1)
                {
                    if (j == ArrayStrings - 1) Array[j][k] = FirstValue;
                    else Array[j][k] = Array[j + 1][0];
                }
                else Array[j][k] = Array[j][k + 1];
            }
        }
    }
}

template <typename T>
void shiftRight(T*& Array, const int ArraySize, int ShiftValue)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue);
}

template <typename T>
void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue);
}

template <typename T>
void UniqueRand(T*& Array, const int ArraySize, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        T ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
        }

        Array[i] = ArrayValue;
    }
}

template <typename T>
void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            T ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
            while (ValueInArray(Array, ArrayValue, i, j, ArrayColumns))
            {
                ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
            }
            Array[i][j] = ArrayValue;
        }
    }
}

template <typename T>
bool ValueInArray(T* Array, const T ArrayValue, const int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue)
        {
            ValueInArray = true;
            break;
        }
    }
    return ValueInArray;
}

template <typename T>
bool ValueInArray(T** Array, const T ArrayValue, const int IndexString, const int IndexColumn, const int ArrayColumns)
{
    bool ValueInArray = false;
    for (int i = 0; i <= IndexString; i++)
    {
        for (int j = 0; j < (i == IndexString ? IndexColumn : ArrayColumns); j++)
        {
            if (Array[i][j] == ArrayValue)
            {
                ValueInArray = true;
                break;
            }
        }
        if (ValueInArray) break;
    }
    return ValueInArray;
}

template <typename T>
void Sort(T*& Array, const int ArraySize, const bool SortByAscending)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            bool NeedChange;
            if (SortByAscending) NeedChange = (Array[j] < Array[i]);
            else NeedChange = (Array[j] > Array[i]);

            if (NeedChange)
            {
                T CurrentValue = Array[i];
                Array[i] = Array[j];
                Array[j] = CurrentValue;
            }
        }
    }
}

template <typename T>
void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = k == i ? (j + 1) : 0; l < ArrayColumns; l++)
                {
                    bool NeedChange;
                    if (SortByAscending) NeedChange = (Array[k][l] < Array[i][j]);
                    else NeedChange = (Array[k][l] > Array[i][j]);

                    if (NeedChange)
                    {
                        T CurrentValue = Array[i][j];
                        Array[i][j] = Array[k][l];
                        Array[k][l] = CurrentValue;
                    }
                }
            }
        }
    }
}

template <typename T>
void Search(T* Array, const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        bool IsRepeat = false;
        for (int j = 0; j < i; j++) if (Array[j] == Array[i])
        {
            IsRepeat = true;
            break;
        }
        if (IsRepeat) continue;

        int CountOfDouble = 1;
        for (int j = i + 1; j < ArraySize; j++)
        {
            if (Array[i] == Array[j]) CountOfDouble++;
        }
        if (CountOfDouble > 1)
        {
            TotalDoubles += CountOfDouble;
            cout << Array[i] << " - " << CountOfDouble << " раз(а)\t";
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    cout << endl;
    ActiveString++;
}

template <typename T>
void Search(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    int TotalDoubles = 0;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            bool IsRepeat = false;
            for (int k = 0; k <= i; k++)
            {
                for (int l = 0; l < (k == i ? j : ArrayColumns); l++)
                {
                    if (Array[k][l] == Array[i][j])
                    {
                        IsRepeat = true;
                        break;
                    }
                }
                if (IsRepeat) break;
            }
            if (IsRepeat) continue;

            int CountOfDouble = 1;
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = k == i ? (j + 1) : 0; l < ArrayColumns; l++)
                {
                    if (Array[k][l] == Array[i][j]) CountOfDouble++;
                }
            }
            if (CountOfDouble > 1)
            {
                TotalDoubles += CountOfDouble;
                cout << Array[i][j] << " - " << CountOfDouble << " раз(а)\t";
            }
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    cout << endl;
    ActiveString++;
}

template <typename T>
void Split(T* Array, const int ArraySize, int& ActiveString)
{
    int evenSize = 0;
    int oddSize = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        T CurrentValue = Array[i];
        if ((CurrentValue-(int)CurrentValue)==0)
        {
            if ((int)CurrentValue%2==0) evenSize++;
            else oddSize++;
        }
        else oddSize++;
    }

    T* even = CreateArray<T>(evenSize);
    T* odd = CreateArray<T>(oddSize);

    int evenIndex = 0;
    int oddIndex = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        T CurrentValue = Array[i];
        if ((CurrentValue-(int)CurrentValue)==0)
        {
            if ((int)CurrentValue%2==0)
            {
                even[evenIndex] = CurrentValue;
                evenIndex++;
            }
            else
            {
                odd[oddIndex] =CurrentValue;
                oddIndex++;
            }
        }
        else
        {
            odd[oddIndex] =CurrentValue;
            oddIndex++;
        }
    }

    if (evenSize > 0)
    {
        PrintString("Массив четных элементов: ", ActiveString);
        Print(even, evenSize, ActiveString);
    }
    if (oddSize > 0)
    {
        PrintString("Массив нечетных элементов: ", ActiveString);
        Print(odd, oddSize, ActiveString);
    }

    if (evenSize > 0) DeleteArray(even);
    if (oddSize > 0) DeleteArray(odd);
}

template <typename T>
void push_back(T*& Array, int& ArraySize, const T AddedValue)
{
    T* NewArray = CreateArray<T>(ArraySize+1);
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i] = Array[i];
    }
    DeleteArray(Array);
    Array = NewArray;
    Array[ArraySize] = AddedValue;
    ArraySize++;
}

template <typename T>
void push_string_back(T**& Array, int& ArrayStrings, const int ArrayColumns)
{
    T** NewArray = new T*[ArrayStrings+1];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    Array[ArrayStrings] = CreateArray<T>(ArrayColumns);
    ArrayStrings++;
}

template <typename T>
void push_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns)
{
    T** NewArray = CreateArray<T>(ArrayStrings,ArrayColumns+1);
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
    ArrayColumns++;
}

template <typename T>
void push_front(T*& Array, int& ArraySize, const T AddedValue)
{
    T* NewArray = CreateArray<T>(ArraySize+1);
    NewArray[0] = AddedValue;
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i+1] = Array[i];
    }
    DeleteArray(Array);
    Array = NewArray;
    ArraySize++;
}

template <typename T>
void push_string_front(T**& Array, int& ArrayStrings, const int ArrayColumns)
{
    T** NewArray = new T*[ArrayStrings+1];
    NewArray[0] = CreateArray<T>(ArrayColumns);
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayStrings++;
}

template <typename T>
void push_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns)
{
    T** NewArray = CreateArray<T>(ArrayStrings, ArrayColumns+1);

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j+1] = Array[i][j];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
    ArrayColumns++;
}

template <typename T>
void insert(T*& Array, int& ArraySize, const T AddedValue, const int InsertIndex)
{
    T* NewArray = CreateArray<T>(ArraySize+1);

    for (int i = 0; i < InsertIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    NewArray[InsertIndex] = AddedValue;
    for (int i = InsertIndex; i < ArraySize; i++)
    {
        NewArray[i+1] = Array[i];
    }
    DeleteArray(Array);
    Array = NewArray;
    ArraySize++;
}

template <typename T>
void insert_string(T**& Array, int& ArrayStrings, const int ArrayColumns, const int InsertStringIndex)
{
    T** NewArray = new T*[ArrayStrings+1];
    for (int i = 0; i < InsertStringIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    NewArray[InsertStringIndex] = CreateArray<T>(ArrayColumns);
    for (int i = InsertStringIndex; i < ArrayStrings; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayStrings++;
}

template <typename T>
void insert_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int InsertColumnIndex)
{
    T** NewArray = CreateArray<T>(ArrayStrings, ArrayColumns+1);
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < InsertColumnIndex; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
        for (int j = InsertColumnIndex; j < ArrayColumns; j++)
        {
            NewArray[i][j+1] = Array[i][j];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
    ArrayColumns++;
}

template <typename T>
void pop_back(T*& Array, int& ArraySize)
{
    ArraySize--;
    T* NewArray = CreateArray<T>(ArraySize);
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i] = Array[i];
    }
    DeleteArray(Array);
    Array = NewArray;
}

template <typename T>
void pop_string_back(T**& Array, int& ArrayStrings)
{
    ArrayStrings--;
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = Array[i];
    }
    DeleteArray(Array[ArrayStrings]);
    delete[] Array;
    Array = NewArray;
}

template <typename T>
void pop_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns)
{
    ArrayColumns--;
    T** NewArray = CreateArray<T>(ArrayStrings,ArrayColumns);

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
}

template <typename T>
void pop_front(T*& Array, int& ArraySize)
{
    T* NewArray = CreateArray<T>(ArraySize-1);
    for (int i = 1; i < ArraySize; i++)
    {
        NewArray[i-1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArraySize--;
}

template <typename T>
void pop_string_front(T**& Array, int& ArrayStrings)
{
    T** NewArray = new T*[ArrayStrings-1];
    for (int i = 1; i < ArrayStrings; i++)
    {
        NewArray[i-1] = Array[i];
    }
    DeleteArray(Array[0]);
    delete[] Array;
    Array = NewArray;
    ArrayStrings--;
}

template <typename T>
void pop_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns)
{
    T** NewArray = CreateArray<T>(ArrayStrings,ArrayColumns-1);
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 1; j < ArrayColumns; j++)
        {
            NewArray[i][j-1] = Array[i][j];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
    ArrayColumns--;
}

template <typename T>
void erase(T*& Array, int& ArraySize, const int EraseIndex)
{
    T* NewArray = CreateArray<T>(ArraySize-1);
    for (int i = 0; i < EraseIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    for (int i = EraseIndex+1; i < ArraySize; i++)
    {
        NewArray[i-1] = Array[i];
    }
    DeleteArray(Array);
    Array = NewArray;
    ArraySize--;
}

template <typename T>
void erase_string(T**& Array, int& ArrayStrings, const int EraseStringIndex)
{
    T** NewArray = new T*[ArrayStrings-1];
    for (int i = 0; i < EraseStringIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    for (int i = EraseStringIndex+1; i < ArrayStrings; i++)
    {
        NewArray[i-1] = Array[i];
    }
    DeleteArray(Array[EraseStringIndex]);
    delete[] Array;
    Array = NewArray;
    ArrayStrings--;
}

template <typename T>
void erase_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int EraseColumnIndex)
{
    ArrayColumns--;
    T** NewArray = CreateArray<T>(ArrayStrings,ArrayColumns);
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < EraseColumnIndex; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
        for (int j = EraseColumnIndex; j < ArrayColumns; j++)
        {
            NewArray[i][j] = Array[i][j+1];
        }
    }
    DeleteArray(Array,ArrayStrings);
    Array = NewArray;
}

template <typename T>
void FillColumnRand(T**& Array, const int ArrayStrings, const int FillColumnIndex, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i][FillColumnIndex] = (double) (rand() % (MaxRand - MinRand) + MinRand)/10;
    }
}
