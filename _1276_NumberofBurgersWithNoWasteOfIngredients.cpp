#include "headers.hpp"

// 这题完全是一道数学题，解二元一次方程组
std::vector<int> LeetCode::_1276_NumberofBurgersWithNoWasteOfIngredients::numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int T = tomatoSlices;
    int C = cheeseSlices;
    if(T%2) {
        return {};
    }
    int y = 2 * C - T / 2;
    if(y < 0) {
        return {};
    }
    if (2 * T - 4 * C < 0) {
        return {};
    } else if( (2 * T - 4 * C) % 4) {
        return {};
    } else {
        int x = (2 * T - 4 * C) / 4;
        return {x, y};
    }
    
}