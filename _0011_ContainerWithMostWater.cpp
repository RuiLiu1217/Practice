#include "headers.hpp"

int LeetCode::_0011_ContainerWithMostWater::maxArea(std::vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int water = 0;
    while(i < j) {
        int h = std::min(height[i], height[j]);
        water = std::max(water, h * (j - i));
        while(i < j && height[i] <= h) { // Caution: the edge case it should be <= not <
            ++i;
        }
        while(i < j && height[j] <= h) {
            --j;
        }
    }
    return water;
}