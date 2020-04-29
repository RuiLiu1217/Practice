#include "headers.hpp"

/*
Google
*/
std::vector<std::string> LeetCode::_0022_GenerateParentheses::generateParenthesis(int n) {
    if(n == 0) {
        return {};
    }
    std::vector<std::string> res;
    generateParenthesis(n, n, "", res);
    return res;
}
// l means how many ( still not used yet
// r means how many ) still not used yet, so if l > r means we used too many ( that there are more ) left and some of ) cannot match, return early 趁早回头是岸
void LeetCode::_0022_GenerateParentheses::generateParenthesis(int l, int r, std::string v, std::vector<std::string>& res) {
    if(l < 0 || r < 0) {
        return;
    }
    if(l > r) {
        return;
    }
    if(l == r && l == 0) {
        res.push_back(v);
    }
    generateParenthesis(l - 1, r, v + "(", res);
    generateParenthesis(l, r - 1, v + ")", res);
}