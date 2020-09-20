#include "headers.hpp"
// 这道题想法也是DP，状态转移方程也想到了，问题就是实现上一下子卡住了。
// 搞得脑子就蒙了。
int LeetCode::_1105_FillingBookcaseShelves::minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width) {
    const int N = books.size();
    std::vector<int> DP(N, INT_MAX / 2);
    for(int j = 0; j < N; ++j) {
        int w = 0; // The current width occuplied by books
        int h = 0; // max height of the book.
        for(int i = j; i >= 0; --i) {

            // 如果拿到的书的宽度超过书架宽度，就不能再放书了。
            if((w += books[i][0]) > shelf_width) { 
                break;
            }
            h = std::max(h, books[i][1]); // 在当前这层的书最高的书
            DP[j] = std::min(DP[j],(i == 0 ? 0 : DP[i-1]) + h);
        }
    }
    return DP.back();
}