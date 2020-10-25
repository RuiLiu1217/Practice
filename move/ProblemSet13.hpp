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
