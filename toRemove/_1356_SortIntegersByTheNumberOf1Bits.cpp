#include "headers.hpp"

class Compare {
public:
    bool operator()(int a, int b) {
        int ca = numOfBits(a);
        int cb = numOfBits(b);
        return ca < cb || ((ca == cb) && (a < b));
    }
private:
    int numOfBits(int a) {
        int c = 0;
        while(a) {
            a = a & (a - 1);
            ++c;
        }
        return c;
    }
};
std::vector<int> LeetCode::_1356_SortIntegersByTheNumberOf1Bits::sortByBits(std::vector<int>& arr) {
    std::sort(begin(arr), end(arr), Compare());
    return arr;
}