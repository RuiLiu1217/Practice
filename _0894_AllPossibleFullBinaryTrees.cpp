#include "headers.hpp"
#include <numeric>
#include <algorithm>
std::vector<TreeNode<int>*> LeetCode::_0894_AllPossibleFullBinaryTrees::allPossibleFBT(int N) {
    if (!(N % 2)) {
        return std::vector<TreeNode<int>*>();
    }
    if(N == 1) {
        TreeNode<int>* p = new TreeNode<int>(0);
        return std::vector<TreeNode<int>*>({p});
    }
    std::vector<TreeNode<int>*> res;
    for(int i = 1; i < N; i += 2) {
        std::vector<TreeNode<int>*> lft = allPossibleFBT(i);
        std::vector<TreeNode<int>*> rgh = allPossibleFBT(N - i - 1);
        if(lft.empty() || rgh.empty()) {
            continue;
        }

        for(int k = 0; k < lft.size(); ++k) {
            for(int j = 0; j < rgh.size(); ++j) {
                TreeNode<int>* root = new TreeNode<int>(0);
                root->left = lft[k];
                root->right = rgh[j];
                res.push_back(root);
            }
        }
    }
    return res;
}
