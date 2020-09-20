#include "headers.hpp"
#include <functional>

std::vector<int> LeetCode::_0360_SortTransformedArray::sortTransformedArray(std::vector<int>& nums, int a, int b, int c) {
    std::vector<int> res;
    std::function<int(int)> fun = [&](int x){ return a * x * x + b * x + c;};
    std::function<bool(int, int)> select = [&](int fi, int fj) {
        if(a > 0) {
            return fi > fj;
        } else {
            return fi < fj;
        }
    };
    int i = 0;
    int j = nums.size() - 1;
    while(i <= j) {
        int fi = fun(nums[i]);
        int fj = fun(nums[j]);
        if(select(fi,fj)) {
            res.push_back(fi);
            ++i;
        } else {
            res.push_back(fj);
            --j;
        }
    }
    if(a > 0) {   
        std::reverse(begin(res), end(res));
    }
    return res;
}