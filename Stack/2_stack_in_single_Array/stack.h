#ifndef __stack.h__
#define __stack .h__

class doubleStack
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    doubleStack(int);
    void push1(int);
    void push2(int);
    void pop1();
    void pop2();
    int peek1();
    int peek2();
    ~doubleStack();
};

#endif