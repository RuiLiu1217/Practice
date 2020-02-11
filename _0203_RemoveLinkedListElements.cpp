#include "headers.hpp"
// Tag: single linked list
ListNode<int>* LeetCode::_0203_RemoveLinkedListElements::removeElements(ListNode<int>* head, int val) {
    if(!head) {
        return nullptr;
    }
    if(head && head->next == nullptr) {
        if(head->val == val) {
            delete head;
            return nullptr;
        }
    }
    ListNode<int>* newHead = new ListNode<int>(-1);
    newHead->next = head;

    ListNode<int>* p = newHead;
    while(p->next) {
        if(p->next->val == val) {
            ListNode<int>* toRemove = p->next;
            p->next = p->next->next;
            delete toRemove;
        } else {
            p = p->next;
        }
    }
    head = newHead->next;
    return head;      
}

