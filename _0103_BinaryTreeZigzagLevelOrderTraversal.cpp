#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_0103_BinaryTreeZigzagLevelOrderTraversal::zigzagLevelOrder(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    if(!p) {
        return {};
    }
    
    std::queue<TreeNode<int>*> qu;
    qu.push(p);
    int l = 1;

    std::vector<std::vector<int>> res;
    while(!qu.empty()) {
        const int N = qu.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            TreeNode<int>* t = qu.front();
            qu.pop();

            tmp.push_back(t->val);

            if(t->left) {
                qu.push(t->left);
            }
            if(t->right) {
                qu.push(t->right);
            }
        }
        if(l%2==0) {
            std::reverse(tmp.begin(), tmp.end());
        }
        res.push_back(tmp);
        ++l;
    }
    return res;
}