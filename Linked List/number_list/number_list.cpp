#include <iostream>
#include "number_list.h"

using namespace std;

void NumberList::append(double value)
{
    Node *newNode;
    Node *ptr;

    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        ptr = head;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }
}

void NumberList::display()
{
    Node *ptr;
    ptr = head;
    while (ptr)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
}

// Insert the value at sorted position
void NumberList::insert(double value)
{
    Node *newNode = new Node;
    Node *ptr;
    Node *prevoiusNode = nullptr;

    newNode->data = value;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        ptr = head;

        while (ptr != nullptr && ptr->data < value)
        {
            prevoiusNode = ptr;
            ptr = ptr->next;
        }

        if (prevoiusNode)
        {
            prevoiusNode->next = newNode;
            newNode->next = ptr;
        }
        else
        {

            head = newNode;
            newNode->next = ptr;
        }
    }
}

/// Delete the Node

void NumberList::deleteNode(double value)
{
    Node *ptr;
    ptr = head;
    Node *prevoiusNode = nullptr;

    if (head->data == value)
    {
        ptr = head;
        head = head->next;
        delete ptr;
    }
    else
    {
        while (ptr != nullptr && ptr->data != value)
        {
            prevoiusNode = ptr;
            ptr = ptr->next;
        }

        if (ptr)
        {
            prevoiusNode->next = ptr->next;
            delete ptr;
        }
    }
}

NumberList::~NumberList()
{
    int count{1};
    Node *ptr;
    Node *nextNode;

    ptr = head;

    while (ptr)
    {
        nextNode = ptr->next;
        delete ptr;
        ptr = nextNode;
        cout << count++ << " node is Deleted" << endl;
    }

    cout << "All nodes are deleted";
}

void NumberList::reverse()
{
    Node *ptr = head;
    traverse(ptr);
}

void traverse(Node *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        traverse(ptr->next);
        cout << ptr->data << ' ';
    }
}