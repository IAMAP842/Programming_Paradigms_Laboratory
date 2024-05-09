#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    static int stack_count_limit;
    static int stack_count;
    int *arr;
    int top;
    int size;

public:
    Stack(int size) : size(size), top(-1)
    {
        if (stack_count >= stack_count_limit)
        {
            throw runtime_error("Cannot create more stacks. Limit reached.");
        }
        arr = new int[size];
        stack_count++;
    }

    Stack(const Stack &other) : size(other.size), top(other.top)
    {
        arr = new int[size];
        for (int i = 0; i <= top; i++)
        {
            arr[i] = other.arr[i];
        }
        stack_count++;
    }

    ~Stack()
    {
        delete[] arr;
        stack_count--;
    }

    void Push(int ele)
    {
        if (top == size - 1)
            cout << "Stack Overflow !!!" << endl;
        else
            arr[++top] = ele;
    }

    int Pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow !!!" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    int Maxsize() const
    {
        return size;
    }

    int Currentsize() const
    {
        return top + 1;
    }

    int Is_empty() const
    {
        return (top == -1) ? 1 : 0;
    }

    void Display() const
    {
        cout << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    Stack &operator=(const Stack &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] arr;
        size = other.size;
        top = other.top;
        arr = new int[size];
        for (int i = 0; i <= top; i++)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    Stack operator+(const Stack &other) const
    {
        Stack result(this->size + other.size);
        for (int i = 0; i <= top; i++)
        {
            result.Push(arr[i]);
        }
        for (int i = 0; i <= other.top; i++)
        {
            result.Push(other.arr[i]);
        }
        return result;
    }

    static void setStackLimit(int limit)
    {
        stack_count_limit = limit;
    }

    static int getStackCount()
    {
        return stack_count;
    }
};

int Stack::stack_count_limit = 0;
int Stack::stack_count = 0;

int main()
{
    Stack::setStackLimit(3);

    try
    {
        Stack stackA(3);
        stackA.Push(1);
        stackA.Push(2);
        stackA.Push(-5);
        Stack stackB(3);
        stackB.Push(3);
        stackB.Push(4);
        stackB.Push(10);

        cout << "initial stacks: " << endl;
        stackA.Display();
        stackB.Display();

        Stack stackC = stackA + stackB;
        cout << "contents of stack c after addition of two stacks a&b:" << endl;
        stackC.Display();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}