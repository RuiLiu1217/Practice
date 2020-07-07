#include "headers.hpp"
#include <numeric>

int LeetCode::_0135_Candy::candy(std::vector<int>& ratings) {
    std::vector<int> candy(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); ++i) {
        if(ratings[i] > ratings[i-1]) {
            candy[i] = candy[i-1] + 1;
        }
    }
    
    for(int i = ratings.size() - 1; i > 0; --i) {
        if(ratings[i-1] > ratings[i]) {
            candy[i-1] = std::max(candy[i - 1], candy[i] + 1);
        }
    }
    return std::accumulate(candy.begin(), candy.end(), 0);
}