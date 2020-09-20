#include "headers.hpp"

bool LeetCode::_0877_StoneGame::stoneGame(std::vector<int>& piles) {
    alexMap = std::vector<std::vector<int>>(piles.size(), std::vector<int>(piles.size(), -1));
    leeMap = std::vector<std::vector<int>>(piles.size(), std::vector<int>(piles.size(), -1));
    if(piles.size() <= 2) {
        return true;
    }
    totStone.resize(piles.size() + 1);
    for(int i = 1; i < totStone.size(); ++i) {
        totStone[i] = totStone[i - 1] + piles[i-1];
    }
    int alexStone = AlexMax(piles, 0, piles.size() - 1);
    return alexStone * 2 > totStone.back();
}

int LeetCode::_0877_StoneGame::AlexMax(std::vector<int>& piles, int start, int end) {
    if(start > end) {
        return 0;
    }
    if(alexMap[start][end] != -1) {
        return alexMap[start][end];
    }
    if(start == end) {
        alexMap[start][end] = piles[start];
        return piles[start];
    }
    alexMap[start][end] = std::max(piles[start] + totStone[end+1] - totStone[start+1] - LeeMax(piles, start + 1, end),
                    piles[end] + totStone[end] - totStone[start] - LeeMax(piles, start, end - 1));
    return alexMap[start][end];
}
int LeetCode::_0877_StoneGame::LeeMax(std::vector<int>& piles, int start, int end) {
    if(start > end) {
        return 0;
    }
    if(leeMap[start][end] != -1) {
        return leeMap[start][end];
    }
        
    if(start == end) {
        leeMap[start][end] = piles[start];
        return piles[start];
    }
    
    leeMap[start][end] = std::max(piles[start] + totStone[end+1] - totStone[start+1] - AlexMax(piles, start + 1, end),
                    piles[end] + totStone[end] - totStone[start] - AlexMax(piles, start, end - 1));        
    return leeMap[start][end];
}