#include "headers.hpp"
#include <unordered_map>
#include <unordered_set>
// String
std::vector<std::string> LeetCode::_0187_RepeatedDNASequences::findRepeatedDNASequences(std::string s) {
    std::string tmp;
    for(int i = 0; i < 10; ++i) {
        tmp += s[i];
    }
    std::unordered_set<std::string> strPatt;
    std::unordered_set<std::string> res;
    strPatt.insert(tmp);
    for(int i = 10; i < s.size(); ++i) {
        tmp += s[i];
        tmp = tmp.substr(1);
        if(strPatt.count(tmp)) {
            res.insert(tmp);
        } else {
            strPatt.insert(tmp);
        }
    }
    return std::vector<std::string>(begin(res), end(res));
}

// AGCT 四个字母的ascii码的二进制表示最后三位不一样，因此每个字母只需要三个位就能区分，因此10个字母就可以表示成不长于32位的int32
// 一个字母的最后三位可以用 x[i] & 7 来提取.
std::vector<std::string> findRepeatedDNASequence(std::string s) {
    std::unordered_map<int, int> m;
    std::vector<std::string> r;
    int t = 0;
    int i = 0;
    int ss = s.size();
    if(s.size() < 10) {
        return {};
    }
    while(i < 9) {
        t = t << 3 | s[i++] & 7; // Calculate the first 10 character's map
    }
    while(i < ss) {
        if(m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1) {
            r.push_back(s.substr(i - 10, 10));
        }
        return r;
    }
}