#include "headers.hpp"

// DP[amount] The minimun number of coins used to sum total "amount";
int LeetCode::_0322_CoinChange::coinChange_Help(
    const std::vector<int>& coins, int amout) 
{
    if(amout < 0) {
        return -1;
    }
    if(amout == 0) {
        return 0;
    }
        
    if(DP[amout] != 0) {
        return DP[amout];
    }
    int minC = INT_MAX;
    for(int coin : coins) {
        int res = coinChange_Help(coins, amout - coin);
        if(res >= 0 && res < minC) {
            minC = res + 1;
        }
    }
    DP[amout] = (minC == INT_MAX)?-1:minC;
    return DP[amout];
}

int LeetCode::_0322_CoinChange::coinChange(std::vector<int>& coins, int amount) {
    DP.resize(amount + 1, 0);
    return coinChange_Help(coins, amount);
}