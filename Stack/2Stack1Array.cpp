#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    vector<int> ar;
    int top1 = 0, top2 = 0, size = -1;

public:
    TwoStack(int n) : ar(n), top1(-1), top2(n), size(n) {};

    bool push1(int data)
    {
        if (top1 + 1 >= top2)
        {
            return false;
        }
        ar[++top1] = data;
        return true;
    }

    bool push2(int data)
    {
        if (top2 - 1 <= top1)
        {
            return false;
        }
        ar[--top2] = data;
        return true;
    }

    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        return ar[top1--];
    }

    int pop2()
    {
        if (top2 == size)
        {
            return -1;
        }
        return ar[top2++];
    }

    int size1()
    {
        return top1 + 1;
    }

    int size2()
    {
        return (size - top2);
    }

    void printStack1()
    {
        for (int i = 0; i <= top1; ++i)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }

    void printStack2()
    {
        for (int i = size - 1; i >= top2; --i)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    TwoStack obj(10);

    cout << obj.push1(2) << " " << obj.push1(4) << " " << obj.push1(6) << endl;
    cout << obj.push2(1) << " " << obj.push2(3) << " " << obj.push2(5) << endl;

    cout << "Size of stack1: " << obj.size1() << endl;
    cout << "Size of stack2: " << obj.size2() << endl;

    cout << "Stack1 contents: ";
    obj.printStack1();

    cout << "Stack2 contents: ";
    obj.printStack2();

    return 0;
}