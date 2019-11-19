#include "headers.hpp"

bool LeetCode::_0777_SwapAdjacentInLRString::canTransform(const std::string& start, const std::string& end) {
    const int n1 = start.size();
    const int n2 = end.size();
    if(n1 != n2) {
        return false;
    }
    int c1[3] = {0};
    int c2[3] = {0};
    for(int i = 0; i < n1; ++i) {
        if(start[i] == 'X') {
            c1[0]++;
        } else if(start[i] == 'L') {
            c1[1]++;
        } else {
            c1[2]++;
        }
        
        if(end[i] == 'X') {
            c2[0]++;
        } else if(end[i] == 'L') {
            c2[1]++;
        } else {
            c2[2]++;
        }
    }
    if(c1[0] != c2[0] || c1[1] != c2[1] || c1[2] != c2[2]) {
        return false;
    }
    
    int ii = 0;
    int jj = 0;
    while(ii < n1 && jj < n2) {
        while(start[ii] == 'X') {
            ++ii;
        }
        while(end[jj] == 'X') {
            ++jj;
        }
        
        if(start[ii] != end[jj]) {
            return false;
        } else {
            if(start[ii] == 'L') {
                if(ii < jj) {
                    return false;
                }
            } else if(start[ii] == 'R') {
                if(ii > jj) {
                    return false;
                }
            }
        }
        ++ii;
        ++jj;
    }
    return true;        
}

