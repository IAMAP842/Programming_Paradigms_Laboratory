#include <bits/stdc++.h>
using namespace std;
struct MyStack
{
    int maxSize;
    int *data;
    int top;

    void Input_size(int size)
    {
        maxSize = size;
        data = new int[size];
        top = -1;
    }

    void Push(int value)
    {
        if (top < maxSize - 1)
        {
            data[++top] = value;
        }
        else
        {
            cout << "Stack overflow!\n";
        }
    }

    void Pop()
    {
        if (top >= 0)
        {
            cout << "Popped element is: " << data[top--] << endl;
        }
        else
        {
            cout << "Stack underflow!\n";
        }
    }

    int GetMaxSize() const
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
};

int main()
{
    int a1, a2;
    MyStack stack1, stack2;
    cout << "Enter maximum size of stack 1" << endl;
    cin >> a1;
    cout << "Enter maximum size of stack 2" << endl;
    cin >> a2;
    stack1.Input_size(a1);
    stack2.Input_size(a2);

    for (int i = 1; i <= a1; ++i)
    {
        stack1.Push(i * 2);
    }

    cout << "Stack 1:\n";
    cout << "Maximum Size: " << stack1.GetMaxSize() << "\n";

    while (!stack1.IsEmpty())
    {
        stack1.Pop();
        cout << "Current Size: " << stack1.CurrentSize() << "\n";
        if (stack1.CurrentSize() == 0)
        {
            cout << "This Stack is empty now!" << endl;
        }
    }
    for (int i = 1; i <= a2; ++i)
    {
        stack2.Push(i * 3);
    }

    cout << "\nStack 2:\n";
    cout << "Maximum Size: " << stack2.GetMaxSize() << "\n";
    while (!stack2.IsEmpty())
    {
        stack2.Pop();
        cout << "Current Size: " << stack2.CurrentSize() << "\n";
        if (stack2.CurrentSize() == 0)
        {
            cout << "This Stack is empty now!" << endl;
        }
    }
    cout << "Therefore multiple stack can be instantiated and can co-exists independently" << endl;
}