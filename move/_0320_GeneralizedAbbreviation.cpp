#include "headers.hpp"
/*
Intuition
If we use 00 to represent a character that is not abbreviated 
and 11 to represent one that is. Then each abbreviation is 
mapped to an nn bit binary number and vice versa.

Algorithm
To generate all the abbreviation with non-repetition and 
non-omission, we need to follow rules. In approach #1, the 
rules are coded in the backtracking process. Here we introduce 
another way.

From the intuition section, each abbreviation has a one to one
relationship to a nn bit binary number xx. We can use these 
numbers as blueprints to build the corresponding abbreviations.

For example:
Given word = "word" and x = 0b0011
Which means 'w' and 'o' are kept, 'r' and 'd' are abbreviated. 
Therefore, the result is "wo2".

Thus, for a number xx, we just need to scan it bit by bit as 
if it is an array so that we know which character should be 
kept and which should be abbreviated.

To scan a number xx bit by bit, one could extract its last bit 
by b = x & 1 and shift xx one bit to the right, i.e. x >>= 1. 
Doing this repeatedly, one will get all the nn bits of xx from 
last bit to first bit.
*/

static std::string buildString(std::string word, int x) {
    const int n = word.size();
    std::string res;
    int k = 0;
    for(int i = 0; i < n; ++i, x >>= 1) {
        if((x & 1) == 0) {
            if(k != 0) {
                res += std::to_string(k);
                k = 0;
            }
            res += word[i];
        } else {
            ++k;
        }
    }
    if(k != 0) {
        res += std::to_string(k);
    }
    return res;
}

std::vector<std::string> LeetCode::_0320_GeneralizedAbbreviation::generalizeAbbreviations(std::string word) {
    const int N = word.size();
    std::vector<std::string> res;
    for(int i = 0; i < (1 << N); ++i) {
        res.push_back(buildString(word, i));
    }
    return res;
}

// Copy from the solution. 
std::vector<std::string> LeetCode::_0320_GeneralizedAbbreviation::generateAbbreviations(std::string word) {
    std::vector<std::string> res;
    res.push_back(word.empty() ? "" : std::to_string(word.size())); // empty string is necessary
    for(int i = 0; i < word.size(); ++i) {
        std::string left = i > 0 ? std::to_string(i) : "";
        for(auto a : generateAbbreviations(word.substr(i + 1))) { // neighbor cannot be the same, so generate substr(i+1) not substr(i)
            res.push_back(left + word.substr(i, 1) + a);
        }
    }
    return res;
}
    
std::vector<std::string> LeetCode::_0320_GeneralizedAbbreviation::generateAbbreviations_v2(std::string word) {
    std::vector<std::string> res;
    const int p2 = std::pow(2, word.size());
    for(int i = 0; i < p2; ++i) {
        std::string out = "";
        int cnt = 0;
        int t = i;
        for(int j = 0; j < word.size(); ++j) {
            if(t & 1 == 1) {
                ++cnt;
                if(j == word.size() - 1) {
                    out += std::to_string(cnt);
                }
            } else {
                if(cnt != 0) {
                    out += std::to_string(cnt);
                    cnt = 0;
                }
                out += word[j];
            }
            t >>= 1;
        }
        res.push_back(out);
    }
    return res;
}