#include "headers.hpp"

// !! Copy from the solution
/*
这道题是之前那道Lonely Pixel I的拓展，我开始以为这次要考虑到对角线的情况，可是这次题目却完全换了一种玩法。
给了一个整数N，说对于均含有N个个黑像素的某行某列，如果该列中所有的黑像素所在的行都相同的话，该列的所有黑像
素均为孤独的像素，让我们统计所有的这样的孤独的像素的个数。那么跟之前那题类似，我们还是要统计每一行每一列的
黑像素的个数，而且由于条件二中要比较各行之间是否相等，如果一个字符一个字符的比较写起来比较麻烦，我们可以用
个trick，把每行的字符连起来，形成一个字符串，然后直接比较两个字符串是否相等会简单很多。然后我们遍历每一行
和每一列，如果某行和某列的黑像素刚好均为N，我们遍历该列的所有黑像素，如果其所在行均相等，则说明该列的所有
黑像素均为孤独的像素，将个数加入结果res中，然后将该行的黑像素统计个数清零，以免重复运算，这样我们就可以求
出所有的孤独的像素了，参见代码如下：
*/
int LeetCode::_0533_LonelyPixelII::findBlackPixel(std::vector<std::vector<char>>& picture, int N) {
    if (picture.empty() || picture[0].empty()) return 0;   
    int m = picture.size(), n = picture[0].size(), res = 0, k = 0;
    vector<int> rowCnt(m, 0), colCnt(n, 0);
    vector<string> rows(m, "");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rows[i].push_back(picture[i][j]);
            if (picture[i][j] == 'B') {
                ++rowCnt[i];
                ++colCnt[j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rowCnt[i] == N && colCnt[j] == N) {
                for (k = 0; k < m; ++k) {
                    if (picture[k][j] == 'B') {
                        if (rows[i] != rows[k]) break;
                    }
                }
                if (k == m) {
                    res += colCnt[j];
                    colCnt[j] = 0;
                }
            }
        }
    }
    return res;
}