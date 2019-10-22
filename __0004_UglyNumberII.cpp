#include "headers.hpp"

int LintCode::_0004_UglyNumberII::nthUglyNumber(int n) {

    std::vector<int> ugly{1};
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    while(ugly.size() < n) {
        const int next2 = ugly[i2] * 2;
        const int next3 = ugly[i3] * 3;
        const int next5 = ugly[i5] * 5;
        const int next = std::min(next2, std::min(next3, next5));
        if(next == next2) ++i2;   // 这种写法，当我们有多个ugly数与翻新相对应时，要同时更新多个index. 我自己的实现就是没有这样的考虑，导致程序错误
        if(next == next3) ++i3; 
        if(next == next5) ++i5;
        ugly.push_back(next);
    }
    return ugly.back();    
}