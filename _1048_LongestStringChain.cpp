#include "headers.hpp"
#include <algorithm>
static std::vector<std::string> loseOneChar(const std::string& w) {
    std::vector<std::string> res;
    for(int i = 0; i < w.size(); ++i) {
        std::string sub1 = w.substr(0,i);
        std::string sub2 = w.substr(i+1);
        res.push_back(sub1 + sub2);
    }
    return res;
}

int LeetCode::_1048_LongestStringChain::longestStrChain(std::vector<std::string>& words) {
    std::sort(words.begin(), words.end(), [](auto&a, auto& b){ // if by default, it is sorted in an alphabetical order.
    return a.length() < b.length();});

    const int N = words.size();
    std::vector<int> DP(N, 0);
    std::unordered_map<std::string, int> mySet;
    DP[0] = 1;
    mySet.insert({words[0], 1});
    for(int i = 1; i < N; ++i) {
        std::vector<std::string> loseOne = loseOneChar(words[i]);
        int maxC = -1;
        for(auto l : loseOne) {
            if(mySet.find(l) != mySet.end()) {
                maxC = std::max(maxC, mySet[l]);
            }
        }
        if(maxC == -1) {
            mySet[words[i]] = 1;
        } else {
            mySet[words[i]] = maxC + 1;
        }
    }
    int maxC = -1;
    for(auto m : mySet) {
        maxC = std::max(m.second, maxC);
    }
    return maxC;
    }

