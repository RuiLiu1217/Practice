#include "headers.hpp"

ListNode<int>* reverseList(ListNode<int>* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode<int>* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}