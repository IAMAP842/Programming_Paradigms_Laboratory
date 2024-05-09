#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int *stackArray;
    int top;
    int maxSize;

public:
    MyStack(int size) : top(-1), maxSize(size)
    {
        stackArray = new int[maxSize];
    }

    MyStack(const MyStack &other) : top(other.top), maxSize(other.maxSize)
    {
        stackArray = new int[maxSize];
        for (int i = 0; i <= top; ++i)
        {
            stackArray[i] = other.stackArray[i];
        }
    }

    ~MyStack()
    {
        delete[] stackArray;
    }

    void Push(int element)
    {
        if (top == maxSize - 1)
        {
            cout << "Stack overflow! Cannot push element " << element << endl;
            return;
        }
        stackArray[++top] = element;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        top--;
    }

    int MaxSize() const
    {
        return maxSize;
    }

    int CurrentSize() const
    {
        return top + 1;
    }

    bool IsEmpty() const
    {
        return top == -1;
    }

    void Display() const
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack content:" << endl;
        for (int i = top; i >= 0; --i)
        {
            cout << stackArray[i] << endl;
        }
    }

    MyStack &operator=(const MyStack &other)
    {
        if (this == &other)
            return *this;
        delete[] stackArray;
        top = other.top;
        maxSize = other.maxSize;
        stackArray = new int[maxSize];
        for (int i = 0; i <= top; ++i)
        {
            stackArray[i] = other.stackArray[i];
        }
        return *this;
    }
};

int main()
{
    // basic stack functionality
    MyStack stack1(5);
    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);
    stack1.Push(4);
    stack1.Push(5);

    cout << "Stack 1 Details:" << endl;
    stack1.Display();
    cout << "Current Size: " << stack1.CurrentSize() << endl;
    cout << "Max Size: " << stack1.MaxSize() << endl;
    cout << "Is Empty: " << (stack1.IsEmpty() ? "Yes" : "No") << endl;

    stack1.Pop();
    cout << "After popping one element from Stack 1:" << endl;
    stack1.Display();

    // multiple stack instantiation
    MyStack stack2(3);
    stack2.Push(10);
    stack2.Push(20);
    stack2.Push(30);

    cout << "\nStack 2 Details:" << endl;
    stack2.Display();
    cout << "Current Size: " << stack2.CurrentSize() << endl;
    cout << "Max Size: " << stack2.MaxSize() << endl;
    cout << "Is Empty: " << (stack2.IsEmpty() ? "Yes" : "No") << endl;

    // copy constructor
    MyStack stack3 = stack1;
    cout << "\nStack 3 (created from Stack 1 using copy constructor) Details:" << endl;
    stack3.Display();

    // assignment operator
    stack3 = stack2;
    cout << "\nAfter updating Stack 3 from Stack 2 using assignment operator:" << endl;
    stack3.Display();

    return 0;
}
