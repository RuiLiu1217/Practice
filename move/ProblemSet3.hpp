#ifndef PROBLEM_SET3_HPP
#define PROBLEM_SET3_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {

/*
Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except 
for the first two numbers, each subsequent number in the sequence must 
be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to 
determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so 
sequence 1, 2, 03 or 1, 02, 3 is invalid.

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
    1 + 99 = 100, 99 + 100 = 199

Constraints:
num consists only of digits '0'-'9'.
1 <= num.length <= 35
Follow up:
How would you handle overflow for very large input integers?
*/
class _0306_AdditiveNumber {
public:
    bool isAdditiveNumber(std::string num);
    bool isAdditiveNumber(std::string& num, int start1, int start2, int start3);
    std::string add(std::string a, std::string b);
};

/*
完全是数据结构segment tree 或者Fenwick tree驱动的题目

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
class _0307_RangeSumQuery_Mutable {
private:
    std::vector<int> data;
    int arrayLength;

    class SegTreeArray {
    private:
        std::vector<int> tree;
        void buildTree(std::vector<int>& arr, int treeIndex, int start, int end) {
            if(start == end) {
                tree[treeIndex] = arr[start];
                return;
            }
            int mid = start + (end - start) / 2;
            buildTree(arr, treeIndex * 2 + 1, start, mid);
            buildTree(arr, treeIndex * 2 + 2, mid+1, end);

            tree[treeIndex] = tree[treeIndex * 2 + 1] + tree[treeIndex * 2 + 2];
        }
        int query(int treeIndex, int start, int end, int i, int j) {
            if(start > j || end < i) {
                return 0;
            }
            if(i <= start && j >= end) {
                return tree[treeIndex];
            }
            int mid = start + (end - start) / 2;
            if(j <= mid) {
                return query(treeIndex * 2 + 1, start, mid, i, j);
            } else if(i > mid) {
                return query(treeIndex * 2 + 2, mid+1, end, i, j);
            } else {
                int left = query(treeIndex * 2 + 1, start, mid, i, mid);
                int right = query(treeIndex * 2 + 2, mid+1, end, mid+1, j);
                return tree[treeIndex] = left + right;
            }
        }
        void update(int treeIndex, int start, int end, int arrIdx, int val) {
            if(start == end) {
                tree[treeIndex] = val;
                return;
            }
            int mid = start + (end - start) / 2;
            if(arrIdx <= mid) {
                update(treeIndex * 2 + 1, start, mid, arrIdx, val);
            } else if(arrIdx > mid) {
                update(treeIndex * 2 + 2, mid+1, end, arrIdx, val);
            }
            tree[treeIndex] = tree[treeIndex * 2 + 1] + tree[treeIndex * 2 + 2];
        }
    public:
        SegTreeArray(std::vector<int>& arr) {
            arrayLength = arr.size();
            data.resize(arrayLength, 0);
            buildTree(arr, 0, 0, arrayLength-1);
        }

        int query(int i, int j) {
            return query(0, 0, arrayLength-1, i, j);
        }

        void update(int arrIdx, int val) {
            update(0, 0, arrayLength - 1, arrIdx, val);
        }

    };

public:
    SegTreeArray segTree;
    _0307_RangeSumQuery_Mutable(std::vector<int>& nums): segTree(nums) {
        
    }
    void update(int i, int val) {
        segTree.update(i, val);
    }
    int sumRange(int i, int j) {
        return segTree.query(i, j);
    }
};

/*
For an undirected graph with tree characteristics, we can choose any node as 
the root. The result graph is then a rooted tree. Among all possible rooted 
trees, those with minimum height are called minimum height trees (MHTs). Given 
such a graph, write a function to find all the MHTs and return a list of their 
root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given 
the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are
undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
*/
class _0310_MinimumHeightTrees {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges);
};




/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given 
prime list primes of size k.

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
    super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/
class _0313_SuperUglyNumber {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes);
private:
    int _min(std::vector<int>& res, std::vector<int>& idx, std::vector<int>& primes);
};



/*
You are given an integer array nums and you have to return a new counts array. The 
counts array has the property where counts[i] is the number of smaller elements to 
the right of nums[i].

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class _0315_CountOfSmallerNumberAfterSelf {
public:
    std::vector<int> countSmaller(std::vector<int>& nums);
};

/*
Given a string which contains only lowercase letters, remove duplicate letters 
so that every letter appears once and only once. You must make sure your result 
is the smallest in lexicographical order among all possible results.

Input: "bcabc"          :           Output: "abc"
Input: "cbacdcbc"       :           Output: "acdb"

 https://www.youtube.com/watch?v=SrlvMmfG8sA
 分别用两个数组来记录，第一个数组统计各个字母出现的次数
 第二个数组用于记录这个字符是否用过了
*/
class _0316_RemoveDuplicateLetters {
public:   
    std::string removeDuplicateLetters(std::string s);
};

/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you 
turn off every second bulb. On the third round, you toggle every third bulb (turning 
on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. 
For the n-th round, you only toggle the last bulb. Find how many bulbs are on after 
n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/
class _0319_BulbSwitcher {
public:
    int bulbSwitch(int n);
};

/*
Tag: Google
   
Write a function to generate the generalized abbreviations of a word. 
Note: The order of the output does not matter.
Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", 
"1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
! Copy from the solution. 
*/
class _0320_GeneralizedAbbreviation {
public:
    std::vector<std::string> generalizeAbbreviations(std::string word);
    std::vector<std::string> generateAbbreviations(std::string word);
private:
    std::vector<std::string> generateAbbreviations_v2(std::string word);
};

/*
Given two arrays of length m and n with digits 0-9 representing two 
numbers. Create the maximum number of length k <= m + n from digits
of the two. The relative order of the digits from the same array 
must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
 经典题，必会的，DP + Greedy
将问题拆分成两步，第一步两个数组合并，如果都用上，如何得到最大，第二步，在一个数组中拿k个数，怎么得到最大。
 第三步，分别在两个数组中拿k1，k-k1 个元素，各自最大，然后合并出最大于当前的，直到遍历所有可能的k1
*/
class _0321_CreateMaximumNumber {
public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k);
private:
    std::vector<int> maxNumber(const std::vector<int>& nums1,const std::vector<int>& nums2);
    std::vector<int> maxNumber(const std::vector<int>& nums, int k);
};


/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/
class _0325_MaximumSizeSubarraySumEqualsK {
public:
    int maxSubArrayLen(std::vector<int>& nums, int k);
};



/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT 
move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
class _0329_LongestIncreasingPathInAMatrix {
private:
    std::vector<std::vector<int>> DP;
    int mRow;
    int mCol;
    int DFS(const std::vector<std::vector<int>>& matrix, int I, int J);
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix);
};

/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array 
such that any number in range [1, n] inclusive can be formed by the sum of some elements in 
the array. Return the minimum number of patches required.

Input: nums = [1,3], n = 6
Output: 1 
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
*/
class _0330_PatchingArray {
public:
    int minPatches(std::vector<int>& nums, int n);
};


/*
The thief has found himself a new place for his thievery again. There is only one 
entrance to this area, called the "root." Besides the root, each house has one and 
only one parent house. After a tour, the smart thief realized that "all houses in 
this place forms a binary tree". It will automatically contact the police if two 
directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting 
the police.

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
class _0337_HouseRobberIII {
private:
    std::unordered_map<TreeNode<int>*, int> Map;
public:
    int rob(TreeNode<int>* root);
private:
    int robHelper(TreeNode<int>* root);
};

/*
Given a non negative integer number num. For every numbers i in the range 
0 ≤ i ≤ num calculate the number of 1's in their binary representation and 
return them as an array.

Input: 2  :  Output: [0,1,1]

Input: 5  :  Output: [0,1,1,2,1,2]

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like 
__builtin_popcount in c++ or in any other language.
*/
class _0338_CountingBits {
public:
    std::vector<int> countBits(int num);
};

/*
    Given a nested list of integers, implement an iterator to flatten it.
    Each element is either an integer, or a list -- whose elements may 
    also be integers or other lists.

    Example 1:
    Input: [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,1,2,1,1].

    Example 2:
    Input: [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,4,6].
*/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    std::vector<NestedInteger> &getList() const;
};

/*
Given a nested list of integers, return the sum of all integers in the list weighted by 
their depth. Each element is either an integer, or a list -- whose elements may also be 
integers or other lists.

Input: [[1,1],2,[1,1]]
Output: 10 
Explanation: Four 1's at depth 2, one 2 at depth 1.

Input: [1,[4,[6]]]
Output: 27 
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
*/
class _0339_NestedListWeightSum {
public:
    int depthSum(std::vector<NestedInteger>& nestedList);
private:
    int depthSum(std::vector<NestedInteger>& nestedList, int depth);
};


// TODO: COPY FROM A SOLUTION
class _0341_FlattenNestedListIterator {
private:
    std::vector<NestedInteger> nl;
    _0341_FlattenNestedListIterator *itr = nullptr;
    int index = -1;

public:
    _0341_FlattenNestedListIterator(std::vector<NestedInteger> &nestedList);

    int next();
    bool hasNext();
    bool hasContent(std::vector<NestedInteger> V);
    void increaseIndex();
};

/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given 
points symmetrically, in other words, answer whether or not if there exists a line that after reflecting 
all points over the given line the set of the original points is the same that the reflected ones.

Note that there can be repeated points.

Follow up:
Could you do better than O(n2) ?

Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.

Constraints:

n == points.length
1 <= n <= 10^4
-10^8 <= points[i][j] <= 10^8
*/
class _0356_LineReflection {
public:
    bool isReflected(std::vector<std::vector<int>>& points);
};

/*
Given a non-negative integer n, count all numbers with unique 
digits, x, where 0 ≤ x < pow(10, n).

Example:
Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
                excluding 11,22,33,44,55,66,77,88,99
*/
class _0357_CountNumbersWithUniqueDigits {
public:
    int countNumbersWithUniqueDigits(int n);
private:
    // For n-digits, it is a simple combination problem
    // The first digit has 9 choices.
    // From the second digits, 9 , 8, 7 ... selections until 1
    int countExactDigit(int n);
};

/*
Design a logger system that receive stream of messages along with 
its timestamps, each message should be printed if and only if it 
is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return 
true if the message should be printed in the given timestamp, 
otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Logger logger = new Logger();

logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
*/
class _0359_LoggerRateLimiter {
private:
    std::unordered_map<std::string, int> map;
public:
    _0359_LoggerRateLimiter() {}
    bool shouldPrintMessage(int timeStamp, std::string message);
};



/*
Tag: Data Structure
Google

Design a hit counter which counts the number of hits received 
in the past 5 minutes.
Each function accepts a timestamp parameter (in seconds granularity) 
and you may assume that calls are being made to the system in 
chronological order (ie, the timestamp is monotonically increasing). 
You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/
class _0362_DesignHitCounter {
    class Node {
    public:
        int timeStamp;
        int hitNum;
        Node* prev;
        Node* next;
    };
private:
    Node* head;
    Node* tail;
public:
    _0362_DesignHitCounter() {
        head = nullptr;
        tail = nullptr;
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). 
    */
    void hit(int timestamp);

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). 
    */
    int getHits(int timestamp);
};

/*
Given a nested list of integers, return the sum of all integers in the list 
weighted by their depth. Each element is either an integer, or a list -- 
whose elements may also be integers or other lists. Different from the previous 
question where weight is increasing from root to leaf, now the weight is 
defined from bottom up. i.e., the leaf level integers have weight 1, and the 
root level integers have the largest weight.

Input: [[1,1],2,[1,1]]
Output: 8 
Explanation: Four 1's at depth 1, one 2 at depth 2.

Input: [1,[4,[6]]]
Output: 17 
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
*/
class NestedInteger;
class _0364_NestedListWeightSumII {
public:
    int depthSumInv(std::vector<NestedInteger>& nestedList, int level);;
};


/*
Given a set of distinct positive integers, find the largest subset such that every pair 
(Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class _0368_LargestDivisibleSubset {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums);
};


/*
A sequence of numbers is called a wiggle sequence if the differences between 
successive numbers strictly alternate between positive and negative. The first 
difference (if one exists) may be either positive or negative. A sequence 
with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences 
(6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] 
and [1,7,4,5,5] are not wiggle sequences, the first because its first two 
differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that 
is a wiggle sequence. A subsequence is obtained by deleting some number of elements 
(eventually, also zero) from the original sequence, leaving the remaining elements 
in their original order.

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/
class _0376_WiggleSubsequence {
public:
    int wiggleMaxLength(std::vector<int>& nums);
};

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible 
combinations that add up to a positive integer target.

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/
class _0377_CombinationSumIV {
public:

};


/*
    Given a n x n matrix where each of the rows and columns 
    are sorted in ascending order, find the kth smallest element 
    in the matrix.
    
    Note that it is the kth smallest element in the sorted order, 
    not the kth distinct element.
    
    Example:
    matrix = [
            [ 1,  5,  9],
            [10, 11, 13],
            [12, 13, 15]
    ], k = 8, 
    
    return 13.
*/
class _0378_KthSmallestElementInASortedMatrix {
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k);
private:
    int search_less_equal(std::vector<std::vector<int>> &matrix, int target);
};

/*
Insert Delete GetRandom O(1) 
Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/
class _0380_RandomizedSet {
private:
    std::unordered_map<int, int> valueIndex;
    std::vector<int> values;
public:
    /** Initialize your data structure here. */
    _0380_RandomizedSet();    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val);    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val);    
    /** Get a random element from the set. */
    int getRandom();
};

/*
Insert Delete GetRandom O(1) - Duplicates allowed
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/
class _0381_RandomizedCollection {
private:
    std::vector<int> data;
    std::unordered_map<int, std::unordered_set<int>> map;
public:
    /** Initialize your data structure here. */
    _0381_RandomizedCollection();
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val);
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val);
    
    /** Get a random element from the collection. */
    int getRandom();
};



/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
 

Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
 

Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/
class _0385_MiniParser{
public:
class NestedInteger {
 public:
     // Constructor initializes an empty nested list.
     NestedInteger();
     // Constructor initializes a single integer.
     NestedInteger(int value) {}
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const { 
         return true; 
     }
     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const {
         return 0;
     }
      // Set this NestedInteger to hold a single integer.
     void setInteger(int value);
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
      // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> getList() const {
        return std::vector<NestedInteger>();
    }
 };

NestedInteger deserialize(std::string s);
};


/*
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.
*/
class _0386_LexicographicalNumbers {
private:
    std::vector<int> res;
    void dfs(int cur, int n);
public:
    std::vector<int> lexicalOrder(int n);
};



/*
Tag: Stack, string
GOOGLE
TODO:
Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory 
subdir2 containing a file file.ext.
The string 
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 
represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains 
a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains 
a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file 
within our file system. For example, in the second example above, the longest absolute 
path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the 
double quotes).

Given a string representing the file system in the above format, return the length 
of the longest absolute path to file in the abstracted file system. If there is no 
file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another 
path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/
class _0388_LongestAbsoluteFilePath {
public:
    int lengthLongestPath(std::string input);
};


/*
Elimination Game
There is a list of sorted integers from 1 to n. Starting from left to right,
remove the first number and every other number afterward until you reach the
end of the list.

Repeat the previous step again, but this time from right to left, remove the
right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left,
until a single number remains.

Find the last number that remains starting with a list of length n.

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/
class _0390_EliminationGame {
public:
    int lastRemaining(int n);
};


/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed 
by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store 
the data. This means each integer represents only 1 byte of data.

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
*/
class _0393_UTF8Validation {
public:
    bool validUTF8(std::vector<int>& data);
};

/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string 
inside the square brackets is being repeated exactly k times. Note 
that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra 
white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain 
any digits and that digits are only for those repeat numbers, k. 
For example, there won't be input like 3a or 2[4].

    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class _0394_DecodeString {
public:
    std::string decodeString(std::string s);
};


/*
Equations are given in the format A / B = k, where A and B are variables represented 
as strings, and k is a real number (floating point number). Given some queries, 
return the answers. If the answer does not exist, return -1.0.

Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, 
vector<pair<string, string>> queries , where equations.size() == values.size(), and the 
values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 
The input is always valid. You may assume that evaluating the queries will result 
in no division by zero and there is no contradiction.
*/
class _0399_EvaluateDivision {
private:
    // A hash function used to hash a pair of any kind 
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const std::pair<T1, T2>& p) const
        { 
            auto hash1 = std::hash<T1>{}(p.first); 
            auto hash2 = std::hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
    std::unordered_set<std::string> node;
    std::unordered_map<std::pair<std::string, std::string>, double, hash_pair> edge;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::vector<std::string>> adjMap;
    void resetVisit();
    std::vector<std::string> getAdj(std::string a);
    
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, 
    std::vector<double>& values, std::vector<std::vector<std::string>>& queries);    
    double calculate(std::string a, std::string b);
};

/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Input: 3      :     Output: 3
Input: 11     :     Output: 0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
class _0400_NthDight {
public:
    int findNthDigit(int n);
};

}

#endif