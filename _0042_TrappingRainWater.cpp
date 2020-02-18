#include "headers.hpp"

int LeetCode::_0042_TrappingRainWater::trap(std::vector<int>& height) {
    const int N = height.size();
    std::vector<int> l(N, 0);
    std::vector<int> r(N, 0);
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        l[i] = i == 0 ? height[i] : std::max(l[i-1], height[i]);
    }
    for(int i = N - 1; i >= 0; --i) {
        r[i] = i == N - 1 ? height[i] : std::max(r[i+1], height[i]);
    }

    for(int i = 0; i < N; ++i) {
        ans += (std::min(l[i], r[i]) - height[i]);
    }
    return ans;
}

// Two Pointer based solution
static int trap(std::vector<int>& height) {
    int res = 0, l = 0, r = height.size() - 1;
    while (l < r) {
        int mn = std::min(height[l], height[r]);
        if (mn == height[l]) {
            ++l;
            while (l < r && height[l] < mn) {
                res += mn - height[l++];
            }
        } else {
            --r;
            while (l < r && height[r] < mn) {
                res += mn - height[r--];
            }
        }
    }
    return res;
}