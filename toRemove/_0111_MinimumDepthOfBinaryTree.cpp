#include "headers.hpp"
#include <climits>
#include <cmath>
#include <algorithm>
#include <algorithm>
#include <cmath>
#include <numeric>

int LeetCode::_0111_MinimumDepthOfBinaryTree::minDepth(TreeNode<int>* root) {
    if(!root) {
        return 0;
    } else if(!root->left) {
        return minDepth(root->right) + 1;
    } else if(!root->right) {
        return minDepth(root->left) + 1;
    } else {
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
}