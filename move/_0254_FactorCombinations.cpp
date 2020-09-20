#include "headers.hpp"

// Copy from the solution
std::vector<std::vector<int>> LeetCode::_0254_FactorCombinations::getFactors(int n) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    DFS(res, tmp, n);
    return res;
}

void LeetCode::_0254_FactorCombinations::DFS(std::vector<std::vector<int>>& res, std::vector<int>& tmp, int n) {
    int i = tmp.empty() ? 2 : tmp.back();
    for(; i <= n / i; ++i) {
        if(n % i == 0) {
            tmp.push_back(i);
            tmp.push_back(n / i);
            res.push_back(tmp);
            tmp.pop_back();
            DFS(res, tmp, n / i);
            tmp.pop_back();
        }
    }
}

// Another more clear solution, copy from website:
static void helper(int n, int start, std::vector<int> out, std::vector<std::vector<int>>& res) {
    if(n == 1) {
        if(out.size() > 1) {
            res.push_back(out);
            return;
        }
    }

    for(int i = start; i <= n; ++i) {
        if(n % i != 0) {
            continue;
        }

        out.push_back(i);
        helper(n / i, i, out, res);
        out.pop_back();
    }
}
static std::vector<std::vector<int>> getFactors_2(int n) {
    std::vector<std::vector<int>> res;
    helper(n, 2, {}, res);
    return res;
}
