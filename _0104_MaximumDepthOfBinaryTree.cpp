#include "headers.hpp"
#include <numeric>
#include <cmath>
#include <algorithm>
int LeetCode::_0104_MaximumDepthOfBinaryTree::maxDepth(TreeNode<int>* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}