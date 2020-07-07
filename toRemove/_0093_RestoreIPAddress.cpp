#include "headers.hpp"

std::vector<std::string> LeetCode::_0093_RestoreIPAddress::restoreIPAddress(std::string s) {
    std::vector<std::string> res;
    restoreIpAddress(s, 4, "", res);
    return res;
}

void LeetCode::_0093_RestoreIPAddress::restoreIpAddress(std::string s, int level, std::string out, std::vector<std::string>& res) {
    if(s.size() > 12) {
        return;
    }

    if(level == 0 && s.empty()) {
        res.push_back(out);
    } else {
        for(int i = 1; i <= 3; ++i) {
            if(s.size() >= i && isValid(s.substr(0, i))) {
                if(level == 1) {
                    restoreIpAddress(s.substr(i), level - 1, out + s.substr(0, i), res);
                } else {
                    restoreIpAddress(s.substr(i), level - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }

}

bool LeetCode::_0093_RestoreIPAddress::isValid(std::string s) {
    if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) { // if there are two digits, it cannot start with 0
        return false;
    }
    int v = std::atoi(s.c_str());
    return (v >= 0 && v <= 255);
}

