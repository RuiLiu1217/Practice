#include "headers.hpp"

ListNode<int>* LeetCode::_876_MiddleOfTheLinkedList::middleNode(ListNode<int>* head) {
    ListNode<int>* slow = head;
    ListNode<int>* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}