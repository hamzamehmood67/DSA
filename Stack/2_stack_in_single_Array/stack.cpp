#include <iostream>
#include "stack.h"
using namespace std;

doubleStack::doubleStack(int s)
{
    int size = s;
    arr = new int[size];
    top1 = -1;
    top2 = size;
}

void doubleStack::push1(int element)
{
    if (top2 - top1 > 1)
    {
        top1++;
        arr[top1] = element;
        cout << top1;
    }
    else
    {
        cout << "Stack is Full" << endl;
    }
}
void doubleStack::push2(int element)
{
    if (top2 - top1 >= 1)
    {
        top2--;
        arr[top2] = element;
    }
    else
    {
        cout << "Stack is Full" << endl;
    }
}

void doubleStack::pop1()
{
    if (top1 < 0)
    {
        cout << "The Stack is empty" << endl;
    }
    else
    {
        top1++;
    }
}
void doubleStack::pop2()
{
    if (top2 >= size)
    {
        cout << "The Stack is empty" << endl;
    }
    else
    {
        top2--;
    }
}

int doubleStack::peek1()
{
    if (top1 < 0)
    {
        cout << "The Stack is empty" << endl;
    }
    else
    {
        arr[top1];
    }
}
int doubleStack::peek2()
{
    if (top2 >= size)
    {
        cout << "The Stack is empty" << endl;
    }
    else
    {
        arr[top2];
    }
}

doubleStack::~doubleStack()
{
    delete[] arr;
}