#include "headers.hpp"

int LeetCode::_1290_ConvertBinaryNumberInALinkedListToInteger::getDecimalValue(ListNode<int>* head) {
    int sum = 0;
    while(head) {
        sum <<= 1;
        sum += head->val;
        head = head->next;
    }
    return sum;
}