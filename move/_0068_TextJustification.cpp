#include "headers.hpp"
// The solution is in chaos, should rewrite it to make it easier to understand.
std::vector<std::string> LeetCode::_0068_TextJustification::fullJustify(std::vector<std::string>& words, int L) {
   int wIdx = 0;
    std::vector<std::string> res;
    
    while(wIdx < words.size()) {
        int j = wIdx;
        int len = 0;
        while(j < words.size() && len + words[j].size() + j - wIdx <= L) {
            len += words[j++].size();
        }
        std::string out;
        int space = L - len;
        int tempSpace = space;
        int numSpaceSlots = j - wIdx - 1;
        std::vector<int> spaceNum;
        if(numSpaceSlots == 0) {
            
        } else {
            spaceNum.resize(numSpaceSlots);
            int k = 0;
            while(tempSpace) {
                ++spaceNum[k % numSpaceSlots];
                ++k;
                --tempSpace;
            }
        }
                    
        for(int k = wIdx; k < j; ++k) {
            out += words[k];
            if(j == words.size() && k < j - 1) {
                out += ' ';
            } else {
                if(numSpaceSlots != 0) {
                    if (k < j-1) {
                        while(out.size() < L && spaceNum[k-wIdx] > 0) {
                            out += ' ';
                            --spaceNum[k-wIdx];
                        }
                    }
                } else {
                    while(out.size() < L) {
                        out += ' ';
                    }
                }
            }
        }
        if(j == words.size()) {
            while(out.size() < L) {
                out += ' ';
            }
        }
        res.push_back(out);
        wIdx = j;
    }
    return res;
}