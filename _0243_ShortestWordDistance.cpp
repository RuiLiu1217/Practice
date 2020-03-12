#include "headers.hpp"
#include <algorithm>
#include <math.h>
int LeetCode::_0243_ShortestWordDistance::shortestDistance(std::vector<std::string>& words, std::string word1, std::String word2) {
    int iw1 = -1;
    int iw2 = -1;
    int dis = words.size();
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == word1) {
            iw1 = i;
        } else if(words[i] == word2) {
            iw2 = i;
        }
        if(iw1 != -1 && iw2 != -1) {
            dis = std::min(dis, std::abs(iw1 - iw2));
        }
    }
    return dis;
}