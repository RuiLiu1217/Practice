#include "headers.hpp"
#include <algorithm>
int LeetCode::_0875_KokoEatingBananas::minEatingSpeed(std::vector<int>& piles, int H) {
    int l = 1;
    int r = *(std::max_element(piles.begin(), piles.end()));
    while(l < r) {
        int m = l + (r - l) / 2;
        int totLen = 0;
        for(int i = 0; i < piles.size(); ++i) { 
            totLen += (piles[i] + m - 1) / m; // 这道题难点不是这个trick，而是如何想到用二分搜索，搜索对象居然是每次吃多少根香蕉。
        }
        if(totLen > H) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}