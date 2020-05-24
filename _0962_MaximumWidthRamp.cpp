#include "headers.hpp"

int LeetCode::_0962_MaximumWidthRamp::maxWidthRamp(std::vector<int>& A) {
    const int N = A.size();
    std::vector<std::pair<int, int>> st; // <index, value>
    int res = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(st.empty() || st.back().second > A[i]) {
            st.push_back({i, A[i]});
        } else {
            int s = 0;
            int e = st.size();
            while(s < e) {
                int m = s + (e - s) / 2;
                if(st[m].second == A[i]) {
                    s = m;
                    break;
                } else if(st[m].second > A[i]) {
                    s = m + 1;
                } else {
                    e = m;
                }
            }
            res = std::max(res, i - st[s].first);
        }
    }
    return res;
}