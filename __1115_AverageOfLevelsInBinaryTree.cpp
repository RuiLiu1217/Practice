#include "headers.hpp"

std::vector<double> LintCode::_1115_AverageOfLevelsInBinaryTree::averageOfLevels(TreeNode<int>* root) {
    TreeNode<int>* h = root;
    std::queue<TreeNode<int>*> q;
    if(!h) {
        return std::vector<double>();
    }
    q.push(h);
    double sum = 0;
    std::vector<double> res;
    while(!q.empty()) {
        const int N = q.size();
        double sum = 0;
        for(int i = 0; i < N; ++i) {
            auto tp = q.front();
            q.pop();
            sum += tp->val;
            if(tp->left) {
                q.push(tp->left);
            }
            if(tp->right) {
                q.push(tp->right);
            }
        }
        res.push_back(static_cast<double>(sum) / static_cast<double>(N));
    }
    return res;
}