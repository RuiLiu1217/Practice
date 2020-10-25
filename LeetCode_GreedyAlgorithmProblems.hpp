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
TODO
Tag: BFS
Note: be careful of boundary conditions

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Input: [2,3,1,1,4]
Output: 2
The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 
3 steps to the last index.

You can assume that you can always reach the last index.
! 难题，需要再一次好好理解
! 这道题必须掌握.
*/
class _0045_JumpGameII {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // max position one could reach 
        // starting from index <= i 
        int maxPos = nums[0];
        // max number of steps one could do
        // inside this jump
        int maxSteps = nums[0];
        
        int jumps = 1;
        for (int i = 1; i < n; ++i) {
            // if to reach this point 
            // one needs one more jump
            if (maxSteps < i) {
                ++jumps;
                maxSteps = maxPos;
            }
            maxPos = std::max(maxPos, nums[i] + i);
        }
        return jumps;
    }
    /*    
    This problem has a nice BFS structure. Let's illustrate it 
    using the example nums = [2, 3, 1, 1, 4] in the problem statement. 
    We are initially at position 0. Then we can move at most nums[0] 
    steps from it. So, after one move, we may reach nums[1] = 3 or 
    nums[2] = 1. So these nodes are reachable in 1 move. From these 
    nodes, we can further move to nums[3] = 1 and nums[4] = 4. 
    Now you can see that the target nums[4] = 4 is reachable in 2 moves.
    Putting these into codes, we keep two pointers start and end that 
    record the current range of the starting nodes. Each time after we 
    make a move, update start to be end + 1 and end to be the farthest 
    index that can be reached in 1 move from the current [start, end].
    To get an accepted solution, it is important to handle all the edge 
    cases. And the following codes handle all of them in a unified way 
    without using the unclean if statements.
    */
    int jump_solution2(std::vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while(end < n - 1) {
            step++; // update jump steps
            int maxend = end + 1; // 最远可以到达的index
            for(int i = start; i <= end; ++i) {
                if(i + nums[i] >= n - 1) { // 如果当前位置再往前走 nums[i]步会出去，就直接返回步数
                    return step;
                }
                maxend = std::max(maxend, i + nums[i]); //更新最远能到达的index
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }

    int jump_solution(std::vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        int i = 0;
        int cur = 0; // 
        while(cur < n - 1) {
            ++res;
            int pre = cur; // 最远能走到的位置
            for(; i <= pre; ++i) { // 从当前位置开始走，一直到最远，看最远能走多远
                cur = std::max(cur, i + nums[i]); // 下一步
            }

            if(pre == cur) {
                return -1; 
            }
        }
        return res;
    }
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