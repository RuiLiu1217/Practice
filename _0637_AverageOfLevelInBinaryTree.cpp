#include "headers.hpp"
#include <queue>

std::vector<double> LeetCode::_0637_AverageOfLevelsInBinaryTree::averageOfLevels(TreeNode<int>* root) {
    if(!root) {
        return {};
    }
    std::queue<std::pair<TreeNode<int>*, int>> nodeQueue;
    nodeQueue.push(std::make_pair(root, 0));
    std::vector<double> res;
    while(!nodeQueue.empty()) {
        int lvl = nodeQueue.front().second;
        double Sum = 0;
        double Count = 0;
        while(!nodeQueue.empty() && nodeQueue.front().second == lvl) {
            std::pair<TreeNode<int>*, int> p = nodeQueue.front();    
            Sum += p.first->val;
            Count += 1;
            if(p.first->left) {
                nodeQueue.push(std::make_pair(p.first->left, lvl+1));
            }
            if(p.first->right) {
                nodeQueue.push(std::make_pair(p.first->right, lvl+1));
            }
            nodeQueue.pop();
        }
        res.push_back(Sum / Count);
    }
    return res;
}
