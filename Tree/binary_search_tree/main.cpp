#include <iostream>
#include "Bst.h"

using namespace std;

int main()
{
    Bst tree;
    tree.insert(10);
    tree.insert(15);
    tree.insert(9);

    tree.inOrderTaversal();

    return 0;
}