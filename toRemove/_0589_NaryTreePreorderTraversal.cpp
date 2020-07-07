#include "headers.hpp"
#include <stack>
std::vector<int> LeetCode::_0589_NaryTreePreorderTraversal::preorder(NaryTreeNode<int>* root) {
    std::stack<NaryTreeNode<int>*> st;
    if(!root) {
        return std::vector<int>();
    } else {
        NaryTreeNode<int>* p = root;
        st.push(p);
        std::vector<int> res;
        while(!st.empty()) {
            NaryTreeNode<int>* tp = st.top();
            res.push_back(tp->data);
            st.pop();
            for(int i = tp->children.size()-1; i >= 0; --i) {
                st.push(tp->children[i]);
            }
        }
        return res;
    }
}