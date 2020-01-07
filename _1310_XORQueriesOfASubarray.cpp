#include "headers.hpp"

std::vector<int> LeetCode::_1310_XORQueriesOfASubarray::xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
    std::vector<int> preXOR(arr.size(), 0);
    preXOR[0] = arr[0];
    for(int i = 1; i < preXOR.size(); ++i) {
        preXOR[i] = preXOR[i-1] ^ arr[i];
    }
    
    std::vector<int> res(queries.size(), 0);
    for(int i = 0; i < queries.size(); ++i) {
        if(queries[i][0] == 0) {
            res[i] = preXOR[queries[i][1]];
        } else {
            res[i] = preXOR[queries[i][0]-1] ^ preXOR[queries[i][1]];
        }
    }
    return res;
}