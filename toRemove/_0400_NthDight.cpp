#include "headers.hpp"
// Copy from the solution:
// 这道题的关键就是要找出第N位所在的数字，然后可以把数字转为字符串，这样直接可以
// 访问任何一位。那么我们首先来分析自然数序列和其位数的关系，前九个数都是1位的，
// 然后10到99总共90个数字都是两位的，100到999这900个数都是三位的，那么这就很有
// 规律了，我们可以定义个变量cnt，初始化为9，然后每次循环扩大10倍，再用一个变量
// len记录当前循环区间数字的位数，另外再需要一个变量start用来记录当前循环区间的第
// 一个数字，我们n每次循环都减去len*cnt(区间总位数)，当n落到某一个确定的区间里了，
// 那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到了目标数字，然后我
// 们将目标数字start转为字符串，(n-1)%len就是所要求的目标位，最后别忘了考虑int溢出问
// 题，我们干脆把所有变量都申请为长整型的好了
int LeetCode::_0400_NthDight::findNthDigit(int n) {
    long long len = 1;
    long long start = 1;
    long long cnt = 9;
    while(n > len * cnt) {
        n -= len * cnt;
        ++len;
        cnt *= 10;
        start *= 10;
    }
    start += (n - 1) / len;
    std::string t = std::to_string(start);
    return t[(n-1) % len] - '0';
}