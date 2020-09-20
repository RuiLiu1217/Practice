#include "headers.hpp"
#include <algorithm>

bool LeetCode::_0953_VerifyingAnAlienDictionary::isAlienSorted(std::vector<std::string>& words, std::string order) {
    int mapping[26];
    for (int i = 0; i < 26; i++)
        mapping[order[i] - 'a'] = i; // map "cab" --> "abc" which is the correct order
    for (std::string &w : words)
        for (char &c : w)
            c = mapping[c - 'a']; // map the normal words to mapped character words with map
    return std::is_sorted(words.begin(), words.end()); // alphabetically sorted
}