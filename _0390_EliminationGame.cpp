#include "headers.hpp"

/*
所谓的消除游戏，是指给出一个数字n，对应1..n的序列，然后重复如下流程：
1、选择当前序列的第1，3，5，7…..的所有奇数位置的数字消除，得到新的序列
2、选择当前序列的倒数第1，3，5，7…的所有倒数的奇数位置的数字消除，得到新的序列
3、重复12 直到只剩一个为止
这道题首先可以推出一个规律：
1、无论是1还是2，若当前序列长度为k，那么下一轮一定只剩 k/2 (整除)个
然后我们来说下这个递推的式子：
1、一开始不是1,2,3,4,5,6..n 对吧？第一轮结束剩下2，4，6，8，10….2*(n/2) 
等于2*(1,2,3,4…n/2),看着这个序列，是否觉得和一开始的问题很像，对吧，但是似乎有点不一样？
2、对于下一轮而言，虽然是1,2,3,4…,n/2,但是顺序是相反的消除？那既然这样，
我们转变成n/2,…,4,3,2,1不就好了，所以我们还是按照1的方式求1，2，3，4…n/2但是对于结果要n/2 + 1 - lastremain掉不就好了？
*/
int LeetCode::_0390_EliminationGame::lastRemaining(int n) {
    return(n == 1) ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
}


static int lastRemain_Help(int n, bool left2right) {
    if(n == 1) {
        return 1;
    }
    if(left2right) {
        return 2 * lastRemain_Help(n / 2, false);
    } else {
        return 2 * lastRemain_Help(n / 2, true) - 1 + n % 2;
    }
}
static int lastRemain_v2(int n) {
    return lastRemain_Help(n, true);
}

// I have no idea about this solution
static int lastRemain_v3(int n) {
    int base = 1;
    int res = 1;
    while(base * 2 <= n) {
        res += base;
        base *= 2;
        if(base * 2 > n) {
            break;
        }
        if((n / base) % 2 == 1) {
            res += base;
        }
        base *= 2;
    }
    return res;
}