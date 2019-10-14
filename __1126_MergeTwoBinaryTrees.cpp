#include "headers.hpp"

TreeNode<int>* LintCode::_1126_MergeTwoBinaryTrees::mergeTrees(TreeNode<int> * t1, TreeNode<int> * t2) {
    if(t1 == nullptr && t2 == nullptr) {
        return nullptr;
    } else if(t1 == nullptr && t2 != nullptr) {
        return t2;
    } else if(t1 != nullptr && t2 == nullptr) {
        return t1;
    } else {
        int v = t1->val + t2->val;
        TreeNode<int>* h = new TreeNode<int>(v);
        h->left = mergeTrees(t1->left, t2->left);
        h->right = mergeTrees(t1->right, t2->right);
        return h;
    }
}