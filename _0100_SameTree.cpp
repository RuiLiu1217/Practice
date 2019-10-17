#include "headers.hpp"

bool LeetCode::_0100_SameTree::isSameTree(TreeNode<int> *p, TreeNode<int> *q) {
    if (p==nullptr && q==nullptr)
    {
        return true;
    }
    if ((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr))
    {
        return false;
    }
    if(p->val != q->val)
    {
        return false;
    }
    else
    {
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
    
}