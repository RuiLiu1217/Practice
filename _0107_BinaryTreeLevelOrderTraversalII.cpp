#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0107_BinaryTreeLevelOrderTraversalII::levelOrderBottom(TreeNode<int>* root) {
    std::queue<TreeNode<int> *> q;
    q.push(root);
    std::vector<std::vector<int>> res;
    while (!q.empty())
    {
        const int N = q.size();
        std::vector<int> tmp;
        for (int i = 0; i < N; ++i)
        {
            auto t = q.front();
            q.pop();
            tmp.push_back(t->val);

            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        res.push_back(tmp);
    }
    std::reverse(res.begin(), res.end());
    return res;
};