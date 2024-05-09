#include <iostream>

using namespace std;

template <class T>
struct MyStack
{
    int size;
    int n;
    T *arr;
};

template <class T>
MyStack<T> initStack(int size)
{
    MyStack<T> stk;
    stk.n = -1;
    stk.size = size;
    stk.arr = new T[size];
    return stk;
}

template <class T>
void pushStack(MyStack<T> &s, T d)
{
    if (s.size - 2 < s.n)
    {
        cout << "Stack is already full, can't insert " << d << endl;
        return;
    }

    s.arr[++(s.n)] = d;
}

template <class T>
T popStack(MyStack<T> &s, T &d)
{
    if (s.n == -1)
    {
        cout << "Stack is already empty, can't delete any" << endl;
        return -1;
    }
    d = s.arr[s.n];
    (s.n)--;
    return d;
}

template <class T>
void printStack(MyStack<T> &s)
{
    int n = s.n;

    cout << "Current stack is : ";
    T *arr = s.arr;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void loadStack(MyStack<T> &s)
{
    int n;
    T a;
    cout << "How many elements you want to push ";
    cin >> n;
    cout << "Type the elements one by one: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pushStack(s, a);
    }
}

template <class T>
int currStackSize(MyStack<T> &s)
{
    return s.n + 1;
}

template <class T>
int MaxStackSize(MyStack<T> &s)
{
    return s.size;
}

template <class T>
void unloadStack(MyStack<T> &s)
{
    int n;
    T a;
    cout << "How many elements you want to pop ";
    cin >> n;
    cout << "The deleted elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << popStack(s, a) << " ";
    }
    cout << endl;
}

int main()
{
    int n1, n2;
    cout << "Enter the size of first stack : ";
    cin >> n1;
    MyStack<double> s1 = initStack<double>(n1);
    loadStack(s1);
    printStack(s1);
    unloadStack(s1);
    cout << "Stack 1 maxSize and current size are " << MaxStackSize(s1) << " and " << currStackSize(s1) << endl;

    cout << "Enter the size of second stack : ";
    cin >> n2;
    MyStack<double> s2 = initStack<double>(n2);
    loadStack(s2);
    printStack(s2);
    unloadStack(s2);

    printStack(s1);
    printStack(s2);

    return 0;
}