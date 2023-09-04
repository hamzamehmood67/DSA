#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    STACK s1(5);
    s1.push(5);
    s1.push(2);
    s1.push(3);
    s1.push(8);
    s1.push(9);
    s1.push(10);

    cout << "The size of Stack is " << s1._size() << endl;

    s1.display();
}