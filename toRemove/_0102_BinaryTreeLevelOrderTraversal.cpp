#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0102_BinaryTreeLevelOrderTraversal::levelOrder(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::queue<TreeNode<int>*> q;
    q.push(p);
    if(!root) {
        return {};
    }

    std::vector<std::vector<int>> res;
    while(!q.empty()) {
        const int N = q.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            TreeNode<int>* t = q.front();
            q.pop();
            tmp.push_back(t->val);

            if(t->left) {
                q.push(t->left);
            }
            if(t->right) {
                q.push(t->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}
