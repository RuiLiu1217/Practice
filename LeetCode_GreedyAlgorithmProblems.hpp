#ifndef LEETCODE_GREEDYALGORITHMPROBLEMS_HPP
#define LEETCODE_GREEDYALGORITHMPROBLEMS_HPP
#include <vector>
#include <string>
namespace LC {

    /* TODO
Tag: greedy algorithm
Given n non-negative integers a1, a2, ..., an , where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this 
case, the max area of water (blue section) the container can contain is 49. 

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class _0011_ContainerWithMostWater {
public:
    int maxArea(std::vector<int>& height);
};


/* TODO
Tag: greedy algorithm, hash
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is 
written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written 
as IV. Because the one is before the five we subtract it making four. The same 
principle applies to the number nine, which is written as IX. There are six 
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Input: 3
Output: "III"

Input: 4
Output: "IV"

Input: 9
Output: "IX"

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class _0012_IntegerToRoman {
public:
    std::string intToRoman(int num);
};

/*
Tag: numeric, string
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together. Twelve 
    is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, 
    which is XX + V + II.
    Roman numerals are usually written largest to smallest from left to right. However, the 
    numeral for four is not IIII. Instead, the number four is written as IV. Because the one 
    is before the five we subtract it making four. The same principle applies to the number 
    nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range 
    from 1 to 3999.

    Example:
    Input: "III"     :      Output: 3
    Input: "IV"      :      Output: 4
    Input: "IX"      :      Output: 9
    Input: "LVIII"   :      Output: 58     (Explanation: L = 50, V= 5, III = 3)
    Input: "MCMXCIV" :      Output: 1994   (Explanation: M = 1000, CM = 900, XC = 90 and IV = 4)
*/
class _0013_RomanToInteger {
public:
    int romainToInt(std::string s);
};

/*
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers 
from two different arrays (each array picks one) and calculate the distance. We define the 
distance between two integers a and b to be their absolute difference |a-b|. Your task is to 
find the maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:
Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
*/
// 一开始蒙住了
class _0624_MaximumDistanceInArrays {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays);
};

}
#endif