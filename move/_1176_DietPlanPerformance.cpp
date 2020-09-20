#include "headers.hpp"

int LeetCode::_1176_DietPlanPerformance::dietPlanPerformance(std::vector<int>& calories, int k, int lower, int upper) {
    int i = 0;
    int sum = 0;
    for(i = 0; i < k - 1 && i < calories.size(); ++i) {
        sum += calories[i];
    }
    int res = 0;
    for(i; i < calories.size(); ++i) {
        sum += calories[i];
        if(sum > upper) {
            ++res;
        } else if(sum < lower) {
            --res;
        }
        sum -= calories[i - (k - 1)];
    }
    return res;
}