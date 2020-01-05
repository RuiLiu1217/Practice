#include "headers.hpp"

TreeNode<int>* LeetCode::_0865_SmallestSubtreeWithAllTheDeepestNodes::subtreeWithAllDeepest(TreeNode<int>* root) {
    auto res = depth(root);
    return res.second;
}

std::pair<int, TreeNode<int>*> LeetCode::_0865_SmallestSubtreeWithAllTheDeepestNodes::depth(TreeNode<int>* root) {
    if(!root) {
        return {0, nullptr};
    }
    auto l = depth(root->left);
    auto r = depth(root->right);
    int d1 = l.first;
    int d2 = r.first;
    return {std::max(d1, d2) + 1, d1 == d2 ? root : (d1 > d2) ? l.second : r.second};
}