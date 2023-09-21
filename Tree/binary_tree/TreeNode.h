#ifndef TreeNode_h
#define TreeNode_h

class TreeNode
{
private:
    friend class Tree;
    int data;
    TreeNode *lchild;
    TreeNode *rchild;

public:
    TreeNode(int x) : lchild(nullptr), rchild(nullptr), data(x) {}
};

#endif