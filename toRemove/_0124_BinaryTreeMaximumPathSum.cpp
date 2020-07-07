#include "headers.hpp"

// Facebook

// 这道题的解法还是很巧妙的，
// 设计一个helper 函数，这个函数以 树的某个节点为参数，它返回以这个节点为一侧端点的最长路径。也就是选左边子树还是选右边子树.
// 然后在这个函数里面夹带一个全局变量，这个全局变量才是要求解的结果
int LeetCode::_0124_BinaryTreeMaximumPathSum::helper(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    int left = std::max(helper(root->left), 0);
    int right = std::max(helper(root->right), 0);
    res = std::max(res, left + right + root->val);
    return std::max(left, right) + root->val;
}
int LeetCode::_0124_BinaryTreeMaximumPathSum::maxPathSum(TreeNode<int>* root) {
    res = INT_MIN;
    helper(root);
    return res;
}