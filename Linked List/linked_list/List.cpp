#include <iostream>
#include "List.h"

using namespace std;

void List::insertAtFront(int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = LastNode = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void List::display()
{
    Node *ptr = head;

    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void List::insertAtEnd(int value)
{
    Node *newNode = new Node(value);

    if (LastNode == nullptr)
        head = LastNode = newNode;
    else
    {
        LastNode->next = newNode;
        LastNode = newNode;
    }
}

bool List::deleteFromFront(int &value)
{
    if (head == nullptr)
    {
        cout << "List is Empty";
        return false;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        value = temp->data;
        delete temp;

        return true;
    }
}

bool List::deleteFromEnd(int &value)
{
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return false;
    }
    else
    {
        Node *NodePtr = head;
        Node *temp = LastNode;
        while (NodePtr->next != LastNode)
            NodePtr = NodePtr->next;

        LastNode = NodePtr;
        LastNode->next = nullptr;
        value = temp->data;
        delete temp;

        return true;
    }
}

bool List::isEmpty()
{
    return head == nullptr;
}

void List::insertAtPos(int value, int pos)
{

    Node *nodePtr = head;
    Node *newNode = new Node(value);

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1 && nodePtr; i++)
        {
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}

void List::deleteAtPos(int &value, int pos)
{
    Node *currPtr = head;
    Node *previous = nullptr;

    if (pos == 0)
    {
        head = head->next;
        value = currPtr->data;
        delete currPtr;
    }
    else
    {
        for (int i = 0; i < pos && currPtr; i++)
        {
            previous = currPtr;
            currPtr = currPtr->next;
        }

        previous->next = currPtr->next;
        value = currPtr->data;
        delete currPtr;
    }
}

List::~List()
{
    Node *nextNode;
    Node *previou = head;
    int count{1};
    while (previou != nullptr)
    {
        nextNode = previou->next;
        delete previou;
        previou = nextNode;
        // cout << count++ << " node has been deleted so far" << endl;
    }
    // cout << "All nodes are deleted from list" << endl;
}

void List::reverse()
{
    Node *first = head;
    Node *second = nullptr;
    Node *third = nullptr;

    while (first != nullptr)
    {
        third = second;
        second = first;

        first = first->next;
        second->next = third;
    }
    head = second;
}

bool List::isSorted()
{
    Node *ptr = head->next;
    Node *previous = head;

    while (ptr)
    {
        if (ptr->data < previous->data)
        {
            return false;
        }
        previous = ptr;
        ptr = ptr->next;
    }

    return true;
}

Node *List::getHead()
{
    return head;
}

Node *List::getLastNode()
{
    return LastNode;
}

List::List(List &right)
{
    Node *ptr = right.getHead();
    while (ptr)
    {
        this->insertAtEnd(ptr->data);

        ptr = ptr->next;
    }
}

// void List::concatinate(List &right)
// {
//     Node *rightHead = right.head;

//     this->LastNode = rightHead;
//     this->LastNode = right.LastNode;
// }