#ifndef LEETCODE_LINKLISTPROBLEMS_HPP
#define LEETCODE_LINKLISTPROBLEMS_HPP
#include <vector>
#include <map>
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



/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
class _0061_RotateList {
public:
    ListNode* rotateRight(ListNode* head, int k);
};


/*
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Input: 1->1->1->2->3
Output: 2->3
*/
class _0082_RemoveDuplicatesFromSortedListII {
public:
    ListNode* deleteDuplicates(ListNode* head);
};



/*
Given a sorted linked list, delete all duplicates such that each element 
appear only once.

Input: 1->1->2
Output: 1->2

Input: 1->1->2->3->3
Output: 1->2->3
*/
class _0083_RemoveDuplicatesFromSortedList {
public:
    ListNode* deleteDuplicates(ListNode* head);
};


/*
Given a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of 
the two partitions.

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
class _0086_PartitionList {
    public:
        ListNode* partition(ListNode* head, int x);
};


/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
class _0092_ReverseLinkedListII {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n);
};


/*
TODO:
A linked list is given such that each node contains an additional random pointer which could point to 
any node in the list or null. Return a deep copy of the list.

Example 1:
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 

Note:

You must return the copy of the given head as a reference to the cloned list.
*/
class _0138_CopyListWithRandomPointer {
public:
    struct Node {
        public:
            int val;
            Node* next;
            Node* random;
            Node() {}
            Node(int _val, Node* _next, Node* _random) : val(_val), next(_next), random(_random) {}
    };

    Node* copyRandomList(Node* head);
    std::map<Node*, Node*> visit;
};

/*
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?
*/
class _0141_LinkedListCycle {
public:
    bool hasCycle(ListNode* head);
};

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position 
(0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in 
the linked list.

Note: Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
*/
class _0142_LinkedListCycleII {
public:
    ListNode* detectCycle(ListNode* head);
};


/*
Sort a linked list using insertion sort.
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
class _0147_InsertionSortList {
public:
    ListNode* insertionSortList(ListNode* head);
};


// Sort a linked list in O(NlogN) time using constant space complexity.
class _0148_SortList {
public:
    ListNode *sortList(ListNode *head);
private:
    ListNode *merge(ListNode *head1, ListNode *head2);
    void splitList(ListNode* &head, ListNode* &left, ListNode* &right);
};


/*
Tag: single linked list

Write a program to find the node at which the intersection of two singly linked lists begins.

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two 
lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as 
[5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the
intersected node in B.
 

Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two 
lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as 
[3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the 
intersected node in B.


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5].
Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be 
arbitrary values. Explanation: The two lists do not intersect, so return null.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
class _0160_IntersectionOfTwoLinkedLists {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
private:
    int length(ListNode* root);
};

/*
Remove all elements from a linked list of integers that have value val.
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
class _0203_RemoveLinkedListElements {
public:
    ListNode* removeElements(ListNode* head, int val);
};



/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
class _0206_ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head);
};


/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
class _0234_PalindromeLinkedList {
public:
    bool isPalindrome(ListNode* head);
private:
    ListNode* reverse(ListNode* head);
};


/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.
Given linked list -- head = [4,5,1,9], which looks like following:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/
class _0237_DeleteNodeInALinkedList {
public:
    void deleteNode(ListNode* node);
};



/* Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by 
the even nodes. Please note here we are talking about the node number 
and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space 
complexity and O(nodes) time complexity.

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
class _0328_OddEvenLinkedList {
public:
    ListNode* oddEvenList(ListNode* head);
};


/*
Given a (singly) linked list with head node root, write a 
function to split the linked list into k consecutive linked 
list "parts".
The length of each part should be as equal as possible: no 
two parts should have a size differing by more than 1. This 
may lead to some parts being null.
The parts should be in order of occurrence in the input list, 
and parts occurring earlier should always have a size greater 
than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts 
that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, 
root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation
 as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference
 at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/
class _0725_SplitLinkedListInParts {
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k);
private:
    std::pair<ListNode*, ListNode*> getFirstNNodes(ListNode* root, int n) {
        ListNode* h = root;
        ListNode* p = h;
        while(n > 1 && p) {
            p = p->next;
            --n;
        }
        ListNode* nh = p ? p->next : nullptr;
        if(p) {
            p->next = nullptr;
        }
        return {h, nh};
    }
    int getListLength(ListNode* root) {
        if(!root) {
            return 0;
        }
        int c = 0;
        while(root) {
            ++c;
            root = root->next;
        }
        return c;
    }
};


/*
Given a non-empty, singly linked list with head node head, return a middle node of 
linked list. If there are two middle nodes, return the second middle node.

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
*/
class _0876_MiddleOfTheLinkedList {
public:
    ListNode* middleNode(ListNode* head);
};

} // end namespace LC

#endif