#include "headers.hpp"
#include <cmath>
#include <numeric>
#include <algorithm>

// 仔细看看解题到底什么意思
// 最好把他的算法显示地画一下。
static void pathInZigzagTreeHelper(std::vector<int>& res, int label) {
    if(label == 1) {
        res.push_back(1);
        return;
    } else {
        res.push_back(label);
        int level = std::log2(label);
        int preLabel = 0;
        if(level % 2) {
            preLabel = (std::pow(2, level) + std::pow(2, level + 1) - label - 1) / 2;
        } else {
            preLabel = std::pow(2, level) + std::pow(2, level - 1) - (label / 2);
        }
        pathInZigzagTreeHelper(res, preLabel);
    }
}

std::vector<int> LeetCode::_1104_PathInZigzagLabelledBinaryTree::pathInZigZagTree(int label) {
    std::vector<int> res;
    pathInZigzagTreeHelper(res, label);
    std::reverse(res.begin(), res.end());
    return res;
}