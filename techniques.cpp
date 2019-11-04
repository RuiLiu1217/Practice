#include <queue>
#include <functional>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <iterator>
#include <iostream>
#include <algorithm>

// // 总结一些常用C++数据结构的使用方法

// // priority queue
// void PriorityQueue() {
//     std::priority_queue<int, std::vector<int>, std::less<int>> Q1; // 构建一个大根堆
//     std::priority_queue<int, std::vector<int>, std::greater<int>> Q2; // 构建一个小根堆

//     // 对于自定义数据结构如何将其放入堆中？
//     // 例如 pair
//     auto comp = [](std::pair<int, int>& a, std::pair<int, int>& b){
//         // 自行定义 a < b
//         return a.first < b.first && a.second < b.second;
//     };
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> Q3(comp);

//     // access top element
//     Q1.top();

//     // insert element
//     Q1.push(1);

//     // remove the top element
//     Q1.pop();



// }

// // Multimap
// void MultiMap() {
//     std::multimap<int, int> Map;

//     Map.insert(std::make_pair(1,40));
//     Map.insert(std::make_pair(2,30));
//     Map.insert(std::make_pair(3,20));
//     Map.insert(std::make_pair(4,10));
//     Map.insert(std::make_pair(1,10)); // duplicate
//     Map.insert(std::make_pair(1,20)); // duplicate key 1 -> 40, 10, 20

//     std::multimap<int, int>::iterator itM;
//     for(itM = Map.begin(); itM != Map.end(); ++itM) {
//         std::cout << itM->first << "  " << itM->second <<"\n";
//     }

//     // How to get all values that key 1 maps to
//     std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> mapIt = Map.equal_range(1);
//     for(auto m = mapIt.first; m != mapIt.second; ++m) {
//         std::cout << m->second << " ";
//     }

//     // total Elements in the range
//     int count = std::distance(mapIt.first, mapIt.second);
    
// }


// // unordered_set / unordered_map
// void UnorderedSet() {
//     // 如果保存的数据不是基本类型， 如何自定义 hash
//     auto tupleHash = [](std::tuple<int,int, bool> const & tp) {
//         std::size_t h1 = std::hash<int>()(std::get<0>(tp));
//         std::size_t h2 = std::hash<int>()(std::get<1>(tp));
//         std::size_t h3 = std::hash<int>()(std::get<2>(tp));
//         return h1 ^ h2 ^ h3;
//     };
//     std::unordered_set<std::tuple<int, int, bool>, decltype(tupleHash)> mySet;

// }




// // permutation
// void Permutation() {
//     std::vector<int> v(5, 1);
//     do{
//         // 
//     } while(std::next_permutation(v.begin(), v.end()));
// }