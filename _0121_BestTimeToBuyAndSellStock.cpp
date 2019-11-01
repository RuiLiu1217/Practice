#include "headers.hpp"
// 抄答案的
int LeetCode::_0121_BestTimeToBuyAndSellStock::maxProfit(std::vector<int>& prices) {
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int i = 0; i < prices.size(); ++i) {
        if(prices[i] < minprice) {
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}