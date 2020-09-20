#include "headers.hpp"


TreeNode<int>* balanceBST(TreeNode<int>* root) {
    const auto arr = inOrderTraverse(root);
    return createBST(arr, 0, arr.size());
}
TreeNode<int>* createBST(const std::vector<int>& arr, int start, int end) {
    if(start >= end) {
        return nullptr;
    }
    if(start + 1 == end) {
        return new TreeNode<int>(arr[start]);
    } else {
        int mid = start + (end - start) / 2;
        TreeNode<int>* root = new TreeNode<int>(arr[mid]);
        root->left = createBST(arr, start, mid);
        root->right = createBST(arr, mid+1, end);
        return root;
    }
}
std::vector<int> inOrderTraverse(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::vector<int> res;
    std::stack<TreeNode<int>*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            res.push_back(q->val);
            p = q->right;
        }
    }
    return res;
}