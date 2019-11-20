#include "headers.hpp"
#include <deque>
#include <vector>
#include <algorithm>
// 解题思路
// 显然，我们会想到使用dp[i]记录sum(A[:i])，那么这道题就变成了，给定一个数组dp,找到一组i,j，使得dp[j]-dp[i]>=K，且j-i尽量小！
// 数据长度达到50000，显然不能使用O(n^2)复杂度的方法，我们得想办法让i,j只走一遍
// 用一个简单的示例来分析，
//     设  A = [4,-1,2,3], K = 5, 
//   那么 dp = [0,4,3,5,8]
// 从dp数组的第2个数开始分析，（假设来了个-1，那么因为-1比0小，后面任意一个数val如若满足val-0>K,那么val+1也一定大于K，
// 且-1所在的位置i显然能获得更优解，所以0这个位置就失去了意义），现在考虑示例，来了个4，我们发现4-0小于5，我们怎么对4
// 进行处理呢，因为考虑到之后或许会出现一个足够大的数，比如9，那么4相对于0是更优的，但也有可能只来一个8，那么4就没作用了，
// 所以先暂且保留观察。等到来了一个5以上的数，我们依次对保留的数（目前是0，4）进行判断得最优解。

// 接下来来了个3，那么根据上面提到的论点，4将会被舍弃，但3比0要大，故此时0，3保留。
// 然后来了个5，5-0>=5，故找到一组i,j，记录下来，然后判断 5-3>=5 ?如若确实大于，即再次找到一组i,j，若小于，则5保留
// （考虑到之后或许来了个10），依次类推
int LeetCode::_0862_ShortestSubarrayWithSumAtLeastK::shortestSubarray(std::vector<int>& A, int K) {
    if(*std::max_element(A.begin(), A.end()) >= K) {
        return 1;
    }
    std::vector<int> DP(A.size() +1);
    DP[0] = 0;
    for(int i = 1; i < DP.size(); ++i) {
        DP[i] = DP[i-1] + A[i-1];
    }

    std::deque<int> Q;
    int res = INT_MAX;
    for(int i = 0; i < DP.size(); ++i) {
        while(!Q.empty() && DP[i] - DP[Q.front()] >= K) {
            res = std::min(res, i - Q.front());
            Q.pop_front();
        }
        while(!Q.empty() && DP[i] < DP[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    return (res == INT_MAX) ? -1 : res;
}