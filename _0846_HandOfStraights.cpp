#include "headers.hpp"

bool LeetCode::_0846_HandOfStraights::isNStraightHand(std::vector<int>& hand, int W) {
    const int N = hand.size();
    if(N % W) {
        return false;
    }
    std::map<int, int> hands;
    for(int i = 0; i < hand.size(); ++i) {
        ++hands[hand[i]];
    }
    const int S = N / W;
    return isNStraightHand(hands, W, S);
}

bool LeetCode::_0846_HandOfStraights::isNStraightHand(std::map<int, int>& hand, int W, int S) {
    if(S == 0) {
        return true;
    }
    int minK = INT_MAX;
    for(auto& h : hand) {
        if(h.first < minK) {
            minK = h.first;
        }
    }
    for(int m = minK; m < W + minK; ++m) {
        if(hand.find(m) == hand.end() || hand[m] <= 0) {
            return false;
        } else {
            if(W == 1 && hand[m] != 1) {
                return false;
            }
            --hand[m];
            if(hand[m] == 0) {
                hand.erase(m);
            }
        }
    }
    return isNStraightHand(hand, W, S -1);
}