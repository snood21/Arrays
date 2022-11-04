#pragma once
#include "stdafx.h"
#include "constants.h"
#include "Service.h"
#include "NavigatingByMenu.h"

template <typename T> void menu(T ArrayType, int ArraySize);
template <typename T> void menu(T ArrayType, int ArrayColumns, int ArrayStrings);
template <typename T> void FillRand(T*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
template <typename T> void FillRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
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
template <typename T> void shiftLeft(T*& Array, const int ArraySize, int ShiftValue, int& ActiveString);
template <typename T> void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
template <typename T> void shiftRight(T*& Array, const int ArraySize, int ShiftValue, int& ActiveString);
template <typename T> void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
template <typename T> void Sort(T*& Array, const int ArraySize, const bool SortByAscending, int& ActiveString);
template <typename T> void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
template <typename T> void Search(T* Array, const int ArraySize, int& ActiveString);
template <typename T> void Search(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> void UniqueRand(T*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
template <typename T> void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
template <typename T> bool ValueInArray(T* Array, const T ArrayValue, const int ArrayIndex);
template <typename T> bool ValueInArray(T** Array, const T ArrayValue, const int IndexString, const int IndexColumn, const int ArrayColumns);

template <typename T> void Split(T* Array, const int ArraySize, int& ActiveString);

template <typename T> void push_back(T*& Array, int& ArraySize, const T AddedValue, int& ActiveString);
template <typename T> void push_string_back(T**& Array, int& ArrayStrings, const int ArrayColumns, int& ActiveString);
template <typename T> void push_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString);
template <typename T> void push_front(T*& Array, int& ArraySize, const T AddedValue, int& ActiveString);
template <typename T> void push_string_front(T**& Array, int& ArrayStrings, const int ArrayColumns, int& ActiveString);
template <typename T> void push_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString);
template <typename T> void insert(T*& Array, int& ArraySize, const T AddedValue, const int InsertIndex, int& ActiveString);
template <typename T> void insert_string(T**& Array, int& ArrayStrings, const int ArrayColumns, const int InsertStringIndex, int& ActiveString);
template <typename T> void insert_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int InsertColumnIndex, int& ActiveString);

template <typename T> void pop_back(T*& Array, int& ArraySize, int& ActiveString);
template <typename T> void pop_string_back(T**& Array, int& ArrayStrings, int& ActiveString);
template <typename T> void pop_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString);
template <typename T> void pop_front(T*& Array, int& ArraySize, int& ActiveString);
template <typename T> void pop_string_front(T**& Array, int& ArrayStrings, int& ActiveString);
template <typename T> void pop_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString);
template <typename T> void erase(T*& Array, int& ArraySize, const int EraseIndex, int& ActiveString);
template <typename T> void erase_string(T**& Array, int& ArrayStrings, const int EraseStringIndex, int& ActiveString);
template <typename T> void erase_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int EraseColumnIndex, int& ActiveString);

template <typename T>
void menu(T ArrayType, int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    T* Array = new T[ArraySize];

    bool ArrayFilled = false;

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
            case 0: FillRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArraySize, ArrayFilled, ActiveString, 0, ArraySize - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Split(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 15: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                T AddedValue;
                PrintString("Введите значение для добавления: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                push_back(Array, ArraySize, AddedValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 16: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                T AddedValue;
                PrintString("Введите значение для добавления: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                push_front(Array, ArraySize, AddedValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 17: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                T AddedValue;
                int InsertIndex;
                PrintString("Введите значение для вставки: ", ActiveString);
                cin >> AddedValue; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                PrintString("Введите индекс втавляемого значения: ", ActiveString);
                cin >> InsertIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert(Array, ArraySize, AddedValue, InsertIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 18: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_back(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 19: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_front(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 20: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                int EraseIndex;
                PrintString("Введите индекс удаляемого элемента: ", ActiveString);
                cin >> EraseIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase(Array, ArraySize, EraseIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 21: quit = true; delete[] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

template <typename T>
void menu(T ArrayType, int ArrayColumns, int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    T** Array = new T* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = new T[ArrayColumns];
    }

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 27;
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
    MenuList[26] = "Выход";

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
            case 0: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString, 0, ArrayColumns + ArrayStrings - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                push_string_back(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 15: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                push_string_front(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 16: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                int InsertStringIndex;
                PrintString("Введите индекс вставляемой строки: ", ActiveString);
                cin >> InsertStringIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert_string(Array, ArrayStrings, ArrayColumns, InsertStringIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 17: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_string_back(Array, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 18: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_string_front(Array, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 19: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                int EraseStringIndex;
                PrintString("Введите индекс удаляемой строки: ", ActiveString);
                cin >> EraseStringIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase_string(Array, ArrayStrings, EraseStringIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                break;
            case 20: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                push_column_back(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 21: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                push_column_front(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 22: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                int InsertColumnIndex;
                PrintString("Введите индекс вставляемой колонки: ", ActiveString);
                cin >> InsertColumnIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                insert_column(Array, ArrayStrings, ArrayColumns, InsertColumnIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 23: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_column_back(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 24: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                pop_column_front(Array, ArrayStrings, ArrayColumns, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 25: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                int EraseColumnIndex;
                PrintString("Введите индекс удаляемой колонки: ", ActiveString);
                cin >> EraseColumnIndex; cin.ignore(INT32_MAX, '\n'); ActiveString++;
                erase_column(Array, ArrayStrings, ArrayColumns, EraseColumnIndex, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                break;
            case 26:
                quit = true;
                for (int i = 0; i < ArrayStrings; i++)
                {
                    delete Array[i];
                }
                delete[] Array;
                break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

template<typename T>
void FillRand(T*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = (double) (rand() % (MaxRand - MinRand) + MinRand);
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

template<typename T>
void FillRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            Array[i][j] = (double) (rand() % (MaxRand - MinRand) + MinRand);
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

template<typename T>
void Print(T* Array, const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
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
    PrintString("Текущий массив:", ActiveString);
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "*");
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            cout << Array[i][j] << "\t";
        }
        cout << endl;
        ActiveString++;
    }
    setlocale(LC_ALL, "Rus");
}

template <typename T>
void ReversePrint(T* Array, const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
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
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "*");
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        for (int j = ArrayColumns - 1; j >= 0; j--)
        {
            cout << " " << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
    setlocale(LC_ALL, "Rus");
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
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
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
    T MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
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
    T MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

template <typename T>
void shiftLeft(T*& Array, const int ArraySize, int ShiftValue, int& ActiveString)
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
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
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
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void shiftRight(T*& Array, const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

template <typename T>
void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

template <typename T>
void UniqueRand(T*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        T ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand);
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            T ArrayValue = (double) (rand() % (MaxRand - MinRand) + MinRand);
            while (ValueInArray(Array, ArrayValue, i, j, ArrayColumns))
            {
                ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
            }
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
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
void Sort(T*& Array, const int ArraySize, const bool SortByAscending, int& ActiveString)
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
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
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
    PrintString("Выполнено!", ActiveString);
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

    T* even = new T[evenSize];
    T* odd = new T[oddSize];

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
        cout << endl;
        ActiveString++;
        Print(even, evenSize, ActiveString);
    }
    if (oddSize > 0)
    {
        PrintString("Массив нечетных элементов: ", ActiveString);
        cout << endl;
        ActiveString++;
        Print(odd, oddSize, ActiveString);
    }

    if (evenSize > 0) delete[] even;
    if (oddSize > 0) delete[] odd;
}

template <typename T>
void push_back(T*& Array, int& ArraySize, const T AddedValue, int& ActiveString)
{
    T* NewArray = new T[ArraySize+1];
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    Array[ArraySize] = AddedValue;
    ArraySize++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void push_string_back(T**& Array, int& ArrayStrings, const int ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings+1];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    Array[ArrayStrings] = new T[ArrayColumns]{};
    ArrayStrings++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void push_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns+1];
    }

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
    }
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayColumns++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void push_front(T*& Array, int& ArraySize, const T AddedValue, int& ActiveString)
{
    T* NewArray = new T[ArraySize+1];
    NewArray[0] = AddedValue;
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArraySize++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void push_string_front(T**& Array, int& ArrayStrings, const int ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings+1];
    NewArray[0] = new T[ArrayColumns]{};
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayStrings++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void push_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns+1];
    }

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j+1] = Array[i][j];
        }
    }
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayColumns++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void insert(T*& Array, int& ArraySize, const T AddedValue, const int InsertIndex, int& ActiveString)
{
    T* NewArray = new T[ArraySize+1];

    for (int i = 0; i < InsertIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    NewArray[InsertIndex] = AddedValue;
    for (int i = InsertIndex; i < ArraySize; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArraySize++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void insert_string(T**& Array, int& ArrayStrings, const int ArrayColumns, const int InsertStringIndex, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings+1];
    for (int i = 0; i < InsertStringIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    NewArray[InsertStringIndex] = new T[ArrayColumns]{};
    for (int i = InsertStringIndex; i < ArrayStrings; i++)
    {
        NewArray[i+1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayStrings++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void insert_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int InsertColumnIndex, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns+1];
    }

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
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayColumns++;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_back(T*& Array, int& ArraySize, int& ActiveString)
{
    ArraySize--;
    T* NewArray = new T[ArraySize];
    for (int i = 0; i < ArraySize; i++)
    {
        NewArray[i] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_string_back(T**& Array, int& ArrayStrings, int& ActiveString)
{
    delete[] Array[ArrayStrings-1];
    ArrayStrings--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_column_back(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    ArrayColumns--;
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns];
    }

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            NewArray[i][j] = Array[i][j];
        }
    }
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_front(T*& Array, int& ArraySize, int& ActiveString)
{
    T* NewArray = new T[ArraySize-1];
    for (int i = 1; i < ArraySize; i++)
    {
        NewArray[i-1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArraySize--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_string_front(T**& Array, int& ArrayStrings, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings-1];
    delete[] Array[0];
    for (int i = 1; i < ArrayStrings; i++)
    {
        NewArray[i-1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayStrings--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void pop_column_front(T**& Array, const int ArrayStrings, int& ArrayColumns, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns-1];
    }

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 1; j < ArrayColumns; j++)
        {
            NewArray[i][j-1] = Array[i][j];
        }
    }
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArrayColumns--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void erase(T*& Array, int& ArraySize, const int EraseIndex, int& ActiveString)
{
    T* NewArray = new T[ArraySize-1];
    for (int i = 0; i < EraseIndex; i++)
    {
        NewArray[i] = Array[i];
    }
    for (int i = EraseIndex+1; i < ArraySize; i++)
    {
        NewArray[i-1] = Array[i];
    }
    delete[] Array;
    Array = NewArray;
    ArraySize--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void erase_string(T**& Array, int& ArrayStrings, const int EraseStringIndex, int& ActiveString)
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
    delete[] Array[EraseStringIndex];
    delete[] Array;
    Array = NewArray;
    ArrayStrings--;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void erase_column(T**& Array, const int ArrayStrings, int& ArrayColumns, const int EraseColumnIndex, int& ActiveString)
{
    T** NewArray = new T*[ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        NewArray[i] = new T[ArrayColumns-1];
    }
    ArrayColumns--;
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
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete[] Array[i];
    }
    delete[] Array;
    Array = NewArray;
    PrintString("Выполнено!", ActiveString);
}
