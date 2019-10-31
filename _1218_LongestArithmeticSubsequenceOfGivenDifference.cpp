#include "headers.hpp"
#include <unordered_map>
#include <algorithm>

// DP based, which is very common, but will exceed time limit.
static int longestSubsequence_etl(std::vector<int>& arr, int difference) {
    std::vector<int> DP(arr.size(), 0);
    DP[0] = 1;
    for(int i = 1; i < arr.size(); ++i) {
        int cur = arr[i];
        int len = 0;
        for(int j = i - 1; j >= 0; --j) {
            if(cur - arr[j] == difference) {
                len = std::max(len, DP[j] + 1);
            }
        }
        if(len == 0) {
            DP[i] = 1;
        } else {
            DP[i] = len;
        }
    }
    return *std::max_element(DP.begin(), DP.end());
}

// 我们能够想到的办法就是使用hashmap
// 映射关系：当前这个数 --> 组成的最长子序列长度;
// 使用 hashmap 从后向前 扫描 
static int longestSubsequence_map(std::vector<int>& arr, int difference) {
    std::unordered_map<int, int> Map;
    int res = 0;
    for(int i = arr.size() - 1; i >= 0; --i) {
        Map[arr[i]] = 1 + Map[arr[i] + difference];
        res = std::max(res, Map[arr[i]]);
    }
    return res;
}

static int longestSubsequence_mapvec(std::vector<int>& arr, int difference) {
    std::vector<int> Map(40000 + 1, 0);
    int res = 0;
    for(int i = arr.size() - 1; i >= 0; --i) {
        Map[arr[i] + 20000] = 1 + Map[arr[i] + 20000 + difference];
        res = std::max(res, Map[arr[i] + 20000]);
    }
    return res;
}

int LeetCode::_1218_LongestArithmeticSubsequenceOfGivenDifference::longestSubsequence(std::vector<int>& arr, int difference) {
    int a = longestSubsequence_etl(arr, difference);
    int b = longestSubsequence_map(arr, difference);
    int c = longestSubsequence_mapvec(arr, difference);
    return b;
}


