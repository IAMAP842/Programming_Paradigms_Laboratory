#include <bits/stdc++.h>
using namespace std;

struct Person
{
    string name;
    int age;
};

template <typename T>
void SortElements(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void PrintArray(const T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int N;
    cout << "Enter size N of array for all data types: ";
    cin >> N;

    int intArr[N];
    short shortArr[N];
    float floatArr[N];
    double doubleArr[N];
    long longArr[N];

    cout << "Enter values for int array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> intArr[i];
    }

    cout << "Enter values for short array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> shortArr[i];
    }

    cout << "Enter values for float array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> floatArr[i];
    }

    cout << "Enter values for double array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> doubleArr[i];
    }

    cout << "Enter values for long array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> longArr[i];
    }

    const int sizeIntArr = sizeof(intArr) / sizeof(int);
    const int sizeShortArr = sizeof(shortArr) / sizeof(short);
    const int sizeFloatArr = sizeof(floatArr) / sizeof(float);
    const int sizeDoubleArr = sizeof(doubleArr) / sizeof(double);
    const int sizeLongArr = sizeof(longArr) / sizeof(long);

    cout << "Original int array: ";
    PrintArray(intArr, sizeIntArr);
    SortElements(intArr, sizeIntArr);
    cout << "Sorted int array: ";
    PrintArray(intArr, sizeIntArr);

    cout << "Original short array: ";
    PrintArray(shortArr, sizeShortArr);
    SortElements(shortArr, sizeShortArr);
    cout << "Sorted short array: ";
    PrintArray(shortArr, sizeShortArr);

    cout << "Original float array: ";
    PrintArray(floatArr, sizeFloatArr);
    SortElements(floatArr, sizeFloatArr);
    cout << "Sorted float array: ";
    PrintArray(floatArr, sizeFloatArr);

    cout << "Original double array: ";
    PrintArray(doubleArr, sizeDoubleArr);
    SortElements(doubleArr, sizeDoubleArr);
    cout << "Sorted double array: ";
    PrintArray(doubleArr, sizeDoubleArr);

    cout << "Original long array: ";
    PrintArray(longArr, sizeLongArr);
    SortElements(longArr, sizeLongArr);
    cout << "Sorted long array: ";
    PrintArray(longArr, sizeLongArr);

    Person people[N];
    cout << "Enter values for Person array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter name for person " << i + 1 << ": ";
        cin >> people[i].name;
        cout << "Enter age for person " << i + 1 << ": ";
        cin >> people[i].age;
    }

    // SortElements(people, N);
}