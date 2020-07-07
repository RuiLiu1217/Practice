#include "headers.hpp"

// 快慢指针追逐
bool LeetCode::_0141_LinkedListCycle::hasCycle(ListNode<int>* head) {
    ListNode<int>* fastPtr = head;
    ListNode<int>* slowPtr = head;
    if(head == nullptr) {
        return false;
    }
    if(head->next == nullptr) {
        return false;
    }
    while(fastPtr) {
        fastPtr = fastPtr->next;
        if(fastPtr) {
            fastPtr = fastPtr->next;
        } else {
            return false;
        }

        slowPtr = slowPtr->next;

        if(fastPtr == slowPtr) {
            return true;
        }
    }
    return false;    
}