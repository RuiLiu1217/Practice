#include "headers.hpp"
#include <iterator>
#include <functional>
#include <algorithm>
// 抄答案的，不过这道题还是挺无聊的
// Since all strings are limited to 10 characters, we can do two linear scans to detect/count the occurance of the smallest character.
// For longer strings, we would do a single scan, counting each of 26 chars.
// Also, for a frequency f, we increment positions [0...f - 1] in cnt.
// For longer strings, we would only increment position f - 1, and calculate a running sum in cnt in the end.
std::vector<int> LeetCode::_1170_CompareStringByFrequencyOfTheSmallestCharacter::numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
    auto f = [](std::string& s) {
        auto min_ch = *std::min_element(std::begin(s), std::end(s));
        return std::accumulate(std::begin(s), std::end(s), 0, [min_ch](int s, char ch) {
            return  s += ch == min_ch ? 1 : 0;
        });
    };

    std::vector<int> cnt(11, 0);
    std::vector<int> res;

    for(auto& w : words) {
        for(int i = f(w) - 1; i >= 0; --i) {
            ++cnt[i];
        }
    }
    for(auto& q : queries) {
        res.push_back(cnt[f(q)]);
    }
    return res;
}