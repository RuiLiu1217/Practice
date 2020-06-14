#include "headers.hpp"

int LeetCode::_0264_UglyNumberII::nthUglyNumber(int n) {
    std::vector<int> res(1,1);
    int idx2 = 0;
    int idx3 = 0;
    int idx5 = 0;
    while(res.size() < n) {
        int nextNum = std::min(res[idx5] * 5, std::min(res[idx2] * 2, res[idx3] * 3));
        if(nextNum == res[idx5] * 5) {
            idx5++;
        }
        if(nextNum == res[idx2] * 2) {
            idx2++;
        }
        if(nextNum == res[idx3] * 3) {
            idx3++;
        }
        res.push_back(nextNum);
    }
    return res.back();
}