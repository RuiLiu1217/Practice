#include "headers.hpp"

std::string LeetCode::_1081_SmallestSubsequenceOfDistinctCharacters::smallestSubsequenc(std::string text) {
    std::vector<int> count(26, 0);   // record how many times each character appears
    std::vector<int> used(26, 0);    // whether this character is already used

    for(auto ch : text) {
        ++count[ch - 'a'];
    }

    std::string res;
    for(auto ch : text) {
        --count[ch - 'a'];  // The number of appearance of char "ch" in the following string will be decreased by one no matter you will use it or not;
        if(used[ch - 'a']++ > 0) { // if it is used, just continue;
            continue;
        }

        // if the last character in current result is larger than the ch and we still have back character, we will pop the last char
        while(!res.empty() && res.back() > ch && count[res.back() - 'a'] > 0) { 
            used[res.back() - 'a'] = 0;
            res.pop_back();
        }

        res.push_back(ch);
    }
    return res;
}
