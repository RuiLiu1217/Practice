#include "headers.hpp"
#include <unordered_map>
// 这道题逻辑还是蛮复杂的，实在不行就背下来吧。
    
// 虽然标记成median 这道题给我的感觉还是蛮难的。
// 主要思路是看了几个答案才知道的。
// 用两个map，第一个map ： 保存 数组元素对应的个数;
// 第二个map 比较特殊，也比较难以构造：用于判断当前元素是否能够放到一个已经构建好的序列的末端;
bool LeetCode::_0659_SplitArrayIntoConsecutiveSubsequences::isPossible(std::vector<int>& nums) {
    std::unordered_map<int, int> freq; // 表示各个数都有多少个
    std::unordered_map<int, int> need; // 用于判断当前元素是否能够放到一个已经构建好的序列的末端;

    for(auto& n : nums) {
        ++freq[n];
    }

    for(auto& n : nums) {
        if(freq[n] == 0) { // 数字n已经用完了
            continue;
        }
        if(need.find(n) != need.end() && need[n] > 0) { // 这个数作为末尾
            --need[n];
            ++need[n+1]; //  n 放完之后 后面就需要接 n+1
        } else if(freq.find(n+1) != freq.end() freq[n+1] > 0 && freq.find(n+2) != freq.end() && freq[n+2] > 0) { // 当前这个数n作为数组开头
            --freq[n+1];
            --freq[n+2];
            ++need[n+3];
        } else {
            return false;
        }
        --freq[n]; 
    }
    return true;
}