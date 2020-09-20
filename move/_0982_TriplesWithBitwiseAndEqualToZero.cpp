#include "headers.hpp"
#include <unordered_map>

int LeetCode::_0982_TriplesWithBitwiseAndEqualToZero::countTriplets(std::vector<int>& A) {
    // 用一个unordered map 记录任何两个数 按位与得到的结果并映射到其能出现的次数
    std::unordered_map<int, int> map;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < A.size(); ++j) {
            ++map[A[i] & A[j]];
        }
    }

    int count = 0;
    for(int i = 0; i < A.size(); ++i) {
        for(auto m : map) {
            if((A[i] & m.first) == 0) { // operator priority == is larger than &, we need "()"
                count += m.second;
            }
        }
    }
    return count;
}