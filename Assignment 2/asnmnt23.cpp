#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

struct MyStruct
{
    int value1;
    int value2;
    char charValue;
};

template <>
void Swap<MyStruct>(MyStruct &a, MyStruct &b)
{
    Swap(a.value1, b.value1);
    Swap(a.value2, b.value2);
    Swap(a.charValue, b.charValue);
}

int main()
{
    int num1 = 5, num2 = 10;
    cout << "Before Swap - num1: " << num1 << ", num2: " << num2 << endl;
    Swap(num1, num2);
    cout << "After Swap - num1: " << num1 << ", num2: " << num2 << endl;

    double dbl1 = 3.14, dbl2 = 6.28;
    cout << "\nBefore Swap - double1: " << dbl1 << ", double2: " << dbl2 << endl;
    Swap(dbl1, dbl2);
    cout << "After Swap - double1: " << dbl1 << ", double2: " << dbl2 << endl;

    float float1 = 1.23f, float2 = 4.56f;
    cout << "\nBefore Swap - float1: " << float1 << ", float2: " << float2 << endl;
    Swap(float1, float2);
    cout << "After Swap - float1: " << float1 << ", float2: " << float2 << endl;

    short short1 = 2, short2 = 8;
    cout << "\nBefore Swap - short1: " << short1 << ", short2: " << short2 << endl;
    Swap(short1, short2);
    cout << "After Swap - short1: " << short1 << ", short2: " << short2 << endl;

    MyStruct struct1 = {42, 10, 'A'};
    MyStruct struct2 = {99, 20, 'B'};
    cout << "\nBefore Swap - struct1.value1: " << struct1.value1 << ", struct1.value2: " << struct1.value2 << ", struct1.charValue: " << struct1.charValue << endl;
    cout << "Before Swap - struct2.value1: " << struct2.value1 << ", struct2.value2: " << struct2.value2 << ", struct2.charValue: " << struct2.charValue << endl;

    Swap(struct1, struct2);

    cout << "\nAfter Swap - struct1.value1: " << struct1.value1 << ", struct1.value2: " << struct1.value2 << ", struct1.charValue: " << struct1.charValue << endl;
    cout << "After Swap - struct2.value1: " << struct2.value1 << ", struct2.value2: " << struct2.value2 << ", struct2.charValue: " << struct2.charValue << endl;

    return 0;
}