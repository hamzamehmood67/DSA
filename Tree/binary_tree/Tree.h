#ifndef Tree_h
#define Tree_h

#include "TreeNode.h"

class Tree
{
private:
    TreeNode *root;
    void preOrderTraversal(TreeNode *);

public:
    Tree() : root(nullptr){};
    void create();

    void DisplayPreOrder();
};

#endif