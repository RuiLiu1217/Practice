#include "headers.hpp"
#include <cmath>

// 神逻辑：
// 一个灯泡最后是亮着的当且仅当它被开关奇数次。
// 对于第i个灯泡来说，在d次它被拉仅当他能被d整除。
// 而整除数是成对出现的！！！
// 12 --> 1:12, 2:6, 3:4
// 除非！ 这个数是个完全平方数， 那么平方因子就被合并成一个了，这样
// 编号为平方数的灯泡最后会被拉 奇数次。
// 给定一个数 n ，在之内有多少个平方数，就是答案
// --> sqrt(n)
int LeetCode::_0319_BulbSwitcher::bulbSwitch(int n) {
    return std::sqrt(n);
}