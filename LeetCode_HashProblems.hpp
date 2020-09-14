#ifndef LEETCODE_HASHPROBLEMS_HPP
#define LEETCODE_HASHPROBLEMS_HPP

#include <string>
#include <vector>
#include <unordered_map>
namespace LC {
/*
Group Anagrams :  Given an array of strings, group anagrams together.
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
class _0049_GroupAnagrams { 
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
};

/*
Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.

Optimize it such that it minimizes the call to system’s Math.random().

Note:

1 <= N <= 1000000000
0 <= B.length < min(100000, N)
[0, N) does NOT include N. See interval notation.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
Output: [null,0,0,0]
Example 2:

Input: 
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
Output: [null,1,1,1]
Example 3:

Input: 
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
Output: [null,0,0,2]
Example 4:

Input: 
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
Output: [null,1,3,1]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. 
Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. 
Arguments are always wrapped with a list, even if there aren't any.
*/
class _0710_RandomPickWithBlacklist {
private:
  int n;
  int bl;
  std::unordered_map<int, int> blkMap;
public:
  _0710_RandomPickWithBlacklist(int N, std::vector<int>& blacklist);
  int pick();
};

/*
Given the string s, return the size of the longest substring containing each vowel an even number 
of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times. 

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.

Constraints:
1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.

这道题看了答案之后才懂，不是滑动窗口题目，虽然第一眼看上去像，不过得用hash table 来保存第一次遇到元音字母的位置，每次遇到，如果状态恢复到之前碰到的
状态，那么之间的这一段就是偶数个元音字母的字符串，从一开始，一个元音字母都没有的情况假设它对应的index为-1.
*/
class _1371_FindTheLongestSubstringContainingVowelsInEvenCounts {
public:
  int findTheLongestSubstring(std::string s);
};

}
#endif