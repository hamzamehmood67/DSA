#include <iostream>
#include "../Stack_Array_Implementation/stack.h"

using namespace std;

int main()
{
    STACK obj(5);

    obj.push(5);
    obj.push(3);

    obj.display();
}