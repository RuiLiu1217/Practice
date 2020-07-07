#include "headers.hpp"

/* 完全抄答案的，这道题看上去不复杂，不过对于开头有很多0的或者结尾是0的那种就有点难想。
We can split S to two parts for two coordinates.
Then we use sub function f to find all possible strings for each coordinate.

In sub functon f(S)
    if S == "": return []
    if S == "0": return [S]
    if S == "0XXX0": return []
    if S == "0XXX": return ["0.XXX"]
    if S == "XXX0": return [S]
return [S, "X.XXX", "XX.XX", "XXX.X"...]

Then we add the product of two lists to result.

Time complexity
O(N^3) with N <= 10
*/
std::vector<std::string> f(std::string S) {
    int n = S.size();
    if(n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0')) {
        return {};
    }
    if(n > 1 && S[0] == '0') {
        return {"0." + S.substr(1)};
    }
    if(n == 1 || S[n-1] == '0') {
        return {S};
    }
    std::vector<std::string> res = {S};
    for(int i = 1; i < n; ++i) {
        res.push_back(S.substr(0, i) + '.' + S.substr(i));
    }

    return res;
}

std::vector<std::string> LeetCode::_0816_AmbiguousCoordinates::ambiguousCoordinates(std::string S) {
    int n = S.size();
    std::vector<std::string> res;
    for(int i = 1; i < n - 2; ++i) {
        std::vector<std::string> A = f(S.substr(1, i));
        std::vector<std::string> B = f(S.substr(i + 1, n - 2 - i));
        for(auto& a : A) {
            for(auto& b : B) {
                res.push_back("(" + a + ", " + b + ")");
            }
        }
    }

    return res;
}
