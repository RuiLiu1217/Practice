#include "headers.hpp"

TreeNode<int>* LeetCode::_1028_RecoverATreeFromPreorderTraversal::recoverFromPreorder(std::string S) {
    std::string varStr;
    int i = 0;
    int countLevel = 0;
    std::stack<std::pair<TreeNode<int>*, int>> st;
    while(i < S.size()) {
        if(S[i] == '-') {
            if(varStr.size() > 0) {
                int v = std::stoi(varStr);
                TreeNode<int>* t = new TreeNode<int>(v);
                while(!st.empty() && st.top().second >= countLevel) {
                    st.pop();
                }
                if(!st.empty()) {
                    TreeNode<int>* top = st.top().first;
                    if(top->left == nullptr) {
                        top->left = t;
                    } else if(top->right == nullptr) {
                        top->right = t;
                    }
                }
                st.push(std::make_pair(t, countLevel));
                varStr = "";
                countLevel = 1;
            } else {
                ++countLevel;
            }
        } else {
            varStr += S[i];
        }
        ++i;
    }
    if(varStr.size() > 0) {
        int v = std::stoi(varStr);
        TreeNode<int>* t = new TreeNode<int>(v);
        while(!st.empty() && st.top().second >= countLevel) {
            st.pop();
        }
        if(!st.empty()) {
            TreeNode<int>* top = st.top().first;
            if(top->left == nullptr) {
                top->left = t;
            } else if(top->right == nullptr) {
                top->right = t;
            }
        }                    
        st.push(std::make_pair(t, countLevel));
        varStr = "";
        countLevel = 1;
    }

    TreeNode<int>* p = nullptr;
    while(!st.empty()) {
        p = st.top().first;
        st.pop();
    }
    return p;
}