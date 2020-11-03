#include "LeetCode_HashProblems.hpp"
#include "HeaderFiles.hpp"

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

// Facebook
std::vector<int> LC::_0349_IntersectionOfTwoArrays::intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set(begin(nums1),end(nums1));
    std::vector<int> res;
    for(int n : nums2) {
        if(set.count(n)) {
            res.push_back(n);
            set.erase(n);
        }
    }
    return res;
}

std::vector<int> LC::_0350_IntersectionOfTwoArraysII::intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    if(nums2.size() > nums1.size()) {
        return intersect(nums2, nums1);
    }
    
    std::unordered_map<int, int> Map;
    for(auto n : nums1) {
        ++Map[n];
    }
    std::vector<int> res;
    for(auto n : nums2) {
        if(Map[n] > 0) {
            --Map[n];
            res.push_back(n);
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

std::vector<std::string> LC::_0599_MinimumIndexSumOfTwoLists::findRestaruant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map<std::string, int> l1;
    for(int i = 0; i < list1.size(); ++i) {
        l1[list1[i]] = i;
    }
    
    std::vector<std::string> res;
    int minV = INT_MAX;
    for(int i = 0; i < list2.size(); ++i) {
        if(l1.count(list2[i])) {
            if(l1[list2[i]] + i < minV) {
                res.clear();
                minV = l1[list2[i]] + i;
                res.push_back(list2[i]);
            } else if(l1[list2[i]] + i == minV) {
                res.push_back(list2[i]);
            }
        }
    }
    return res;
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

bool LC::_1207_UniqueNumberOfOccurances::uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> valueFreq;
    std::unordered_set<int> freqPool;
    for(int& a : arr) {
        ++valueFreq[a];
    }
    for(auto& f : valueFreq) {
        if(freqPool.count(f.second)) {
            return false;
        }
        freqPool.insert(f.second);
    }
    return true;
}

int LC::_1218_LongestArithmeticSubsequenceOfGivenDifference::longestSubsequence(std::vector<int>& arr, int difference) {
    std::unordered_map<int, int> currentLen;
    for(int a : arr) {
        if(currentLen.count(a - difference)) {
            currentLen[a] = currentLen[a - difference] + 1;
        } else {
            currentLen[a] = 1;
        }
    }
    int maxL = 0;
    for(auto& c : currentLen) {
        maxL = std::max(maxL, c.second);
    }
    return maxL;
}


int LC::_1512_NumberOfGoodPairs::numIdenticalPairs(std::vector<int>& nums) {
    std::unordered_map<int, std::unordered_set<int>> map;
    for(int i = 0; i < nums.size(); ++i) {
        map[nums[i]].insert(i);
    }
    int res = 0;
    for(auto& m : map) {
        const int setSize = m.second.size();
        res += setSize * (setSize - 1) / 2;
    }
    return res;
}