#include "headers.hpp"

int LeetCode::_0245_ShortestWordDistanceIII::shortestWordDistance(std::vector<std::string>& words, std::string word1, std::string word2) {
    int p1 = -1;
    int p2 = -1;
    int dis = INT_MAX;

    if(word1 != word2) {
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                p1 = i;
            }
            if(words[i] == word2) {
                p2 = i;
            }
            if(p1 != -1 && p2 != -1) {
                dis = std::min(std::abs(p2-p1), dis);
            }
        }
        return dis;
    } else {
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                if(p1 == -1) {
                    p1 = i;
                } else {
                    if(p2 == -1) {
                        p2 = i;
                    } else {
                        p1 = p2;
                        p2 = i;
                    }
                }
                if(p1 != -1 && p2 != -1) {
                    dis = std::min(std::abs(p2-p1), dis);
                }
            }
        }
        return dis;
    }
}