#ifndef PROBLEM_SET2_HPP
#define PROBLEM_SET2_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "Tree.hpp"
#include "LinkList.hpp"
#include "Trie.hpp"
namespace LeetCode {
/*
Tag: palindrome, KMP
TODO: Familar with KMP algorithm, especially how to calculate the next[] array

Given a string s, you are allowed to convert it to a palindrome by 
adding characters in front of it. Find and return the shortest 
palindrome you can find by performing this transformation.

Input: "aacecaaa"           :          Output: "aaacecaaa"
Input: "abcd"               :          Output: "dcbabcd"
Credits:
Special thanks to @ifanchu for adding this problem and creating all test 
cases. Thanks to @Freezen for additional test cases. 
*/
class _0214_ShortestPalindrome {
public:
    std::string shortestPalindrome(std::string s);
};


/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a
distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo 
(Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are 
the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed 
that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles 
grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], 
[19 24 8] ] .
The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that 
uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, 
where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. 
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], 
[11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: 
[...[2 3], [4 5], [12 7], ...]
*/
// https://youtu.be/8Kd-Tn_Rz7s
class _0218_TheSkylineProblem {
    public:
        std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings);
};



/*
Given an array of integers, find out whether there are two distinct 
indices i and j in the array such that the absolute difference between 
nums[i] and nums[j] is at most t and the absolute difference between 
i and j is at most k.

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
 
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
class _0220_ContainsDuplicateIII {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t);
};


/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Input: "3+2*2"       :         Output: 7
Input: " 3/2 "       :         Output: 1
Input: " 3+5 / 2 "   :         Output: 5

Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class _0227_BasicCalculatorII {
public:
    int calculate(std::string s);
};

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

Input: [3,2,3]
Output: [3]

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
class _0229_MajorityElementII {
public:
    std::vector<int> majorityElement(std::vector<int>& nums);
};




/*
Given an integer n, count the total number of digit 1 appearing 
in all non-negative integers less than or equal to n.

Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:
Beware of overflow.
*/
class _0233_NumberOfDigitOne {
public:
    int countDigitOne(int n);
};



/*
Write an efficient algorithm that searches for a value 
in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

    Consider the following matrix:
    [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    Given target = 5, return true.
    Given target = 20, return false.
*/
class _0240_SearchA2DMatrix_II {
private:
    std::map<std::string, std::vector<int>> map;
public:
    bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target);
};




/*
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

Input:  root = [5,1,5,5,5,null,5]

        5
       / \
      1   5
     / \   \
    5   5   5

Output: 4
*/
class _0250_CountUnivalueSubtrees {
public:
    int countUnivalSubtrees(TreeNode<int>* root);
private:
    int count = 0;
    bool isUnique(TreeNode<int>* root);
};

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Input: [[0,30],[5,10],[15,20]]
Output: false

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class _0252_MeetingRooms {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals);
};

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
Input: [[0, 30],[5, 10],[15, 20]]            :         Output: 2
Input: [[7,10],[2,4]]                        :         Output: 1
*/
class _0253_MeetingRoomsII {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals);
};

/*
Tag: serialization

Google, but I don't know why I cannot get a correct result

Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded 
back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

The string may contain any possible characters out of 256 valid ascii characters. 
Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and 
decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should 
implement your own encode/decode algorithm.
*/
class _0271_EncodeAndDecodeStrings {

};

/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Input: 123
Output: "One Hundred Twenty Three"

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/
class _0273_IntegerToEnglishWords {
public:
    std::string numberToWords(int num);
};

/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
class _0274_HIndex {
public:
    int hIndex(std::vector<int>& citations);
};

/*
Given an array of citations sorted in ascending order (each citation is a 
non-negative integer) of a researcher, write a function to compute the researcher's 
h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h 
if h of his/her N papers have at least h citations each, and the other N − h 
papers have no more than h citations each."

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.

If there are several possible values for h, the maximum one is taken as the h-index.

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
*/
class _0275_HIndexII {
public:
    int hIndex(std::vector<int>& citations);
};


/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
class _0279_PerfectSquares {
public:
    int numSquares(int n);
};

/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() 
operation -- it essentially peek() at the element that will be returned by the next call to next().


Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/
class Iterator {
public:
    struct Data {};
    Data* data;
    Iterator(const std::vector<int>& nums) {

    }
    Iterator(const Iterator& iter);

    int next();
    bool hasNext() const;
};

class _0284_PeekingIterator : public Iterator {
public:
    _0284_PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {}
    int peek() {
        return Iterator(*this).next(); // The only difficulty is why here?
    }
    int next() {
        return Iterator::next();
    }
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Input: [1,3,4,2,2]
Output: 2

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
! Find the duplicate number
*/
class _0287_FindTheDuplicateNumber {
public:
    int findDuplicate(std::vector<int>& nums);
};

/*
Tag: hash
Google

An abbreviation of a word follows the form <first letter><number><last letter>. 
Below are some examples of word abbreviations:
a) it --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓    
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is 
unique in the dictionary. A word's abbreviation is unique if no other word from 
the dictionary has the same abbreviation.

Example:
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/
class _0288_UniqueWordAbbreviation {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> mp;
public:
    _0288_UniqueWordAbbreviation(std::vector<std::string>& dictionary);
    bool isUnique(std::string word);
};


/*
You are playing the following Nim Game with your friend: There is a heap of stones 
on the table, each time one of you take turns to remove 1 to 3 stones. The one who 
removes the last stone will be the winner. You will take the first turn to remove the stones.
Both of you are very clever and have optimal strategies for the game. Write a 
function to determine whether you can win the game given the number of stones in the heap.

Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be 
             removed by your friend.
*/
class _0292_NimGame {
public:
    bool canWinNim(int n);
};



/*
Facebook

Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, or 
transmitted across a network connection link to be reconstructed later in the 
same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no 
restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary 
tree. You do not necessarily need to follow this format, so please be creative 
and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your 
serialize and deserialize algorithms should be stateless.
*/
class _0297_SerializeAndDeserializeBinaryTree {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode<int>* root);
    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(std::string data);
};

/*
You are playing the following Bulls and Cows game with your friend: You write down 
a number and ask your friend to guess what the number is. Each time your friend 
makes a guess, you provide a hint that indicates how many digits in said guess match 
your secret number exactly in both digit and position (called "bulls") and how many 
digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret 
number.
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. 
Please note that both secret number and friend's guess may contain duplicate digits.

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain 
digits, and their lengths are always equal.
*/
class _0299_BullsAndCows {
public:
    std::string getHint(std::string secret, std::string guess);
};

/*
Given an unsorted array of integers, find the length of longest increasing 
subsequence.
Example:
Input: [10,9,2,5,3,7,101,18]       :       Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:
There may be more than one LIS combination, it is only necessary for you to return 
the length. Your algorithm should run in O(n2) complexity. 
Follow up: Could you improve it to O(n log n) time complexity?
*/
class _0300_LongestIncreasingSubsequence {
public:
    int lengthOfLIS(std::vector<int>& nums);
private:
    int lengthOfLIS_N2(std::vector<int>& nums);
    int lengthOfLIS_NlogN(std::vector<int>& nums);
};

}
#endif