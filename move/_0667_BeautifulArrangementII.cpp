#include "headers.hpp"
// 从数组两头一小一大地取数字，每次把k降1直到k==1， 然后一直从小的一边取数字，
std::vector<int> LeetCode::_0667_BeautifulArrangementII::constructArray(int n, int k) {
    std::vector<int> res;
    for(int i = 1, j = n; i <= n; ) {
        if(k > 1) {
            res.push_back(k--%2?i++:j--);
        } else {
            res.push_back(i++);
        }
    }
    return res;
}
