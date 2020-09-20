#include "headers.hpp"

bool LeetCode::_1145_BinaryTreeColoringGame::btreeGameWinningMove(
    TreeNode<int>* root, int n, int x) {
    nodes(root, x);
    int p = n - (l_ + r_ + 1);
    return std::max(p, std::max(l_, r_)) > n / 2;
}

int LeetCode::_1145_BinaryTreeColoringGame::nodes(TreeNode<int>* root, int x) {
    if(!root) {
        return 0;
    }
    int l = nodes(root->left, x);
    int r = nodes(root->right, x);

    if(root->val == x) {
        l_ = l;
        r_ = r;
    }
    return 1 + l + r;
}

