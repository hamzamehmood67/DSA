#ifndef Node_h
#define Node_h

class Node
{
private:
    friend class DoublyLL;
    int data;
    Node *next;
    Node *previous;

public:
    Node(int x) : next(nullptr), previous(nullptr), data(x)
    {
    }
};

#endif