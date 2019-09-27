#include "headers.hpp"

TreeNode<int>* LeetCode::_0108_ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(std::vector<int>& nums) {
    return bst(nums, 0, nums.size() - 1);
}

TreeNode<int>* LeetCode::_0108_ConvertSortedArrayToBinarySearchTree::bst(std::vector<int>& nums, int start, int end) {
    if(start > end || end < 0) { // end < 0 is a edge conditional case
        return nullptr;
    }
    if(start == end) {
        TreeNode<int>*p = new TreeNode<int>(nums[start]);
    } else {
        int mid = start + (end - start) / 2;
        TreeNode<int>* root = new TreeNode<int>(nums[mid]);
        root->left = bst(nums, start, mid - 1);
        root->right = bst(nums, mid + 1, end);
        return root;
    }
}