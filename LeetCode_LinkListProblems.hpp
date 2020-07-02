#ifndef LEETCODE_LINKLISTPROBLEMS_HPP
#define LEETCODE_LINKLISTPROBLEMS_HPP
namespace LC {

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};


/* Tag: single link list
    You are given two non-empty linked lists representing 
    two non-negative integers. The digits are stored in 
    reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.
    
    Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/
class _0002_AddTwoNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
private:
    ListNode *addImpl(ListNode *l1, ListNode *l2, int carry);
};


}

#endif