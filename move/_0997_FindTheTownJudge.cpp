#include "headers.hpp"

int LeetCode::_0997_FindTheTownJudge::findJudge(int N, std::vector<std::vector<int>>& trust) {
    std::vector<int> inDegree(N, 0);
    std::vector<int> outDegree(N, 0);
    for(auto& t : trust) {
        ++outDegree[t[0] - 1];
        ++inDegree[t[1] - 1];
    }
    for(int i = 0; i < N; ++i) {
        if(outDegree[i] == 0 && inDegree[i] == N - 1) {
            return i+1;
        }
    }
    return -1;
}