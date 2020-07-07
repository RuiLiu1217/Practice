#include "headers.hpp"

std::vector<int> LeetCode::_0030_SubstringWithConcatenationOfAllWords::findSubstring(std::string s, std::vector<std::string>& words) {
    int n = s.size();
    if(n == 0 || words.size() == 0) {
        return {};
    }

    int len = words[0].size();
    int total = words.size();
    int cnt = total;
     
    std::vector<int> res;
    std::unordered_map<std::string, int> counts;
    for(auto& s : words) {
        ++counts[s];
    }

    for(int i = 0; i < len; ++i) {
        std::unordered_map<std::string, int> wordcnt = counts;
        cnt = total;
        for(int j = i; j + len <= n; j += len) {
            std::string cur = s.substr(j, len);
            if(wordcnt[cur]-- > 0) {
                cnt--;
            }
            if(j - total * len >= 0) {
                std::string out = s.substr(j - total * len, len); // the word out side of the current sliding window;
                if(++wordcnt[out] > 0) {
                    ++cnt;
                }
            }
            if(cnt == 0) {
                res.push_back(j - (total - 1) * len);
            }
        }
    }

    return res;
}