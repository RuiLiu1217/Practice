#include "headers.hpp"
#include <numeric>

std::vector<int> LeetCode::_1313_DecompressRunLengthEncodedList::decompressRLElist(std::vector<int>& nums) {
	std::vector<int> res;
	res.reserve(std::accumulate(nums.begin(), nums.end(), 0));
	for(int i = 0; i < nums.size(); i += 2) {
		int count = nums[i];
		int v = nums[i+1];
		for(int j = 0; j < count; ++j) {
			res.push_back(v);
		}
	}
	return res;
}
