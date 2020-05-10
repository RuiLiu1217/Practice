#include "headers.hpp"
#include <algorithm>
int LeetCode::_0274_HIndex::hIndex(std::vector<int>& citations) {
    std::sort(begin(citations), end(citations), std::greater<int>());
    int s = 0;
    int e = citations.size();
    while(s < e) {
        int m = s + (e - s) / 2;
        if(citations[m] > m) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return s;
}