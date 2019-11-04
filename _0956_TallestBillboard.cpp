#include "headers.hpp"
#include <algorithm>
#include <unordered_map>
#include <numeric>
int LeetCode::_0956_TallestBillboard::tallestBillboard(std::vector<int>& rods) {
    const int n = rods.size();
    const int s = std::accumulate(rods.begin(), rods.end(), 0);

    std::vector<std::vector<int>> DP(n + 1, std::vector<int>(s + 1, -1));
    DP[0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        int h = rods[i - 1];
        for(int j = 0; j <= s - h; ++j) {
            if(DP[i - 1][j] < 0) {
                continue;
            }
            // Not use
            DP[i][j] = std::max(DP[i][j], DP[i - 1][j]);

            // Put on the taller side;
            DP[i][j+h] = std::max(DP[i][j + h], DP[i-1][j]);

            // Put on the shorter side;
            DP[i][std::abs(j-h)] = std::max(DP[i][std::abs(j-h)],
                                            DP[i-1][j] + std::min(h, j));
        }
    }
    return DP[n][0];
}


static int tallestBillboard_mapBased(std::vector<int>& rods) {
    std::unordered_map<int, int> dp; // height difference --> maximum height;
    dp[0] = 0;
    for(int h : rods) {
        auto cur = dp;
        for(const auto& kv : cur) {
            const int i = kv.first; // difference
            dp[i+h] = std::max(dp[i+h], cur[i]);
            dp[std::abs(i-h)] = std::max(dp[std::abs(i-h)], cur[i] + std::min(i, h));
        }
    }
    return dp[0];
}

static int tallestBillboard_arrayBased(std::vector<int>& rods) {
    const int s = std::accumulate(std::begin(rods), std::end(rods), 0);
    std::vector<int> DP(s+1, -1);
    DP[0] = 0;
    for(int h : rods) {
        std::vector<int> cur(DP);
        for(int i = 0; i <= s - h; ++i) {
            if(cur[i] < 0) {
                continue;
            }

            DP[i+h] = std::max(DP[i+h], cur[i]);
            DP[std::abs(i-h)] = std::max(DP[std::abs(h-i)], cur[i] + std::min(h, i));
        }
    }
    return DP[0];
}