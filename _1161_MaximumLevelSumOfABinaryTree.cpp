#include "headers.hpp"
#include <queue>
int LeetCode::_1161_MaximumLevelSumOfABinaryTree::maxLevelSum(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    TreeNode<int>* p = root;
    std::queue<TreeNode<int>*> Q;
    Q.push(p);
    int maxSum = INT_MIN;
    int level = 1;
    int l = 1;
    while(!Q.empty()) {
        const int N = Q.size();
        int sum = 0;
        for(int i = 0; i < N; ++i) {
            auto t = Q.front();
            Q.pop();
            sum += t->val;
            
            if(t->left) {
                Q.push(t->left);
            }
            
            if(t->right) {
                Q.push(t->right);
            }
        }
        if(sum > maxSum) {
            maxSum = sum;
            level = l;
        }
        ++l;
    }
    return level;
}