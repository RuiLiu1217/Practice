#include "headers.hpp"

int LeetCode::_0222_CountCompleteTreeNodes::countNodes(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}