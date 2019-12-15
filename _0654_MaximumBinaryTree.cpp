#include "headers.hpp"
#include <numeric>
#include <algorithm>

TreeNode<int>* LeetCode::_0654_MaximumBinaryTree::constructMaximumBinaryTree(std::vector<int>& nums) {
    return constructMaximumBinaryTree_impl(nums, 0, nums.size());
}

TreeNode<int>* LeetCode::_0654_MaximumBinaryTree::constructMaximumBinaryTree_impl(std::vector<int>& nums, int l, int r) {
    if(l == r) {
        return nullptr;
    } 
    auto it = std::max_element(nums.begin() + l, nums.begin() + r);
    int idx = it - nums.begin();
    TreeNode<int>* root = new TreeNode<int>(*it);
    root->left = constructMaximumBinaryTree_impl(nums, l, idx);
    root->right= constructMaximumBinaryTree_impl(nums,idx+1, r);
    return root;
}