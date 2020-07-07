#include "headers.hpp"

int LeetCode::_1359_CountAllValidPickupAndDeliveryOptions::countOrders(int n) {
    if (n == 1) {
        return 1;
    }
    long long c = n * 2 - 1;
    return (c + 1) * c / 2 * countOrders(n - 1) % (1000000000 + 7);
}