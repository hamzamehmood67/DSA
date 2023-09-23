#ifndef TreeNode_h
#define TreeNode_h

class TreeNode
{
private:
    friend class Bst;
    int data;
    TreeNode *lchild;
    TreeNode *rchild;

public:
    TreeNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

#endif