#include <iostream>
#include "doublyLL.h"
using namespace std;

void DoublyLL::insertAtFront(int data)
{
    Node *newNode = new Node(data);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void DoublyLL::insertAtEnd(int data)
{
    Node *newNode = new Node(data);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->previous = ptr;
    }
}

void DoublyLL::display()
{
    Node *ptr = head;

    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void DoublyLL::reverseDisplay()
{
    Node *ptr = head;

    while (ptr->next)
        ptr = ptr->next;

    while (ptr)
    {
        cout << ptr->data << ' ';
        ptr = ptr->previous;
    }
    cout << endl;
}

void DoublyLL::reverse()
{
    Node *ptr = head;

    while (ptr)
    {
        // Node *temp = ptr->next;
        // ptr->next = ptr->previous;
        // ptr->previous = temp;

        swap(ptr->next, ptr->previous);
        head = ptr;
        ptr = ptr->previous;
    }

    // head=ptr
}

void swap(Node *&link1, Node *&link2)
{
    Node *temp = link1;
    link1 = link2;
    link2 = temp;
}

void DoublyLL::insertAtPos(int data, int pos)
{
    Node *newNode = new Node(data);

    Node *ptr = head;

    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }

    newNode->next = ptr;
    newNode->previous = ptr->previous;
    newNode->previous->next = newNode;
    ptr->previous = newNode;
}

void DoublyLL::deleteFromFront()
{
    Node *temp = head;

    head = head->next;
    head->previous = nullptr;
    delete temp;
}

// void DoublyLL::deleteFromEnd()
// {
//     Node *ptr = head;

//     while (ptr->next)
//         ptr = ptr->next;

//     ptr->previous->next=
// }