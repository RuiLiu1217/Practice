#ifndef PROBLEM_SET13_HPP
#define PROBLEM_SET13_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
/*
You are given a square board of characters. You can move on the board starting 
at the bottom right square marked with the character 'S'.
You need to reach the top left square marked with the character 'E'. The rest 
of the squares are labeled either with a numeric character 1, 2, ..., 9 or with 
an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if 
there is no obstacle there.
Return a list of two integers: the first integer is the maximum sum of numeric 
characters you can collect, and the second is the number of such paths that you
 can take to get that maximum sum, taken modulo 10^9 + 7.
In case there is no path, return [0, 0].

Input: board = ["E23","2X2","12S"]
Output: [7,1]

Input: board = ["E12","1X1","21S"]
Output: [4,2]

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 
Constraints:

2 <= board.length == board[i].length <= 100
*/
class _1301_NumberOfPathsWithMaxScore {
public:
    std::vector<int> pathsWithMaxScore(std::vector<std::string>& bd);
};


/*
Given the array arr of positive integers and the array queries where 
queries[i] = [Li, Ri], for each query i compute the XOR of elements 
from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
*/
class _1310_XORQueriesOfASubarray {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries);
};
 

/*
Given an integer n. No-Zero integer is a positive integer 
which doesn't contain any 0 in its decimal representation.
Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. 
If there are many valid solutions you can return any of them.

Input: n = 2            Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't 
contain any 0 in their decimal representation.

Input: n = 11           Output: [2,9]
Input: n = 10000        Output: [1,9999]
Input: n = 69           Output: [1,68]
Input: n = 1010         Output: [11,999]

Constraints:

2 <= n <= 10^4
*/
class _1317_ConvertIntegerToTheSumOfTwoNonZeroIntegers {
public:
    std::vector<int> getNoZeroIntegers(int n);
};


/*
Given a m * n matrix mat of integers, sort it diagonally in 
ascending order from the top-left to the bottom-right then 
return the sorted array.

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
class _1329_SortTheMatrixDiagonally {
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);
};


/*
1337. The K Weakest Rows in a Matrix
User Accepted:3626
User Tried:3781
Total Accepted:3727
Total Submissions:5595
Difficulty:Easy
Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

struct comp {
  bool operator()(std::pair<int, int> const & p1, std::pair<int, int> const & p2) {
      return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
  }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, comp> pq;
        for(int i = 0; i < mat.size(); ++i) {
            pq.push({std::accumulate(begin(mat[i]), end(mat[i]), 0), i});
        }
        
        std::vector<int> res;
        int t = 0;
        while (t < k) {
            res.push_back(pq.top().second);
            pq.pop();
            ++t;
        }
        return res;
    }
};


1338. Reduce Array Size to The Half
User Accepted:3238
User Tried:3451
Total Accepted:3301
Total Submissions:5000
Difficulty:Medium
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
Example 3:

Input: arr = [1,9]
Output: 1
Example 4:

Input: arr = [1000,1000,3,7]
Output: 1
Example 5:

Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
 

Constraints:

1 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        std::unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); ++i) {
            ++map[arr[i]];
        }
        std::vector<std::pair<int,int>> statistic;
        for(auto& m : map) {
            statistic.push_back(m);
        }
        std::sort(begin(statistic), end(statistic), [](auto& a, auto& b){
            return (a.second > b.second);
        });
        int removeNum = 0;
        int accumuNum = 0;
        for(int i = 0; i < statistic.size(); ++i) {
            ++removeNum;
            accumuNum += statistic[i].second;
            if(accumuNum >= N / 2) {
                break;
            }
        }
        return removeNum;
    }
};
*/

/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 
edge such that the product of the sums of the subtrees are maximized.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025

Input: root = [1,1]
Output: 1

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].
*/
class _1339_MaximumProductOfSplittedBinaryTree {
private:
    std::unordered_map<TreeNode<int>*, int> map;
public:
    int maxProduct(TreeNode<int>* root);
    int subSum(TreeNode<int>* root);
};



/*
Given n orders, each order consist in pickup and delivery services. 
Count all valid pickup/delivery possible sequences such that 
delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
Example 3:

Input: n = 3
Output: 90

1 <= n <= 500
*/
class _1359_CountAllValidPickupAndDeliveryOptions {
public:
    int countOrders(int n );
};


/*
Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.
Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.


Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
 

Constraints:

1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5
*/
class _1400_ConstructKPalindromeStrings {
public:
    // Two conditions:
    // 1. the number of odd times characters must be <= k
    // 2. the total length of the string must >= k;
    bool canConstruct(std::string s, int k); 
};


}

#endif
