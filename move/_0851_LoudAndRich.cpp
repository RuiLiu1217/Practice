#include "headers.hpp"

std::vector<int> LeetCode::_0851_LoudAndRich::loudAndRich(std::vector<std::vector<int>>& richer, std::vector<int>& quiet) {
    for(auto v : richer) {
        richer2[v[1]].push_back(v[0]);
    }
    res = std::vector(quiet.size(), -1);
    for(int i = 0; i < quiet.size(); ++i) {
        dfs(i, quiet);
    }
    return res;
}

int LeetCode::_0851_LoudAndRich::dfs(int i, std::vector<int>& quiet) {
    if(res[i] >= 0) {
        return res[i];
    }
    res[i] = i; // i is 'richer' but less quiet than himself
    for(int j : richer2[i]) {
        if(quiet[res[i]] > quiet[dfs(j, quiet)]) {
            res[i] = res[j];
        }
    }
    return res[i];
}