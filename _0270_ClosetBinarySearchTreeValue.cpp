#include "headers.hpp"

// Facebook

int LeetCode::_0270_ClosetBinarySearchTreeValue::closestValue(TreeNode<int>* root, double target) {
    int closet = root->val;
    while(root) {
        if(std::abs(closet - target) >= std::abs(root->val - target)) {
            closet = root->val;
        }
        root = target < root->val ? root->left : root->right;
    }
    return closet;
}
