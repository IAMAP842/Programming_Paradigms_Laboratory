#include <iostream>
using namespace std;

template <typename T>
struct MyStruct
{
    T x, y;
};

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
            cout << "Element pushed into the stack." << endl;
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
            cout << "Element popped from the stack." << endl;
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
            cout << stackArray[i].x << "," << stackArray[i].y << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyStack<MyStruct<int>> structStack(5);
    MyStruct<int> s1 = {1, 2};
    MyStruct<int> s2 = {3, 4};
    MyStruct<int> s3 = {5, 6};
    MyStruct<int> s4 = {7, 8};
    MyStruct<int> s5 = {9, 10};
    MyStruct<int> s6 = {11, 12};

    structStack.Push(s1);
    structStack.Push(s2);
    structStack.Push(s3);
    structStack.Push(s4);
    structStack.Push(s5);
    structStack.Push(s6); // overflow

    cout << "Current size of structStack: " << structStack.CurrentSize() << endl;
    structStack.Pop();
    structStack.Pop();
    structStack.Pop();
    structStack.Pop();
    structStack.Pop();
    structStack.Pop(); // underflow

    cout << "Max size of structStack: " << structStack.MaxSize() << endl;
    cout << "Is structStack empty? " << (structStack.IsEmpty() ? "Yes" : "No") << endl;
    structStack.Display();

    return 0;
}