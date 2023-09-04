#ifndef __stack.h__
#define __stach .h__

class STACK
{
private:
    int *arr;
    int top;
    int size;

public:
    STACK(int s);
    void push(int element);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int _size();
    void display();
};

#endif