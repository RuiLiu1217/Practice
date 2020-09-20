#include "headers.hpp"
/*
Type: Array
*/
// 抄答案的
int LeetCode::_0121_BestTimeToBuyAndSellStock::maxProfit(std::vector<int>& prices) {
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int i = 0; i < prices.size(); ++i) {
        if(prices[i] < minprice) { // 如果当前价格比最低价低，就把当前价格设为最低价。
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) { // 否则， 用当前价格减去设定的最低价，如果比最大利润高，那么就把最大利润设为当前差价。
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}