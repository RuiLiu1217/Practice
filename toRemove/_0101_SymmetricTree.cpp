#include "headers.hpp"

bool LeetCode::_0101_SymmetricTree::isSymmetric(TreeNode<int>* root) {
    return preOrderIter(root);
}

bool LeetCode::_0101_SymmetricTree::preOrderIter(TreeNode<int>* root) {
    using Treenode = TreeNode<int>;
    Treenode *p = root;
    Treenode *q = root;
    std::stack<Treenode *> stLft;
    std::stack<Treenode *> stRgh;
    while (p != nullptr || !stLft.empty())
    {
        if (p != nullptr)
        {
            if (q == nullptr || p->val != q->val)
            {
                return false;
            }
            stLft.push(p);
            stRgh.push(q);
            p = p->left;
            q = q->right;
        }
        else
        {
            Treenode *tmplft = stLft.top();
            stLft.pop();
            Treenode *tmpRgh = nullptr;
            if (stRgh.empty())
            {
                return false;
            }
            else
            {
                tmpRgh = stRgh.top();
                stRgh.pop();
            }
            p = tmplft->right;
            q = tmpRgh->left;
        }
    }
    return true;
}
