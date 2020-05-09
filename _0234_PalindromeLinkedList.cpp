#include "headers.hpp"

ListNode<int>* LeetCode::_0234_PalindromeLinkedList::reverse(ListNode<int>* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode<int>* nh = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return nh;
}
bool LeetCode::_0234_PalindromeLinkedList::isPalindrome(ListNode<int>* head) {
    if(!head || (!head->next)) {
        return true;
    }
    
    ListNode<int>* slow = head;
    ListNode<int>* fast = head;
    ListNode<int>* prev = nullptr;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode<int>* secondList = prev->next;
    prev->next = nullptr;
    secondList = reverse(secondList);
    while(head && secondList) {
        if(head->val != secondList->val) {
            return false;
        }
        head = head->next;
        secondList = secondList->next;            
    }
    return true;
}