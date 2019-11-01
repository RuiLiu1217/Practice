#include "headers.hpp"

std::string LeetCode::_0168_ExcelSheetColumnTitle::convertToTitle(int n) {
    return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
}