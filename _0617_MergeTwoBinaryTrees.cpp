#include "headers.hpp"

TreeNode<int>* mergeTrees(TreeNode<int>* t1, TreeNode<int>* t2) {
    if(t1 == nullptr && t2 == nullptr)
        return nullptr;
    else if(t1 == nullptr && t2 != nullptr) {
        return t2;
    }
    else if(t1 != nullptr && t2 == nullptr) {
        return t1;
    }
    else {
        TreeNode<int>* root = new TreeNode<int>(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
}