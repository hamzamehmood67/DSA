#include <iostream>
#include "stack.h"

using namespace std;

STACK::STACK(int s)
{
    this->size = s;
    arr = new int[size];
    top = -1;
}

void STACK::push(int element)
{
    if (isFull())
    {
        cout << "Stack Is overflow" << endl;
    }
    else
    {
        top++;
        arr[top] = element;
    }
}

void STACK::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        top--;
    }
}

int STACK::peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        return arr[top];
    }
}

bool STACK::isEmpty()
{
    if (top >= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool STACK::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int STACK::_size()
{
    return top + 1;
}

void STACK::display()
{
    int s = top + 1;
    for (int i = 0; i < s; i++)
    {
        cout << peek() << " ";
        pop();
    }
}