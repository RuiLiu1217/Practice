#include "headers.hpp"

LeetCode::_1261_FindElementsInAContaminatedBinaryTree::_1261_FindElementsInAContaminatedBinaryTree(TreeNode<int>* root) {
    res.insert(0);
    root->val = 0;
    recover(root);
    this->rot = root;
}

bool LeetCode::_1261_FindElementsInAContaminatedBinaryTree::find(int target) {
    return res.find(target) != res.end();
}

void LeetCode::_1261_FindElementsInAContaminatedBinaryTree::recover(TreeNode<int>* root) {
    if(!root) {
        return;
    }

    int v = root->val;
    if(root->left) {
        root->left->val = v * 2 + 1;
        res.insert(v * 2 + 1);
        recover(root->left);
    } 
    if(root->right) {
        root->right->val = v * 2 + 2;
        res.insert(v * 2 + 2);
        recover(root->right);
    }
}