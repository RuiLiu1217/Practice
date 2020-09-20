#include "headers.hpp"

// 这道题完全蒙住了
// https://www.youtube.com/watch?v=yX1hVhcHcH8
int LeetCode::_0687_LongestUnivaluePath::longestUnivaluePath(TreeNode<int>* root) {
    if(root == nullptr) {
        return 0;
    }
    int ans = 0;
    univaluePath(root, &ans);
    return ans;
}

// 表示用到 root 的最长路径是多长。
int LeetCode::_0687_LongestUnivaluePath::univaluePath(TreeNode<int>* root, int* ans) {
    if(root == nullptr) {
        return 0;
    }
    
    int l = univaluePath(root->left, ans);
    int r = univaluePath(root->right, ans);
    
    int pl = 0;
    int pr = 0;
    
    if(root->left && root->val == root->left->val) {
        pl = l + 1;
    }
    if(root->right && root->val == root->right->val) {
        pr = r + 1;
    }
    *ans = std::max(*ans, pl + pr);
    
    // 一定经过root的最长路径，如果两个孩子都和root上的value不一样，就返回0.
    return std::max(pl, pr); 
}
