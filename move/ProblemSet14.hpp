#ifndef PROBLEM_SET14_HPP
#define PROBLEM_SET14_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1401 - 1500
namespace LeetCode {

    /*
    Given an array of string words. Return all strings in words which is 
    substring of another word in any order. 
    String words[i] is substring of words[j], if can be obtained removing 
    some characters to left and/or right side of words[j].

    Input: words = ["mass","as","hero","superhero"]
    Output: ["as","hero"]
    Explanation: "as" is substring of "mass" and "hero" is substring of 
    "superhero". ["hero","as"] is also a valid answer.

    Input: words = ["leetcode","et","code"]
    Output: ["et","code"]
    Explanation: "et", "code" are substring of "leetcode".

    Input: words = ["blue","green","bu"]
    Output: []
    
    Constraints:
        1 <= words.length <= 100
        1 <= words[i].length <= 30
        words[i] contains only lowercase English letters.
        It's guaranteed that words[i] will be unique.
    */
    class _1408_StringMatchingInAnArray {
        public:
            std::vector<std::string> stringMatching(std::vector<std::string>& words);
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
    Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

    Build the target array using the following operations:

    Push: Read a new element from the beginning list, and push it in the array.
    Pop: delete the last element of the array.
    If the target array is already built, stop reading more elements.
    You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.

    Return the operations to build the target array.

    You are guaranteed that the answer is unique.

    

    Example 1:

    Input: target = [1,3], n = 3
    Output: ["Push","Push","Pop","Push"]
    Explanation: 
    Read number 1 and automatically push in the array -> [1]
    Read number 2 and automatically push in the array then Pop it -> [1]
    Read number 3 and automatically push in the array -> [1,3]
    Example 2:

    Input: target = [1,2,3], n = 3
    Output: ["Push","Push","Push"]
    Example 3:

    Input: target = [1,2], n = 4
    Output: ["Push","Push"]
    Explanation: You only need to read the first 2 numbers and stop.
    Example 4:

    Input: target = [2,3,4], n = 4
    Output: ["Push","Pop","Push","Push","Push"]
    */
    class _1441_BuildAnArrayWithStackOperations {
        public:
            std::vector<std::string> buildArray(std::vector<int>& target, int n);
    };

}
#endif
