#include "headers.hpp"

TreeNode<int> *_0235_LowestCommonAncestor::lowestCommonAncestorRecursive(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestorRecursive(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestorRecursive(root->right, p, q);
    }
    return root;
}

TreeNode<int> *_0235_LowestCommonAncestor::lowestCommonAncestorIterative(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (!root)
    {
        return nullptr;
    }
    TreeNode<int> *t = root;
    while (1)
    {
        if (t->val > p->val && t->val > q->val)
        {
            t = t->left;
        }
        else if (t->val < p->val && t->val < q->val)
        {
            t = t->right;
        }
        else
        {
            return t;
        }
    }
}