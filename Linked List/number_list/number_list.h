#ifndef __number_list__
#define __number_list__

struct Node
{
    double data;
    struct Node *next;
};

class NumberList
{
private:
    struct Node *head;

public:
    NumberList()
    {
        head = nullptr;
    }

    void append(double);
    void insert(double);
    void display();
    void deleteNode(double);
    ~NumberList();
    void reverse();
};

#endif