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
Given a binary tree where all the right nodes are either leaf nodes with a sibling 
(a left node that shares the same parent node) or empty, flip it upside down and 
turn it into a tree where the original right nodes turned into left leaf nodes. 
Return the new root.

Example:

Input: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

Output: return the root of the binary tree [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
Clarification:

Confused what [4,5,2,#,#,3,1] means? Read more below on how binary tree is serialized on OJ.

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as [1,2,3,#,#,4,#,#,5].
*/
class _0156_BinaryTreeUpsideDown {
public:
    TreeNode<int>* upsideDownBinaryTree(TreeNode<int>* root);
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
Tag: special topic 
 */
class _0188_BestTimeToBuyAndSellStockIV {

};


} // end namespace leetcode

#endif