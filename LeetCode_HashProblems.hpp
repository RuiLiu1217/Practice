#ifndef LEETCODE_HASHPROBLEMS_HPP
#define LEETCODE_HASHPROBLEMS_HPP

#include "HeaderFiles.hpp"
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
    Given a pattern and a string str, find if str follows the same pattern.
    Here follow means a full match, such that there is a bijection between a 
    letter in pattern and a non - empty word in str.
    
    Example 1:
        Input: pattern = "abba", str = "dog cat cat dog"
        Output : true
    Example 2 :
        Input : pattern = "abba", str = "dog cat cat fish"
        Output : false
    Example 3 :
        Input : pattern = "aaaa", str = "dog cat cat dog"
        Output : false
    Example 4 :
        Input : pattern = "abba", str = "dog dog dog dog"
        Output : false
    Notes :
        You may assume pattern contains only lowercase letters, and str 
        contains lowercase letters separated by a single space.
*/
class _0290_WordPattern {
public:
    bool wordPattern(std::string pattern, std::string str) {
      std::istringstream iss(str);

      // Split a string into a string vector 
      std::vector<std::string> strVec(std::istream_iterator<std::string>{iss}, 
                                      std::istream_iterator<std::string>());  // Learn how to make the space-separated string to string vector

      if (pattern.size() != strVec.size()) {
          return false;
      }

      for (int i = 0; i < pattern.size(); ++i) {
          if (map.find(pattern[i]) == map.end()) {
              map[pattern[i]] = strVec[i];
          } else {
              if (map[pattern[i]] != strVec[i]) {
                  return false;
              }
          }

          if (map2.find(strVec[i]) == map2.end()) {
              map2[strVec[i]] = pattern[i];
          } else {
              if (map2[strVec[i]] != pattern[i]) {
                  return false;
              }
          }
      }
      return true;
    }
private:
    std::unordered_map<char, std::string> map;
    std::unordered_map<std::string, char> map2;
};


/*
Tag: hash
Facebook

Given two arrays, write a function to compute their intersection.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:
Each element in the result must be unique.
The result can be in any order.
*/
class _0349_IntersectionOfTwoArrays {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
};


/*
Given two arrays, write a function to compute their intersection.

Input: nums1 = [1,2,2,1], nums2 = [2,2]           :          Output: [2,2]
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]       :          Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class _0350_IntersectionOfTwoArraysII {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
};

/*
Tag: hash

Facebook

Given an array of integers with possible duplicates, randomly output 
the index of a given target number. You can assume that the given 
target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra 
space will not pass the judge.

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

pick(3) should return either index 2, 3, or 4 randomly. Each index 
should have equal probability of returning.
solution.pick(3);

pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/
class _0398_RandomPickIndex {
private:
    std::unordered_map<int, std::vector<int>> map;
public:
    _0398_RandomPickIndex(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
          map[nums[i]].push_back(i);
      }
    }
    int pick(int target) {
      std::vector<int>& range = map[target];
      int r = std::rand() % range.size();
      return range[r];
    }
};


/*
You are given the number of rows n_rows and number of columns n_cols of 
a 2D binary matrix where all values are initially 0. Write a function 
flip which chooses a 0 value uniformly at random, changes it to 1, and 
then returns the position [row.id, col.id] of that value. Also, write a 
function reset which sets all values back to 0. Try to minimize the number 
of calls to system's Math.random() and optimize the time and space 
complexity.

Note:

1 <= n_rows, n_cols <= 10000
0 <= row.id < n_rows and 0 <= col.id < n_cols
flip will not be called when the matrix has no 0 values left.
the total number of calls to flip and reset will not exceed 1000.

Input: 
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
Output: [null,[0,1],[1,2],[1,0],[1,1]]

Input: 
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
Output: [null,[0,0],[0,1],null,[0,0]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's 
constructor has two arguments, n_rows and n_cols. flip and reset have no 
arguments. Arguments are always wrapped with a list, even if there aren't any.
*/
class _0519_RandomFlipMatrix {
private:
  std::unordered_map<int, int> occupied;
  int nRows;
  int nCols;
  int remain;
  
  std::mt19937 rng{std::random_device{}()};
  
  int randInt(int bound) {
      std::uniform_int_distribution<int> uni(0, bound);
      return uni(rng);
  }
public:
  _0519_RandomFlipMatrix(int n_rows, int n_cols);
  std::vector<int> flip();
  void reset();
};


/*
  Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a 
  list of favorite restaurants represented by strings.
  You need to help them find out their common interest with the least list index sum. 
  If there is a choice tie between answers, output all of them with no order requirement. 
  You could assume there always exists an answer.

  Input:
  ["Shogun", "Tapioca Express", "Burger King", "KFC"]
  ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
  Output: ["Shogun"]
  Explanation: The only restaurant they both like is "Shogun".

  Input:
  ["Shogun", "Tapioca Express", "Burger King", "KFC"]
  ["KFC", "Shogun", "Burger King"]
  Output: ["Shogun"]
  Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
  Note:
  The length of both lists will be in the range of [1, 1000].
  The length of strings in both lists will be in the range of [1, 30].
  The index is starting from 0 to the list length minus 1.
  No duplicates in both lists.
*/
class _0599_MinimumIndexSumOfTwoLists {
public:
    std::vector<std::string> findRestaruant(std::vector<std::string>& list1, std::vector<std::string>& list2);
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
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have. Each character in S is a type of 
stone you have. You want to know how many of the stones you have are also 
jewels.
The letters in J are guaranteed distinct, and all characters in J and S 
are letters. Letters are case sensitive, so "a" is considered a different 
type of stone from "A".

Input: J = "aA", S = "aAAbbbb"
Output: 3

Input: J = "z", S = "ZZ"
Output: 0
Note: S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
class _0771_JewelsAndStones {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::set<char> Js;
        for(auto a : J) {
            Js.insert(a);
        }
        int jnum = 0;
        for(auto b : S) {
            if(Js.find(b) != Js.end()) {
                jnum++;
            }
        }
        return jnum;
    }
};

/*
Given an array of integers arr, write a function that returns true if and only if the 
number of occurrences of each value in the array is unique.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the 
same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/
class _1207_UniqueNumberOfOccurances {
public:
    bool uniqueOccurrences(std::vector<int>& arr);
};

/*
Given an integer array arr and an integer difference, return the length of the 
longest subsequence in arr which is an arithmetic sequence such that the 
difference between adjacent elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/
class _1218_LongestArithmeticSubsequenceOfGivenDifference {
public:
    int longestSubsequence(std::vector<int>& arr, int difference);
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

/*
  Given an array of integers nums.
  A pair (i,j) is called good if nums[i] == nums[j] and i < j.
  Return the number of good pairs.
  
  Input: nums = [1,2,3,1,1,3]
  Output: 4
  Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
  
  Input: nums = [1,1,1,1]
  Output: 6
  Explanation: Each pair in the array are good.
  
  Input: nums = [1,2,3]
  Output: 0
  
  Constraints:
      1 <= nums.length <= 100
      1 <= nums[i] <= 100
  */
  class _1512_NumberOfGoodPairs {
  public:
      int numIdenticalPairs(std::vector<int>& nums);
  };


  /*
  1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
  Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:

    Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
    Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
    

    Example 1:

    Input: nums1 = [7,4], nums2 = [5,2,8,9]
    Output: 1
    Explanation: Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. (4^2 = 2 * 8). 
    Example 2:

    Input: nums1 = [1,1], nums2 = [1,1,1]
    Output: 9
    Explanation: All Triplets are valid, because 1^2 = 1 * 1.
    Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]^2 = nums2[j] * nums2[k].
    Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].
    Example 3:

    Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
    Output: 2
    Explanation: There are 2 valid triplets.
    Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
    Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].
    Example 4:

    Input: nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
    Output: 0
    Explanation: There are no valid triplets.
    

    Constraints:

    1 <= nums1.length, nums2.length <= 1000
    1 <= nums1[i], nums2[i] <= 10^5
  */
 class _1577_NumberOfWaysWhereSquareOfNumberIsEqualToProductOfTwoNumbers{
     public:
        int numTriplets(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::sort(begin(nums1), end(nums1));
            std::sort(begin(nums2), end(nums2));
            
            auto twoProduct = [](long prod, std::vector<int>& n) {
                std::unordered_map<int, int> m;
                int cnt = 0;
                for(auto v : n) {
                    if(v > prod) {
                        break;
                    }
                    if(prod % v == 0) {
                        cnt += m[prod / v];
                    }
                    ++m[v];
                }
                return cnt;
            };
            
            int res = std::accumulate(begin(nums1), end(nums1), 0, [&](int s, long n) {
                return s + twoProduct(n * n, nums2);
            }) + 
            std::accumulate(begin(nums2), end(nums2), 0, [&](int s, long n) {
                return s + twoProduct(n * n, nums1);
            });
            return res;
        }
 };
}
#endif