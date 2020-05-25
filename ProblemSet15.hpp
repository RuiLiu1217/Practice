#ifndef PROBLEM_SET15_HPP
#define PROBLEM_SET15_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1401 - 1500
namespace LeetCode {
    
    /*
    Given a string s of zeros and ones, return the maximum score after splitting the string into two 
    non-empty substrings (i.e. left substring and right substring).
    The score after splitting a string is the number of zeros in the left substring plus the number 
    of ones in the right substring.
    
    Input: s = "011101"
    Output: 5 
    Explanation: 
    
    All possible ways of splitting s into two non-empty substrings are:
    left = "0" and right = "11101", score = 1 + 4 = 5 
    left = "01" and right = "1101", score = 1 + 3 = 4 
    left = "011" and right = "101", score = 1 + 2 = 3 
    left = "0111" and right = "01", score = 1 + 1 = 2 
    left = "01110" and right = "1", score = 2 + 1 = 3
    
    Example 2:
    Input: s = "00111"
    Output: 5
    Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
    
    Input: s = "1111"
    Output: 3
    
    Constraints:
        2 <= s.length <= 500
        The string s consists of characters '0' and '1' only.
    */
    class _1422_MaximumScoreAfterSplittingAString {
        public:
            int maxScore(std::string s);
    };

    /*
    Given a binary tree where each path going from the root to any leaf form a valid sequence, 
    check if a given string is a valid sequence in such binary tree. We get the given string 
    from the concatenation of an array of integers arr and the concatenation of all values 
    of the nodes along a path results in a sequence in the given binary tree.

    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
    Output: true
    Explanation: 
    The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
    Other valid sequences are: 
    0 -> 1 -> 1 -> 0 
    0 -> 0 -> 0

    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
    Output: false 
    Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
    Output: false
    Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

    Constraints:

    1 <= arr.length <= 5000
    0 <= arr[i] <= 9
    Each node's value is between [0 - 9].
    */
    class _1430_CheckIfAStringIsAValidSequenceFromRootToLeavesPathInaBinaryTree {
        public:
            bool isValidSequence(TreeNode<int>* root, std::vector<int>& arr);
            bool isValidSequence(TreeNode<int>* root, std::vector<int>& arr, int startIdx);
    };


    /*
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from 
    cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

    Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    Output: "Sao Paulo" 
    Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist 
    of: "London" -> "New York" -> "Lima" -> "Sao Paulo".


    Input: paths = [["B","C"],["D","B"],["C","A"]]
    Output: "A"
    Explanation: All possible trips are: 
    "D" -> "B" -> "C" -> "A". 
    "B" -> "C" -> "A". 
    "C" -> "A". 
    "A". 
    Clearly the destination city is "A".

    Input: paths = [["A","Z"]]
    Output: "Z"
    

    Constraints:
        1 <= paths.length <= 100
            paths[i].length == 2
        1 <= cityAi.length, cityBi.length <= 10
            cityAi != cityBi
        All strings consist of lowercase and uppercase English letters and the space character.
    */
    class _1436_DestinationCity {
        public:
            std::string destCity(std::vector<std::vector<std::string>>& paths);
    };

    /*
    Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
    
    Input: nums = [1,0,0,1,0,1], k = 2
    Output: false
    Explanation: The second 1 and third 1 are only one apart from each other.
    
    Input: nums = [1,1,1,1,1], k = 0
    Output: true
    
    Input: nums = [0,1,0,1], k = 1
    Output: true
    
    Constraints:
        1 <= nums.length <= 10^5
        0 <= k <= nums.length
        nums[i] is 0 or 1
    */
    class _1437_CheckIf1sAreAtLeastLengthKPlacesAway {
        public:
            bool kLengthApart(std::vector<int>& nums, int k);
    };
}
#endif
