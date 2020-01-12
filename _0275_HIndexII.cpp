#include "headers.hpp"
// 二分搜索的经典题目，难点在于如何找到返回条件和更新左右边界的条件
int LeetCode::_0275_HIndexII::hIndex(std::vector<int>& citations) {
    const int N = citations.size();
    int left = 0;
    int right = N - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(citations[mid] == N - mid) {
            return N - mid;
        } else if(citations[mid] > N - mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return N - left;
}