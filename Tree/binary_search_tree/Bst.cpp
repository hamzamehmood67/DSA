#include <iostream>
#include "Bst.h"

using namespace std;

void Bst::insert(int data)
{
    TreeNode *ptr = root;
    TreeNode *tailPtr = nullptr;

    while (ptr)
    {
        tailPtr = ptr;

        if (data == ptr->data)
        {
            return;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            ptr = ptr->lchild;
        }
    }
}

void Bst::inOrderRecursive(TreeNode *root)
{
    if (root)
    {
        inOrderRecursive(root->lchild);
        cout << root->data << " ";
        inOrderRecursive(root->rchild);
    }
}

void Bst::inOrderTaversal()
{
    inOrderRecursive(root);
}