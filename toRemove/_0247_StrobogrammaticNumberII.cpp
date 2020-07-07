#include "headers.hpp"

std::vector<std::string> LeetCode::_0247_StrobogrammaticNumberII::findStrobogrammatic(int n) {
    if(n == 0) {
        return {};
    }
    if(n == 1) {
        return {"0", "1", "8"};
    }
    if(n == 2) {
        return {"69", "96", "88", "11"};
    }
    std::unordered_set<char> set{'0', '1', '6', '8', '9'};
    std::unordered_map<char, char> map;
    map['0'] = '0';
    map['1'] = '1';
    map['6'] = '9';
    map['8'] = '8';
    map['9'] = '6';

    int N = n / 2;
    std::vector<std::string> halfRes;
    std::string tmp;
    DFS(set, 0, N, tmp, halfRes);
    std::vector<std::string> res;

    for(int i = 0; i < halfRes.size(); ++i) {
        std::string left = halfRes[i];
        std::string right;
        for(char c : left) {
            right += map[c];
        }
        std::reverse(begin(right), end(right));
        if(n % 2) {
            res.push_back(left + "1" + right);
            res.push_back(left + "8" + right);
            res.push_back(left + "0" + right);
        } else {
            res.push_back(left + right);
        }
    }
    return res;

}

void LeetCode::_0247_StrobogrammaticNumberII::DFS(std::unordered_set<char> set, int curLen, int n, std::string tmp, std::vector<std::string>& res) {
    if(curLen == n) {
        res.push_back(tmp);
        return;
    }

    for(char c : set) {
        if(curLen == 0 && c == '0') { // number cannot start with 0
            continue;
        }
        tmp.push_back(c);
        DFS(set, curLen+1, n, tmp, res);
        tmp.pop_back();
    }
}