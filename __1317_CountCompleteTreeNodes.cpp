#include "headers.hpp"

int LintCode::_1317_CountCompleteTreeNodes::countNodes(TreeNode<int>* root) {
    if(!root) {
        return 0;
    } else if(root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
