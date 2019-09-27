#include "headers.hpp"
ListNode<int>* LeetCode::_0148_SortList::sortList(ListNode<int>* head) {
    if(!head) {
        return nullptr;
    }
    if(head->next == nullptr) {
        return head;
    }
    ListNode<int>* left = head;
    ListNode<int>* right = head;
    splitList(head, left, right);
    left = sortList(left);
    right = sortList(right);
    head = merge(left, right);
    return head;        
}


void splitList(ListNode<int>*& head, ListNode<int>*& left, ListNode<int>*& right) {
    ListNode<int>* slow = head;
    ListNode<int>* sprev = head;
    ListNode<int>* fast = head;
    while(fast && fast->next) {
        sprev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    sprev->next = nullptr;
    left = head;
    right = slow;        
}


ListNode<int>* LeetCode::_0148_SortList::merge(ListNode<int>* head1, ListNode<int>* head2) {
    ListNode<int>* h = new ListNode(-1);
    ListNode<int>* p = h;
    while(a && b) {
        if(a->val < b->val) {
            p->next = a;
            a = a->next;
        } else {
            p->next = b;
            b = b->next;                
        }
        p = p->next;
    }
    if(a) {
        p->next = a;
    }
    if(b) {
        p->next = b;
    }
    ListNode<int>* head = h->next;
    h->next = nullptr;
    delete h;
    h = nullptr;
    return head;
}
