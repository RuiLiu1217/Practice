#ifndef LEETCODE_BACKTRACINGPROBLEMS_HPP
#define LEETCODE_BACKTRACINGPROBLEMS_HPP
#include <vector>
#include <string>

namespace LC {
    /*
        Tag: backtracing
    Given a string containing digits from 2-9 inclusive, return all possible 
    letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is 
    given below. Note that 1 does not map to any letters.

    Example:
    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note:
    Although the above answer is in lexicographical order, your answer could 
    be in any order you want.
    */
class _0017_LetterCombinationsOfAPhoneNumber {
public:
    std::vector<std::string> letterCombinations(std::string &digits);
private:
    void letterCombination(const std::string &digits, int i, int N, std::string tmp, std::vector<std::string> &res);
};

}


#endif