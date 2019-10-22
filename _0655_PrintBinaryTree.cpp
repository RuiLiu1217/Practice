#include "headers.hpp"

std::vector<std::vector<std::string>> LeetCode::_0655_PrintBinaryTree::printTree(TreeNode<int>* root) {
    int h = getHeight(root);
    int w = (1<<h) - 1; // 2^h - 1
    std::vector<std::vector<std::string>> res(h, std::vector<std::string>(w, ""));
    fill(root,res, 0, 0, w - 1);
    return res;
}

int LeetCode::_0655_PrintBinaryTree::getHeight(TreenNode<int>* root) {
    if(!root) {
        return 0;
    }
    return std::max(getHeight(root->left),getHeight(root->right)) + 1;
}
void LeetCode::_0655_PrintBinaryTree::fill(TreeNode<int>* root, std::vector<std::vector<std::string>>& res, int h, int l, int r) {
    if(!root) {
        return;
    }
    int mid = l + (r - l) / 2;
    res[h][mid] = std::to_string(root->val);
    fill(root->left, res, h + 1, l, mid - 1);
    fill(root->right, res, h + 1, mid + 1, r);
}
