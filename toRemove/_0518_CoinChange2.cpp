#include "headers.hpp"
#include <algorithm>


// DP[i] to denote the number of ways to sum up to amount i.
// therefore, DP[i+coin] += DP[i];
int LeetCode::_0518_CoinChange2::change(int amount, std::vector<int>& coins) {
    std::vector<int> DP(amount + 1, 0);
    DP[0] = 1;
    for(const int coin : coins) {
        for(int i = 0; i <= amount - coin; ++i) {
            DP[i+coin] += DP[i];
        }
    }
    return DP[amount];
}


// // TLE
// static int change(int amount, std::vector<int>& coins) {
//     std::sort(coins.begin(), coins.end(), std::greater<int>());
//     int tot = 0;
//     change(amount, coins, 0, tot);
//     return tot;
// }

// static void change(int amount, std::vector<int>& coins, int startIdx, int& tot) {
//     if(amount == 0) {
//         ++tot;
//         return;
//     }
//     for(int i = startIdx; i < coins.size(); ++i) {
//         if(amount >= coins[i]) {
//             change(amount - coins[i], coins, i, tot);
//         }
//     }
// }

