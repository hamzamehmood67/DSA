#include <iostream>
#include "number_list.h"

using namespace std;

int main()
{
    NumberList obj;
    obj.append(3);
    obj.append(7);

    obj.insert(5);
    obj.insert(1);
    obj.insert(9);

        obj.insert(60);

    obj.display();

    obj.reverse();
}