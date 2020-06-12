#include "headers.hpp"
#include <sstream>
#include <iterator>

bool LeetCode::_0290_WordPattern::wordPattern(std::string pattern, std::string str) {
    std::istringstream iss(str);

    // Split a string into a string vector 
    std::vector<std::string> strVec(std::istream_iterator<std::string>{iss}, 
                                    std::istream_iterator<std::string>());  // Learn how to make the space-separated string to string vector

    if (pattern.size() != strVec.size()) {
        return false;
    }

    for (int i = 0; i < pattern.size(); ++i) {
        if (map.find(pattern[i]) == map.end()) {
            map[pattern[i]] = strVec[i];
        } else {
            if (map[pattern[i]] != strVec[i]) {
                return false;
            }
        }

        if (map2.find(strVec[i]) == map2.end()) {
            map2[strVec[i]] = pattern[i];
        } else {
            if (map2[strVec[i]] != pattern[i]) {
                return false;
            }
        }
    }
    return true;
}