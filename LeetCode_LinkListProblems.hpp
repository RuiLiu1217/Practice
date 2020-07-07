#ifndef LEETCODE_LINKLISTPROBLEMS_HPP
#define LEETCODE_LINKLISTPROBLEMS_HPP
#include <vector>
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


/* 
Tag: single link list
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: Given n will always be valid.
Follow up: Could you do this in one pass?
*/
class _0019_RemoveNthNodeFromEndToList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};



/*
Tag: single link list, recursive
Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.
Example:
Input:  1->2->4, 
        1->3->4
Output: 1->1->2->3->4->4
*/
class _0021_MergeTwoSortedLists {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

/*
Google

Tag: single link list
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
class _0023_MergeKeSortedLists {
private:
    ListNode* p;
    ListNode* fh;
public:
    ListNode* mergeKLists(std::vector<ListNode*> &lists);
    bool finishSorting(std::vector<bool> notChoose);
};



/*
Tag: single link list, recursive
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
class _0024_SwapNodesInPairs {
public:
    ListNode *swapPairs(ListNode *head);
};



/*
Tag: single link list, recursive
Given a linked list, reverse the nodes of a linked list k at a time and return 
its modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should 
remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
class _0025_ReverseNodeInKGroup {
public:
    ListNode* reverseGroup(ListNode* head, int k);
};


} // end namespace LC

#endif