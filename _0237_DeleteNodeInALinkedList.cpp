#include "headers.hpp"

void LeetCode::_0237_DeleteNodeInALinkedList::deleteNode(ListNode<int>* node) {
    if(!node->next) {
        return;        
    } else {
        std::swap(node->val, node->next->val);
        ListNode<int>* p = node->next;
        node->next = node->next->next;
        delete p;
    }
}