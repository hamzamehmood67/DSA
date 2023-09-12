#include <iostream>
#include "doublyLL.h"

using namespace std;

int main()
{
    DoublyLL list1;

    list1.insertAtEnd(3);
    list1.insertAtEnd(5);
    list1.insertAtEnd(7);
    list1.insertAtPos(45, 3);
    // list1.insertAtFront(3);
    // list1.insertAtFront(6);
    // list1.insertAtFront(1);

    list1.insertAfterGivenData(45, 100);
    list1.display();

    // list1.deleteFromFront();
    // list1.display();

    // list1.reverseDisplay();
}