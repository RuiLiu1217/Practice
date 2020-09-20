#include "headers.hpp"
// Recursive, string
// todo
int LeetCode::_0165_CompareVersionNumbers::compareVersion(std::string version1, std::string version2) {
    if(version1.size() == 0 && version2.size() == 0) {
        return 0;
    }

    int i1 = findDot(version1);
    std::string m1 = removeHeadingZeros(version1.substr(0, i1));
    int i2 = findDot(version2);
    std::string m2 = removeHeadingZeros(version2.substr(0, i2));

    if(m1 == m2) {
        std::string sub1;
        if(i1 == version1.size()) {
            sub1 = "";
        } else {
            sub1 = version1.substr(i1+1);
        }
        std::string sub2;
        if(i2 == version2.size()) {
            sub2 = "";
        } else {
            sub2 = version2.substr(i2+1);
        }
        return compareVersion(sub1, sub2);
    } else {
        int v1;
        if(m1 == "") {
            v1 = 0;
        } else {
            v1 = std::stoi(m1);
        }
        
        int v2;
        if(m2 == "") {
            v2 = 0;
        } else {
            v2 = std::stoi(m2);
        }
        if(v1 > v2) {
            return 1;
        } else {
            return -1;
        }
    }
}

int LeetCode::_0165_CompareVersionNumbers::findDot(const std::string& v) {
    int i = 0;
    while(i < v.size()) {
        if(v[i] == '.') {
            break;
        }
        ++i;
    }
    return i;
}

std::string LeetCode::_0165_CompareVersionNumbers::removeHeadingZeros(const std::string& v) {
    int i= 0;
    if(v.size() == 0) {
        return "";
    }
    while(v[i] == '0') {
        ++i;
    }
    return v.substr(i);
}