#include "headers.hpp"

int LeetCode::_0543_DiameterofBinaryTree::diameterOfBinaryTree(TreeNode<int>* root) {
    res = 1;
    depth(root);
    return res - 1;
}
int LeetCode::_0543_DiameterofBinaryTree::depth(TreeNode<int>* root) {
    if(root == nullptr) {
        return 0;
    }
    int L = depth(root->left);
    int R = depth(root->right);
    res = std::max(res, L + R + 1);
    return std::max(L, R) + 1;
}