#include "headers.hpp"
// 需要换个思维方式：就考虑每个人去A比去B省多少钱，然后省的钱，从大到小排序，那么
// 前一半的人去A，后一半的人去B就好了。

int LeetCode::_1029_TwoCityScheduling::twoCitySchedCost(std::vector<std::vector<int>>& costs) {
    // std::sort(costs.begin(), costs.end(), [](std::vector<int> a, std::vector<int> b){
    //     return (a[1] - a[0]) > (b[1] - b[0]);
    // });
    // 实际上不需要排序，只需要找前一半的元素就好
    std::nth_element(begin(costs), begin(costs) + costs.size() / 2, end(costs), [](vector<int> &a, vector<int> &b) {
            return (a[0] - a[1] < b[0] - b[1]);
    });
    
    int v = 0;
    for(int i = 0; i < costs.size() / 2; ++i) {
        v += costs[i][0];
        v += costs[i + costs.size() / 2][1];
    }
    return v;
}
