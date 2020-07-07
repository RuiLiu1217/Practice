#ifndef LEETCODE_HASHPROBLEMS_HPP
#define LEETCODE_HASHPROBLEMS_HPP

#include <string>
#include <vector>

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

}
#endif