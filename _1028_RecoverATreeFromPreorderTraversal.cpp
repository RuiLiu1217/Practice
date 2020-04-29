#include "headers.hpp"

TreeNode<int>* LeetCode::_1028_RecoverATreeFromPreorderTraversal::recoverFromPreorder(std::string S) {
    S += '-';
    std::stack<std::pair<TreeNode<int>*, int>> st;
    int dashNum = 0;
    std::string num;
    for(char s : S) {
        if(s == '-') {
            if(!num.empty()) {
                TreeNode<int>* node = new TreeNode<int>(std::stoi(num));
                num.clear();

                if(st.empty()) {
                    st.push({node, dashNum});
                } else {
                    while(!st.empty() && st.top().second >= dashNum) {
                        st.pop();
                    }

                    TreeNode<int>* parent = st.top().first;
                    if(parent->left == nullptr) {
                        parent->left = node;
                    } else if(parent->right == nullptr) {
                        parent->right = node;
                    }
                    st.push({node, dashNum});
                }
                dashNum = 1;
            } else {
                ++dashNum;
            }
        } else {
            num += s;
        }
    }
}