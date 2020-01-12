#include "headers.hpp"

std::vector<int> LeetCode::_1299_ReplaceElementsWithGreatestElementOnRightSide::replaceElements(std::vector<int>& arr) {
    std::vector<int> res(arr.size(), -1);
    int maxV = arr.back();
    for(int i = res.size() - 2; i >= 0; --i) {
        if(arr[i] > maxV) {
            res[i] = maxV;
            maxV = arr[i];
        } else {
            res[i] = maxV;
        }
    }
    return res;
}