#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_1200_MinimumAbsoluteDifference::minimumAbsDifference(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> res;
    int curDif = INT_MAX;
    for(int i = 1; i < arr.size(); ++i) {
        int dif = arr[i] - arr[i-1];
        if(dif < curDif) {
            curDif = dif;
            res.clear(); // 一旦遇到更小的差值，直接抛弃前面所有的结果;
            res.push_back({arr[i-1],arr[i]});
        } else if(dif == curDif) {
            res.push_back({arr[i-1],arr[i]});
        }
    }
    return res;
}