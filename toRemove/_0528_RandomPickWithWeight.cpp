#include "headers.hpp"
#include <algorithm>
LeetCode::_0528_RandomPickWithWeight::_0528_RandomPickWithWeight(std::vector<int>& w) {
    W = w;
    accumulated.resize(w.size());
    accumulated[0] = w[0];
    for(int i = 1; i < w.size(); ++i) {
        accumulated[i] = accumulated[i - 1] + w[i];
    }
    maxV = accumulated.back();
}

int LeetCode::_0528_RandomPickWithWeight::pickIndex() {
    int v = rand() % maxV;
    auto iter = std::upper_bound(accumulated.begin(), accumulated.end(), v);
    int index = iter - accumulated.begin();
    return index;
}