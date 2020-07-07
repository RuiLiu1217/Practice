#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0113_PathSumII::pathSum(TreeNode<int>* root, int sum) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    pathSum(root, sum, tmp, res);
    return res;
}

void LeetCode::_0113_PathSumII::pathSum(TreeNode<int>* root, int sum, std::vector<int> tmp, std::vector<std::vector<int>>& res) {
    if(root == nullptr) {
        return;            
    } else if(root->val == sum && root->left == nullptr && root->right == nullptr) {
        tmp.push_back(root->val);
        res.push_back(tmp);
        return;
    }
    tmp.push_back(root->val);
    pathSum(root->left, sum - root->val, tmp, res);
    pathSum(root->right, sum - root->val, tmp, res);
}