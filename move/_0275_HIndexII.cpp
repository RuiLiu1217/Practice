#include "headers.hpp"

int LeetCode::_0275_HIndexII::hIndex(std::vector<int>& citations) {
    std::reverse(begin(citations), end(citations));
    int s = 0;
    int e = citations.size();
    while(s < e) {
        int m = s + (e - s) / 2;
        if(m < citations[m]) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return s;
}