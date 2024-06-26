#ifndef Bst_h
#define Bst_h

#include "TreeNode.h"

class Bst
{
private:
    TreeNode *root;
    void inOrderRecursive(TreeNode *);

public:
    Bst() : root(nullptr) {}
    void insert(int);
    TreeNode *search(int);
    void inOrderTaversal();
};

#endif