#include "headers.hpp"
#include <algorithm>

static int counts(int n, std::vector<int>& vs) {
    if (n <= 0) return 1;
    int ans = 0;
    for (int i = 0; i<n; ++i) {
        if (vs[i] % n == 0 || n%vs[i] == 0) {
            std::swap(vs[i], vs[n - 1]);
            ans += counts(n - 1, vs);
            std::swap(vs[i], vs[n - 1]);
        }
    }
    return ans;
}

int LeetCode::_0526_BeautifulArrangement::countArrangement(int N) {
    std::vector<int> vs(N, 0);
    std::generate(begin(vs), end(vs), [n=1]() mutable {return n++;});
    return counts(N, vs);
}
