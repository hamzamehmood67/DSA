#ifndef List_h
#define List_h

#include "LISTNODE.h"

class List
{
private:
    Node *head;
    Node *LastNode;

public:
    List()
    {
        head = LastNode = nullptr;
    }
    List(List &);
    ~List();

    void insertAtFront(int);
    void insertAtEnd(int);
    bool deleteFromFront(int &);
    bool deleteFromEnd(int &);
    bool isEmpty();
    void display();
    void insertAtPos(int, int);
    void deleteAtPos(int &, int);
    void reverse();
    bool isSorted();
    Node *getHead();
    Node *getLastNode();
    // void operator+(List &);

    // void concatinate(List &);
};

#endif