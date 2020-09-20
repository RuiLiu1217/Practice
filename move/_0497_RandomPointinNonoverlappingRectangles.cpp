#include "headers.hpp"

// Copy from the solution, I have no idea why
std::vector<int> LeetCode::_0497_RandomPointinNonoverlappingRectangles::pick() {
    int sumArea = 0;
    std::vector<int> selected;
    for(auto r : rects) {
        int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        sumArea += area;
        
        if(rand() % sumArea < area) {
            selected = r;
        }
    }
    int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
    int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
    return {x,y};
}