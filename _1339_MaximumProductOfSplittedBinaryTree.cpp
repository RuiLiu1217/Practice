#include "headers.hpp"

int LeetCode::_1339_MaximumProductOfSplittedBinaryTree::maxProduct(TreeNode<int>* root) {
    int totVal = subSum(root);
    std::vector<std::pair<TreeNode<int>*, int>> serial;
    for(auto& m : map) {
        serial.push_back(m);
    }
    std::sort(begin(serial), end(serial), [&](auto& a, auto& b){
        return static_cast<long long>(totVal - a.second) * a.second > static_cast<long long>(totVal - b.second) * b.second;
    });
    int v = serial.front().second;
    return static_cast<long long>(totVal - v) * v % (1000000000 + 7);
}

int LeetCode::_1339_MaximumProductOfSplittedBinaryTree::subSum(TreeNode<int>* root) {
    if(!root) {
        return map[nullptr] = 0;
    }
    return map[root] = root->val + subSum(root->left) + subSum(root->right);
}