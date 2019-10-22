#include "headers.hpp"

TreeNode<int>* LeetCode::_0109_ConvertSortedListToBinarySearchTree::sortedListToBST(ListNode<int>* head) {
    if(!head) {
        return nullptr;
    }
    ListNode<int>* lRoot = nullptr;
    ListNode<int>* lleft = nullptr;
    ListNode<int>* lright= nullptr;
    split(head, lRoot, lleft, lright);
    
    TreeNode<int>* root = new TreeNode<int>(lRoot->val);
    root->left = sortedListToBST(lleft);
    root->right = sortedListToBST(lright);
    return root;
}
    
void LeetCode::_0109_ConvertSortedListToBinarySearchTree::split(ListNode<int>* head, ListNode<int>*& root, ListNode<int>*& left, ListNode<int>*& right) {
    if(!head) {
        root = nullptr;
        left = nullptr;
        right = nullptr;
        return;
    }
    
    if(!head->next) {
        root = head;
        left = nullptr;
        right = nullptr;
        return;
    }
    
    ListNode<int>* nh = new ListNode<int>(INT_MAX);
    nh->next = head;
    
    ListNode<int>* slow = nh;
    ListNode<int>* fast = nh;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    root = slow->next;
    slow->next = nullptr;
    right = root->next;
    root->next = nullptr;
    left = nh->next;
    nh->next = nullptr;
    delete nh;
    return;
    
}