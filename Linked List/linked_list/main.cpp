#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    int deletedvalue{};
    List obj;

    obj.insertAtFront(9);
    obj.insertAtEnd(5);
    obj.insertAtEnd(6);
    obj.insertAtFront(2);
    obj.insertAtFront(5);

    // obj.insertAtEnd(17);

    obj.display();
    cout << endl;

    // cout << "Values before deletion\n";
    // obj.display();
    // cout << endl;

    // if (obj.deleteFromFront(deletedvalue))
    //     cout << deletedvalue << " has been succesfully deleted from node" << endl;
    // else
    //     cout << "Value deletion is unsuccessful" << endl;

    // if (obj.deleteFromEnd(deletedvalue))
    //     cout << deletedvalue << " has been succesfully deleted from node" << endl;
    // else
    //     cout << "Value deletion is unsuccessful" << endl;

    // cout << "Values After deletion\n";
    // obj.display();
    // cout << endl;

    // obj.insertAtPos(5, 0);
    // obj.insertAtPos(3, 1);
    // obj.insertAtPos(2, 2);
    // obj.display();
    // cout << endl;

    // obj.deleteAtPos(deletedvalue, 2);
    // cout << deletedvalue << " has been deleted from the List" << endl;

    // obj.reverse();

    // if (obj.isSorted())
    // {
    //     cout << "List is sorted\n";
    // }
    // else
    // {
    //     cout << "Not Sorted\n";
    // }

    List obj2(obj);
    cout << "This is second object\n";
    obj2.display();
    cout << endl;

    // obj2.reverse();

    // if (obj2.isSorted())
    //     cout << "obj2 is sorted\n";
    // else
    //     cout << "obj2 is Not sorted\n";
    // obj2.display();
    // cout << endl;

        return 0;
}