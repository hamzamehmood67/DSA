#ifndef doublyLL_h
#define doublyLL_h

#include "Node.h"

class DoublyLL
{
private:
    Node *head;

public:
    DoublyLL() : head(nullptr)
    {
    }

    void insertAtFront(int);
    void insertAtEnd(int);

    void deleteFromFront();
    // void deleteFromEnd();

    void reverse();
    void display();
    void reverseDisplay();

    void insertAtPos(int, int);
};

#endif