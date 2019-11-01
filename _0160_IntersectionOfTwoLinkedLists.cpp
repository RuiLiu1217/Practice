#include "headers.hpp"

ListNode<int>* LeetCode::_0160_IntersectionOfTwoLinkedLists::getIntersectionNode(ListNode<int>* headA, ListNode<int>* headB) {
    int lengthOfA = length(headA);
    int lengthOfB = length(headB);
    int moveCount = std::abs(lengthOfA - lengthOfB);
    if(lengthOfA > lengthOfB) {
        while(moveCount) {
            headA = headA->next;
            moveCount--;
        }
    } else if(lengthOfA < lengthOfB) {
        while(moveCount) {
            headB = headB->next;
            moveCount--;
        }
    }
    while(headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int LeetCode::_0160_IntersectionOfTwoLinkedLists::length(ListNode<int>* root) {
    if(!root) {
        return 0;
    } else {
        return 1 + length(root->next);
    }
}