#include "headers.hpp"
#include <stack>
#include <algorithm>
std::vector<int> LeetCode::_0145_BinaryTreePostorderTraversal::postorderTraversal(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::stack<std::pair<TreeNode<int>*, int>> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        while(p != nullptr) {
            st.push(std::make_pair(p, 0));
            p = p->left;
        }
        if(!st.empty()) {
            auto temp = st.top();
            st.pop();
            if(temp.second == 0) {
                temp.second = 1;
                st.push(temp);
                p = temp.first->right;
            } else {
                res.emplace_back(temp.first->val);
                p = nullptr; // need to set it as null, otherwise, there will be an error.
            }
        }
        return res;
    }
}