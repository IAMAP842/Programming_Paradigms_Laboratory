#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyStack
{
private:
    T *stackArray;
    int top;
    int maxSize;

public:
    MyStack(int size) : top(-1), maxSize(size)
    {
        stackArray = new T[maxSize];
    }

    ~MyStack()
    {
        delete[] stackArray;
    }

    void Push(T element)
    {
        if (top < maxSize - 1)
        {
            stackArray[++top] = element;
            cout << "Element " << element << " pushed into the stack." << endl;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    T Pop()
    {
        if (top >= 0)
        {
            cout << "Element " << stackArray[top] << " popped from the stack." << endl;
            return stackArray[top--];
        }
        else
        {
            cout << "Stack Underflow!" << endl;
            return T();
        }
    }

    int MaxSize()
    {
        return maxSize;
    }

    int CurrentSize()
    {
        return top + 1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    void Display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyStack<int> intStack(5);
    intStack.Push(1);
    intStack.Push(2);
    intStack.Push(3);
    intStack.Push(4);
    intStack.Push(5);
    intStack.Push(6); // overflow

    cout << "Current size of intStack: " << intStack.CurrentSize() << endl;
    intStack.Pop();
    intStack.Pop();
    intStack.Pop();
    intStack.Pop();
    intStack.Pop();
    intStack.Pop(); // underflow

    cout << "Max size of intStack: " << intStack.MaxSize() << endl;
    cout << "Is intStack empty? " << (intStack.IsEmpty() ? "Yes" : "No") << endl;
    intStack.Display();

    MyStack<float> floatStack(3);
    floatStack.Push(1.1);
    floatStack.Push(2.2);
    floatStack.Push(3.3);
    floatStack.Push(4.4); // overflow

    return 0;
}