#include "headers.hpp"
#include <unordered_map>
// The problem description is not clear, actually it is just a sliding window problem that what is the longest substring that only contains at most
// two distinct characters.

int LeetCode::_0904_FruitInoBackets::totalFruit(std::vector<int>& tree) {
    std::unordered_map<int, int> map;
    int slow = 0;
    int maxLen = INT_MIN;
    for(int i = 0; i < tree.size(); ++i) {
        ++map[tree[i]];
        while(map.size() > 2) {
            --map[tree[slow]];
            if(map[tree[slow]] == 0) {
                map.erase(tree[slow]);
            }
            ++slow;
        }
        maxLen = std::max(maxLen, i - slow + 1);
    }
    return maxLen;
}