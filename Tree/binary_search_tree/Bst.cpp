#include <iostream>
#include "Bst.h"

using namespace std;

void Bst::insert(int data)
{
    if (!root)
    {
        root = new TreeNode(data);
        return;
    }
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

    TreeNode *newNode = new TreeNode(data);
    if (data < tailPtr->data)
        tailPtr->lchild = newNode;
    else if (data > tailPtr->data)
        tailPtr->rchild = newNode;
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

TreeNode *Bst::search(int key)
{
    TreeNode *ptr = root;

    if (ptr == nullptr)
    {
        return nullptr;
    }

    while (ptr)
    {
        if (key < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else if (key > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            cout << ptr->data << " data is found\n";
            return ptr;
        }
    }

    return nullptr;
}