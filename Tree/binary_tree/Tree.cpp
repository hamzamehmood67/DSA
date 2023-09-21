#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

void Tree::create()
{

    queue<TreeNode *> qt;
    TreeNode *ptr = root;
    int data{};
    cout << "Enter the root Node" << endl;
    cin >> data;
    root = new TreeNode(data);
    qt.push(root);
    while (qt.size() != 0)
    {
        ptr = qt.front();
        qt.pop();

        cout << "Enter the Left Node of " << ptr->data << endl;
        cin >> data;
        if (data != -1)
        {
            TreeNode *newNode = new TreeNode(data);
            ptr->lchild = newNode;
            qt.push(newNode);
        }

        cout << "Enter the Right Node of " << ptr->data << endl;
        cin >> data;
        if (data != -1)
        {
            TreeNode *newNode = new TreeNode(data);
            ptr->rchild = newNode;
            qt.push(newNode);
        }
    }
}

void Tree::preOrderTraversal(TreeNode *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrderTraversal(root->lchild);
        preOrderTraversal(root->rchild);
    }
}

void Tree::DisplayPreOrder()
{
    preOrderTraversal(root);
}