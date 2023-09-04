#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

class Node
{
private:
    friend class List;
    int data;
    Node *next;

public:
    Node(int value) : data(value), next(nullptr)
    {
    }

    // int getData()
    // {
    //     return data;
    // }

    // Node *getNext()
    // {
    //     return next;
    // }

    // void setData(int value)
    // {
    //     data = value;
    // }
    // void setNext(Node *address)
    // {
    //     next = address;
    // }
};

#endif