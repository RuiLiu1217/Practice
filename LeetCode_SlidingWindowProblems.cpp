#include "LeetCode_SlidingWindowProblems.hpp"
#include <vector>
#include <climits>
#include <string>
// Google
// HashTable + Sliding Window:
// Using a hashtable to remember the last index of every char, And keep tracking the starting
// point of a valid substring
int LC::_0003_LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(std::string s) {
    const int l = s.length(); // length of the string
    int idx[256] = {INT_MIN}; // The vector based map of all chars, it records the last index of a char
    int res = 0;
    int start = 0;
    for(int i = 0; i < l; ++i) {
        if(idx[s[i]] != INT_MIN) { // We already see that character
            start = std::max(start, idx[s[i]] + 1); // update the new start postion of substring
        }
        res = std::max(res, i - start + 1);
        idx[s[i]] = i;
    }
    return res;
}
