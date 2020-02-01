#include "headers.hpp"
#include <queue>
#include <stack>

int LeetCode::_1302_DeepestLeavesSum::deepestLeavesSum(TreeNode<int>* root) {
    std::queue<std::pair<TreeNode<int>*, int>> q;
    q.push(std::make_pair(root, 0));
    std::stack<std::pair<TreeNode<int>*, int>> res;
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto t = q.front();
            q.pop();
            TreeNode<int>* p = t.first;
            int l = t.second;
            bool leaf = (p->left == nullptr) && (p->right == nullptr);
            if(leaf) {
                while(!res.empty() && res.top().second < l) {
                    res.pop();
                }
                res.push(std::make_pair(p, l));
            }
            
            if(p->left) {
                q.push(std::make_pair(p->left, l + 1));
            }
            if(p->right) {
                q.push(std::make_pair(p->right, l + 1));
            }
        }
    }
    int sum = 0;
    while(!res.empty()) {
        sum += res.top().first->val;
        res.pop();
    }
    return sum;
}