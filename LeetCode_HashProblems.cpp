#include "LeetCode_HashProblems.hpp"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
std::vector<std::vector<std::string>> LC::_0049_GroupAnagrams::groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, int> mySet;
    std::vector<std::vector<std::string>> res;
    int idx = 0;
    for(auto & s : strs) {
        std::string ss = s;
        std::sort(ss.begin(), ss.end());
        auto iter = mySet.find(ss);
        if(iter == mySet.end()) {
            mySet[ss] = idx;
            res.push_back(std::vector<std::string>());
            res[idx].push_back(s);
            idx++;
        } else {
            res[iter->second].push_back(s);
        }
    }
    return res;
}

LC::_0519_RandomFlipMatrix::_0519_RandomFlipMatrix(int n_rows, int n_cols) : nRows(n_rows), nCols(n_cols) {
    remain = n_rows * n_cols;
}

std::vector<int> LC::_0519_RandomFlipMatrix::flip() {
    int r = randInt(--remain);
    int x = occupied.count(r) ? occupied[r] : occupied[r] = r;
    occupied[r] = occupied.count(remain) ? occupied[remain] : occupied[remain] = remain;
    return {x / nCols, x % nCols};
}

void LC::_0519_RandomFlipMatrix::reset() {
    occupied.clear();
    remain = nRows * nCols;
}

LC::_0710_RandomPickWithBlacklist::_0710_RandomPickWithBlacklist(int N, std::vector<int>& blacklist) {
    n = N;
    bl = blacklist.size();
    const int blkLen = blacklist.size();
    std::sort(begin(blacklist), end(blacklist));
    std::unordered_set<int> w;
    for(int i = n - bl; i < n; ++i) {
        w.insert(i);
    }
    for(int x : blacklist) {
        w.erase(x);
    }
    auto wi = w.begin();
    for(int x : blacklist) {
        if(x < n - bl) {
            blkMap[x] = *wi++;
        }
    }
}

int LC::_0710_RandomPickWithBlacklist::pick() {
    int k = rand() % (n - bl);
    if(blkMap.find(k) != blkMap.end()) {
        return blkMap[k];
    } else {
        return k;
    }
}

int LC::_1371_FindTheLongestSubstringContainingVowelsInEvenCounts::findTheLongestSubstring(std::string s) {
    std::unordered_map<int, int> firstAppear;
    firstAppear[0] = -1;
    int variable = 0;
    int k = 0;
    int len = 0;
    for(char c : s) {
        if(c == 'a') {
            variable ^= (1<<0);
        } else if(c == 'e') {
            variable ^= (1<<1);
        } else if(c == 'i') {
            variable ^= (1<<2);
        } else if(c == 'o') {
            variable ^= (1<<3);
        } else if(c == 'u') {
            variable ^= (1<<4);
        }
        if(firstAppear.find(variable) != firstAppear.end()) {
            len = std::max(len, k - firstAppear[variable]);
        } else {
            firstAppear[variable] = k;
        }
        ++k;
    }
    return len;
}