#ifndef PROBLEM_SET1_HPP
#define PROBLEM_SET1_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {



/*
Tag: Array, Special Topic. I totally have no idea about it. If possible, just remember it.
TODO : Remember

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell 
one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
Input: [7,1,5,3,6,4]                   :                   Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Input: [7,6,4,3,1]                     :                   Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class _0121_BestTimeToBuyAndSellStock {
public:
// Solution : 
// The points of interest are the peaks and valleys in the given graph. We need to find 
// the largest peak following the smallest valley. We can maintain two variables - minprice 
// and maxprofit corresponding to the smallest valley and maximum profit (maximum 
// difference between selling price and minprice) obtained so far respectively.
    int maxProfit(std::vector<int>& prices);
};

/*
Tag: greedy, array, special topic
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as 
you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell 
the stock before you buy again).

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
    engaging multiple transactions at the same time. You must sell before buying again.

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class _0122_BestTimeToBuyAndSellStockII {
public:
    int maxProfit(std::vector<int> prices);
};



/*
Tag: palindrome, string, Dynamic programming, DFS
TODO:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
class _0131_PalindromePartitioning {
public:
    std::vector<std::vector<std::string>> partition(std::string s);
private:
    void partition(std::string& s, int start, int end,std::vector<std::string>& tmp, std::vector<std::vector<std::string>>& res);
    bool isPalindrome(std::string& s, int start, int end); 
};

/*
Tag: string, palindrome, dynamic programming
TODO:

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class _0132_PalindromePartitioningII {
public:
    std::vector<std::vector<std::string>> partition(std::string s);
};



/*
Tag: array, 
TODO: Hard to think of

There are N gas stations along a circular route, 
where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs 
cost[i] of gas to travel from station i to its next station 
(i+1). You begin the journey with an empty tank at one of 
the gas stations.
Return the starting gas station's index if you can travel 
around the circuit once in the clockwise direction, otherwise 
return -1.

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/
class _0134_GasStation {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);
};


/*
Tag: array, left-right two times traversal
TODO: Hard to think of
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it satisfies the above two conditions.
*/

class _0135_Candy {
public:
    int candy(std::vector<int>& ratings);
};


/*
Tag: Dynamic Programming, backtracking (TLE)

Facebook

Given a non-empty string s and a dictionary wordDict containing a list of non-empty 
words, determine if s can be segmented into a space-separated sequence of one or 
more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
class _0139_WordBreak {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict);
private:
    bool wordBreak(std::string s, std::unordered_set<std::string>& wd);
    bool wordBreak(std::string& s, const std::unordered_set<std::string>& wordDict);
private:
    std::unordered_map<std::string, bool> hasSolution;
};





/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Given 1->2->3->4, reorder it to 1->4->2->3.
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
class _0143_ReorderList {
public:
    void reorderList(ListNode<int>* head);
};




/*
Tag: Special topic
TODO:

Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key 
exists in the cache, otherwise return -1. 
put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
class _0146_LRUCache {
private:
    int mCapacity;
    std::list<std::pair<int, int>> mCache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mMap;
public:
    _0146_LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};


/*
Tag: Geometry
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
class _0149_MaxPointsOnALine {
public:
    int maxPoints(std::vector<std::vector<int>>& points);
};


/*
TAG: string, stringstream
TODO: Operation on stirng is very tricky and important
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
class _0151_ReverseWordsInAString {
public:
    std::string reverseWords(std::string s);
};


/*
Tag: array, dynamic programming
Todo: I have no idea how it is solved. and why the solution is in that way
Given an integer array nums, find the contiguous subarray within an array (containing 
at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

抄答案的
*/
class _0152_MaximumProductSubarray {
public:
    int maxProduct(std::vector<int>& nums);
};


/*
Tag: binary search
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element. You may assume no duplicate exists in the array.

Input: [3,4,5,1,2] 
Output: 1

Input: [4,5,6,7,0,1,2]
Output: 0
*/
class _0153_FindMinimumInRotatedSortedArray {
public:
    int findMin(std::vector<int>& nums);
};

/*
Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.

Input: [1,3,5]
Output: 1

Input: [2,2,2,0,1]
Output: 0
Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
class _0154_FindMinimumInRotatedSortedArrayII {
public:
    int findMin(std::vector<int>& nums);
private:
    int findMin(std::vector<int>& nums, int start, int end);
};

/*
Tag: Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
Example:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   --> Returns -3.
    minStack.pop();
    minStack.top();      --> Returns 0.
    minStack.getMin();   --> Returns -2.
*/
class _0155_MinStack
{
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    /** initialize your data structure here. */
    _0155_MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

/*
Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

Method read4:

The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.
The return value is the number of actual characters read.
Note that read4() has its own file pointer, much like FILE *fp in C.
Definition of read4:

    Parameter:  char[] buf
    Returns:    int

Note: buf[] is destination not source, the results from read4 will be copied to buf[]
Below is a high level example of how read4 works:

File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
 

Method read:
By using the read4 method, implement the method read that reads n characters from the file and store it in the buffer array buf. Consider that you cannot manipulate the file directly.
The return value is the number of actual characters read.

Definition of read:

    Parameters:	char[] buf, int n
    Returns:	int

Note: buf[] is destination not source, you will need to write the results to buf[]
 

Example 1:

Input: file = "abc", n = 4
Output: 3
Explanation: After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3. Note that "abc" is the file's content, not buf. buf is the destination buffer that you will have to write the results to.
Example 2:

Input: file = "abcde", n = 5
Output: 5
Explanation: After calling your read method, buf should contain "abcde". We read a total of 5 characters from the file, so return 5.
Example 3:

Input: file = "abcdABCD1234", n = 12
Output: 12
Explanation: After calling your read method, buf should contain "abcdABCD1234". We read a total of 12 characters from the file, so return 12.
Example 4:

Input: file = "leetcode", n = 5
Output: 5
Explanation: After calling your read method, buf should contain "leetc". We read a total of 5 characters from the file, so return 5.
 

Note:

Consider that you cannot manipulate the file directly, the file is only accesible for read4 but not for read.
The read function will only be called once for each test case.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
*/
class _0157_ReadNCharactersGivenRead4 {
public:
    int read(char* buf, int n);
private:
    int read4(char*); // Provided function
};


/*
Given a file and assume that you can only read the file using a given method read4, implement a method read to read n characters. Your method read may be called multiple times.

Method read4:

The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.
The return value is the number of actual characters read.
Note that read4() has its own file pointer, much like FILE *fp in C.
Definition of read4:

    Parameter:  char[] buf
    Returns:    int

Note: buf[] is destination not source, the results from read4 will be copied to buf[]
Below is a high level example of how read4 works:

File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
 

Method read:
By using the read4 method, implement the method read that reads n characters from the file and store it in the buffer array buf. Consider that you cannot manipulate the file directly.
The return value is the number of actual characters read.
Definition of read:

    Parameters:	char[] buf, int n
    Returns:	int

Note: buf[] is destination not source, you will need to write the results to buf[]

File file("abc");
Solution sol;
Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
Example 2:

File file("abc");
Solution sol;
sol.read(buf, 4); // After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.

Note:

Consider that you cannot manipulate the file directly, the file is only accesible for read4 but not for read.
The read function may be called multiple times.
Please remember to RESET your class variables declared in Solution, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
It is guaranteed that in a given test case the same buffer buf is called by read.
*/
class _0158_ReadNCharactersGivenRead4II {
public:
    int read(char* buf, int n);
private:
    int read4(char* buf);
    int readPos = 0;
    int writePos = 0;
    char buf4[4];
};

/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/
class _0159_LongestSubstringWithAtMostTwoDistinctCharacters {
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s);
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
    ListNode<int>* getIntersectionNode(ListNode<int>* headA, ListNode<int>* headB);
private:
    int length(ListNode<int>* root);
};

/*
Given two strings s and t, determine if they are both one edit distance apart.

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/
class _0161_OneEditDistance {
public:
    bool isOneEditDistance(std::string s, std::string t);
};



/*
A peak element is an element that is greater than its neighbors. Given an input array 
nums, where nums[i] ≠ nums[i+1], find a peak element and return its index. The array 
may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.
Example 1:

Input: nums = [1,2,3,1]          :         Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]    :         Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
or index number 5 where the peak element is 6.
*/
class _0162_FindPeakElement {
public:
    int findPeakElement(std::vector<int>& nums);
};

/*
Tag: sort, bucket sort, very special case
TODO
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
*/
class _0164_MaximumGap {
public:
    int maximumGap(std::vector<int>& nums);
};

/*
Tag: string,
TODO: Too much details need to be considered

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth 
second-level revision of the second first-level revision.
You may assume the default revision number for each level of a version number to be 0. 
For example, version number 3.4 has a revision number of 3 and 4 for its first and second 
level revision number. Its third and fourth level revision number are both 0.

Input: version1 = "0.1", version2 = "1.1"             :          Output: -1
Input: version1 = "1.0.1", version2 = "1"             :          Output: 1
Input: version1 = "7.5.2.4", version2 = "7.5.3"       :          Output: -1
Input: version1 = "1.01", version2 = "1.001"          :          Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a 
third level revision number, which means its third level 
revision number is default to "0"

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.
*/
class _0165_CompareVersionNumbers {
private:
    int findDot(const std::string& v);
    std::string removeHeadingZeros(const std::string& v);
public:
    int compareVersion(std::string version1, std::string version2);

};


/*
Tag: string, arithmatic, hash
TODO: Copy solution, need to fully understand what happened.
Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format. If the fractional part is repeating, 
enclose the repeating part in parentheses.

Input: numerator = 1, denominator = 2        :               Output: "0.5"
Input: numerator = 2, denominator = 1        :               Output: "2"
Input: numerator = 2, denominator = 3        :               Output: "0.(6)"
 */
class _0166_FractionToRecurringDecimal {
public:
std::string fractionToDecimal(int numerator, int denominator);
};

/*
Given an array of integers that is already sorted in ascending order, find two numbers such
that they add up to a specific target number. The function twoSum should return indices of 
the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same
element twice.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class _0167_TwoSumII_InputArrayIsSorted {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
};

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
class _0168_ExcelSheetColumnTitle {
public:
    std::string convertToTitle(int n);
};


/*
Given an array of size n, find the majority element. The majority element is the 
element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist 
in the array.

Input: [3,2,3]            :            Output: 3
Input: [2,2,1,1,1,2,2]    :            Output: 2
*/
class _0169_MajorityElement {
public:
    int majorityElement(std::vector<int>& nums);
};

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
class _0171_ExcellSheetColumnNumber {
public:
    int titleToNumber(std::string s);
};


/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/
class _0172_FactorialTrailingZeroes {
public:
    int trailingZeroes(int n);
};



/*
Facebook

Implement an iterator over a binary search tree (BST). Your iterator will be initialized 
with the root node of a BST. Calling next() will return the next smallest number in the BST.
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 
Note:
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the 
height of the tree. You may assume that next() call will always be valid, that is, there 
will be at least a next smallest number in the BST when next() is called.
*/
class _0173_BinarySearchTreeIterator {
public:
    _0173_BinarySearchTreeIterator(TreeNode<int>* root);
    
    /** @return the next smallest number */
    int next();
    
    /** @return whether we have a next smallest number */
    bool hasNext();
private:
    std::stack<TreeNode<int>*> st;
};

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right 
corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must 
fight his way through the dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at
any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative 
integers) upon entering these rooms; other rooms are either empty (0's) or 
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to 
move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he 
is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must 
be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
________________________
|-2 (K)	|  -3  |  3    |
------------------------
|  -5   | -10  |  1    |
------------------------
|  10	| 30   | -5 (P)|
------------------------

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight 
enters and the bottom-right room where the princess is imprisoned.
*/
class _0174_DungeonGame {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);
};

/*
Given a list of non negative integers, arrange them such that they 
form the largest number.

Input: [10,2]
Output: "210"

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
class _0179_LargestNumber {
public:
    std::string largestNumber(std::vector<int>& nums);
};

// 180 is a MySQL problem;
class _0180_ConsecutiveNumbers;
// 181 is a MySQL problem;
class _0181_EmployeesEarningMoreThanTheirManagers;
// 182 is a MySQL problem;
class _0182_DuplicateEmails;
// 183 is a MySQL problem;
class _0183_CustomersWhoeNeverOrder;
// 184 is a MySQL problem;
class _0184_DepartmentHighestSalary;
// 185 is a MySQL problem;
class _0185_DepartmentTopThreeSalaries;

/*
Given an input string , reverse the string word by word. 

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/
class _0186_ReverseWordsInAStringII {
public:
    void reverseWords(std::vector<char>& s);
};
/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to 
identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that 
occur more than once in a DNA molecule.

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class _0187_RepeatedDNASequences {
public:
    std::vector<std::string> findRepeatedDNASequences(std::string s);
};

/*
Tag: special topic 
 */
class _0188_BestTimeToBuyAndSellStockIV {

};

/*
Tag: string like reverse
Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
class _0189_RotateArray {
public:
    void rotate(std::vector<int>& nums, int k);
};



/*
Tag: bit operation
Reverse bits of a given 32 bits unsigned integer.
Example 1:
Input: 00000010100101000001111010011100
Output : 00111001011110000010100101000000
Explanation : The input binary string 00000010100101000001111010011100 
represents the unsigned integer 43261596, so return 964176192 which 
its binary representation is 00111001011110000010100101000000.
Example 2 :
Input : 11111111111111111111111111111101
Output : 10111111111111111111111111111111
Explanation : The input binary string 11111111111111111111111111111101 
represents the unsigned integer 4294967293, so return 3221225471 which 
its binary representation is 10101111110010110010011101101001.

Note :
Note that in some languages such as Java, there is no unsigned integer 
type. In this case, both input and output will be given as signed integer 
type and should not affect your implementation, as the internal binary 
representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement 
notation. Therefore, in Example 2 above the input represents the signed 
integer -3 and the output represents the signed integer -1073741825.
*/
class _0190_ReverseBits {
public:
    uint32_t reverseBits(uint32_t n);
};

/*
Given two non-empty binary trees s and t, check whether tree t has exactly 
the same structure and node values with a subtree of s. A subtree of s is 
a tree consists of a node in s and all of this node's descendants. The tree 
s could also be considered as a subtree of itself.

Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree
of s.

Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/
class _0191_NumberOf1Bits {
public:
    int hammingWeight(uint32_t n);
};

// 192 is a bash problem
class _0192_WordFrequency;
// 193 is a bash problem
class _0193_ValidPhoneNumbers;
// 194 is a bash problem
class _0194_TransposeFile;
// 195 is a bash problem
class _0195_TenthLine;
// 196 is a MySQL problem
class _0196_DeleteDuplicateEmails;
// 197 is a MySQL problem
class _0197_RisingTemperature;



/*
You are a professional robber planning to rob houses along 
a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them 
is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
class _0198_HouseRobber {
public:
    int rob(std::vector<int>& nums);
};


/*
Facebook

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
class _0199_BinaryTreeRightSideView {
public:
    std::vector<int> rightSideView(TreeNode<int>* root);
};


/*
Tag: backtracking

Given a 2d grid map of '1's (land) and '0's (water), count the number of 
islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all four edges 
of the grid are all surrounded by water.

Input:
11110
11010
11000
00000

Output: 1

Input:
11000
11000
00100
00011

Output: 3
*/
class _0200_NumberOfIslands {
public:
    int numIslands(std::vector<std::vector<char>>& grid);
    void eraseIsland(std::vector<std::vector<char>>& grid, int i, int j);
};

} // end namespace leetcode

#endif