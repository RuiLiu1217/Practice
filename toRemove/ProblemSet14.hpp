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

    /*
    Given a sentence text (A sentence is a string of space-separated words) in the following format:

    First letter is in upper case.
    Each word in text are separated by a single space.
    Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

    Return the new text following the format shown above.


    Input: text = "Leetcode is cool"
    Output: "Is cool leetcode"
    Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
    Output is ordered by length and the new first word starts with capital letter.

    Input: text = "Keep calm and code on"
    Output: "On and keep calm code"
    Explanation: Output is ordered as follows:
    "On" 2 letters.
    "and" 3 letters.
    "keep" 4 letters in case of tie order by position in original text.
    "calm" 4 letters.
    "code" 4 letters.

    Input: text = "To be or not to be"
    Output: "To be or to be not"
    

    Constraints:

    text begins with a capital letter and then contains lowercase letters and single space between words.
    1 <= text.length <= 10^5
    */
    class _1451_RearrangeWordsInASentence {
        public:
            std::string arrangeWords(std::string text);
    };

    /*
    Given a binary string s and an integer k.
    
    Return True if all binary codes of length k is a substring of s. Otherwise, return False.
    
    Input: s = "00110110", k = 2
    Output: true
    Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
    
    Input: s = "00110", k = 2
    Output: true
    
    Input: s = "0110", k = 1
    Output: true
    Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
    
    Input: s = "0110", k = 2
    Output: false
    Explanation: The binary code "00" is of length 2 and doesn't exist in the array.
    
    Input: s = "0000000001011100", k = 4
    Output: false
    
    Constraints:
    
    1 <= s.length <= 5 * 10^5
    s consists of 0's and 1's only.
    1 <= k <= 20
     */
    class _1461_CheckIfAStringContainsAllBinaryCodesofSizeK {
        public:
            bool hasAllCodes(std::string s, int k);
    };

    /*
    Given an array of integers arr of even length n and an integer k.
    We want to divide the array into exactly n / 2 pairs such that the 
    sum of each pair is divisible by k.
    Return True If you can find a way to do that or False otherwise.

    Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
    Output: true
    Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).

    Input: arr = [1,2,3,4,5,6], k = 7
    Output: true
    Explanation: Pairs are (1,6),(2,5) and(3,4).

    Input: arr = [1,2,3,4,5,6], k = 10
    Output: false
    Explanation: You can try all possible pairs to see that there is no 
    way to divide arr into 3 pairs each with sum divisible by 10.

    Input: arr = [-10,10], k = 2
    Output: true

    Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
    Output: true
    

    Constraints:

    arr.length == n
    1 <= n <= 10^5
    n is even.
    -10^9 <= arr[i] <= 10^9
    1 <= k <= 10^5
    */
    class _1497_CheckIfArraypairsAreDivisibleByK {
    public:
        bool canArrange(std::vector<int>& arr, int k);

    };

    
}
#endif
