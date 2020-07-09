#include "LeetCode_ArrayProblems.hpp"
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <functional>
#include <cmath>
std::vector<int> LC::_0001_TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); ++i)
    {
        int n = nums[i];
        if(map.find(target - n) != map.end()) {
            return {map[target - n], i};
        }
        map[n] = i;
    }
    return {};
}

// ReviewLater
// Company: Google
// Type: Array
// 一道二分搜索法的极致变形
double LC::_0004_MedianOfTwoSortedArrays::findMedianOfSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int N1 = nums1.size();
    const int N2 = nums2.size();
    if(N1 > N2) {
        return findMedianOfSortedArrays(nums2, nums1); // 总是考虑 第一个数组相对来说较短的情况
    }

    const int K = (N1 + N2 + 1) / 2; // Calculate the median index of two sorted arrays 所谓中位数所在的index
    int l = 0;
    int r = N1;

    while(l < r) {
        const int M1 = l + (r - l) / 2; // Assume that we need M1 elements from the first array // 假设需要M1个元素从nums1中，
        const int M2 = K - M1; // Then we need K - M1 elements in the second array; // 因此需要在nums2中找  K - M1 个元素

        // 如果在nums1中的第M1个数比在nums2中的M2-1个数还要小，说明我们还要从nums1中拿更多的数
        // 否则这意味着我们在nums1中拿太多的数字了，需要返回一部分。
        if(nums1[M1] < nums2[M2 - 1]) { 
            l = M1 + 1; 
        } else {
            r = M1; 
        }
    }

    const int M1 = l;
    const int M2 = K - 1;

    const int C1 = std::max(M1 <= 0 ? INT_MIN : nums1[M1-1], M2 <= 0 ? INT_MIN : nums2[M2 - 1]);

    if((N1 + N2) % 2 == 1) { // The total number of arrays is an odd number.
        return C1;
    }

    const int C2 = std::min(M1 >= N1 ? INT_MAX : nums1[M1], M2 >= N2 ? INT_MAX : nums2[M2]);
    return (C1 + C2) * 0.5;
}


/*
Google
Tag: Array Binary search
*/
std::vector<std::vector<int>> LC::_0015_3Sum::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    if(nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
        return {};
    }

    for(int k = 0; k < nums.size() - 2; ++k) {
        if(nums[k] > 0) {
            break;
        }
        if(k > 0 && nums[k] == nums[k-1]) {
            continue;
        }

        int i = k + 1;
        int j = nums.size() - 1;
        int target = -nums[k];
        while(i < j) {
            if(nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) {
                    ++i;
                }
                while(i < j && nums[j] == nums[j-1]) {
                    --j;
                }
                ++i;
                --j;
            } else if(nums[i] + nums[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
    }
    return res;
}


/*
Google
Stack
*/
bool LC::_0020_ValidParentheses::isValid(std::string& s) {
    // () 1 [] 2 {} 3
    std::stack<int> st;
    for(int i = 0 ; i!= s.size(); ++i)
    {
        if(s[i] == '(') {
            st.push(1);
        } else if(s[i] == '[') {
            st.push(2);
        } else if(s[i] == '{') {
            st.push(3);
        } else if(s[i] == ')') {
            if(!st.empty() && st.top() == 1) {
                st.pop();
            } else {
                return false;
            }
        } else if(s[i] == ']') {
            if(!st.empty() && st.top() == 2) {
                st.pop();
            } else {
                return false;
            }
        } else if(s[i] == '}') {
            if(!st.empty() && st.top() == 3) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}



int LC::_0026_RemoveDuplicatesFromSortedArray::removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int slow = 0;
    int fast = 0;
    while(fast < nums.size()) { // How to compare int with size_t, this is not safe
        if(nums[slow] == nums[fast]) {
            ++fast;
        } else {
            nums[++slow] = nums[fast++];
        }
    }
    return slow + 1;
}

int LC::_0027_RemoveElement::removeElement(std::vector<int>& nums, int val) {
    int slowIdx = 0;
    int fastIdx = 0;
    while(fastIdx != nums.size())
    {
        if(nums[fastIdx] == val)
        {
            ++fastIdx;
        } else {
            nums[slowIdx++] = nums[fastIdx++];
        }
    }
    return slowIdx;      
}


/* 
Google, Facebook
Type: Array

*/

/*
Single pass approach:
First, we observe that for any given sequence that is in descending order, 
no next larger permutation is possible. For example, no next permutation is 
possible for the following array:
            [9, 5, 4, 3, 1]
We need to find the first pair of two successive numbers a[i] and a[i-1], 
from the right, which satisfy a[i] > a[i-1]. Now, no rearrangements to the 
right of a[i−1] can create a larger permutation since that subarray consists 
of numbers in descending order. Thus, we need to rearrange the numbers to the 
right of a[i−1] including itself.
Now, what kind of rearrangement will produce the next larger number? We want 
to create the permutation just larger than the current one. Therefore, we 
need to replace the number a[i−1] with the number which is just larger than 
itself among the numbers lying to its right section, say a[j].

We swap the numbers a[i-1] and a[j]. We now have the correct number at index i−1. 
But still the current permutation isn't the permutation that we are 
looking for. We need the smallest permutation that can be formed by using the 
numbers only to the right of a[i−1]. Therefore, we need to place those numbers in 
ascending order to get their smallest permutation.

But, recall that while scanning the numbers from the right, we simply kept 
decrementing the index until we found the pair a[i] and a[i−1] where, a[i] > a[i-1]
. Thus, all numbers to the right of a[i−1] were already sorted in descending order. 
Furthermore, swapping a[i−1] and a[j] didn't change that order. Therefore, we simply 
need to reverse the numbers following a[i−1] to get the next smallest lexicographic 
permutation.

Algorithm
1. find from the last to front, if a[i] < a[i+1], stop 
2. from a[i+1] to a[N-1], find the number a[j] just a little bit larger than a[i], which means a[j+1] < a[i]
3. swap a[i], a[j]
4. from a[i+1] to a[N-1], sort them in a increasing order.
*/

void LC::_0031_NextPermutation::nextPermutation(std::vector<int>& nums) {

    // define reverse operation
    std::function<void(int start, int end)> reverse = [&](int start, int end) {
        while(start < end) {
            std::swap(nums[start++], nums[end--]);
        }
    };

    if(nums.size() == 0 || nums.size() == 1) {
        return;
    }
    int firstSmall = -1;
    for(int i = nums.size()-2; i >= 0; --i) {
        if(nums[i] < nums[i+1]) {
            firstSmall = i;
            break;
        }
    }

    if(firstSmall == -1) {
        reverse(0, nums.size() - 1);
        return;
    }

    int firstLarge = -1;
    for(int i = nums.size() - 1; i >= firstSmall; --i) {
        if(nums[i] > nums[firstSmall]) {
            firstLarge = i;
            break;
        }
    }

    std::swap(nums[firstLarge], nums[firstSmall]);
    reverse(firstSmall + 1, nums.size() - 1);
}


// Facebook
std::vector<std::vector<int>> LC::_0056_MergeIntervals::merge(std::vector<std::vector<int>>& intervals) {
    if(intervals.size() == 0) {
        return {};
    }
    std::sort(intervals.begin(), intervals.end(), [](auto a, auto b){
        return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
    });
    
    int slow = 0;
    int fast = 0;
    for(fast = 0; fast < intervals.size(); ++fast) {
        if(intervals[slow][1] >= intervals[fast][0]) {
            intervals[slow][1] = std::max(intervals[slow][1],
                                            intervals[fast][1]);
        } else {
            intervals[++slow] = intervals[fast];
        }
    }
    intervals.resize(slow+1);
    return intervals;
}



std::vector<std::vector<int>> LC::_0059_SpiralMatrixII::generateMatrix(int n)
{
    std::vector<std::vector<int>> res;
    if (n == 0) {
        return res;
    }
    res.resize(n);

    for (int i = 0; i != n; ++i) {
        res[i].resize(n);
    }
    int t = 1;
    int i = 0;
    int j = 0;
    int rowCount = n - 1;
    int colCount = n;
    int rowPowIdx = 0;
    int colPowIdx = 0;
    bool isCountingRow = false;
    int count = 0;

    for (int aa = 0; aa != n; ++aa) {
        for (int bb = 0; bb != n; ++bb) {
            res[i][j] = t++;
            if (isCountingRow) {
                i = i + std::pow(-1, rowPowIdx);
                ++count;
                if (count == rowCount) {
                    isCountingRow = false;
                    ++rowPowIdx;
                    rowCount = rowCount - 1;
                    i = i + std::pow(-1, rowPowIdx);
                    j = j + std::pow(-1, colPowIdx);
                    count = 0;
                }
            } else {
                j = j + std::pow(-1, colPowIdx);
                ++count;
                if (count == colCount) {
                    isCountingRow = true;
                    ++colPowIdx;
                    colCount = colCount - 1;
                    i = i + std::pow(-1, rowPowIdx);
                    j = j + std::pow(-1, colPowIdx);
                    count = 0;
                }
            }
        }
    }
    return res;
}


// Facebook
int LC::_0033_SearchInRotatedSortedArray::search(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[start] <= nums[mid]) { // Edge condition is very important "<=" not "<"
            if(target >= nums[start] && target < nums[mid]) { // target ">=" nums[start] not ">"
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if(target > nums[mid] && target <= nums[end]) { // target "<=" nums[end] not "<"
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
};


// Binary search
int LC::_0035_SearchInsertPosition::searchInsert(std::vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 1;
    }
    int mid = 0;
    int left = 0;
    int right = nums.size() - 1; // the last element is included
    while(left <= right) { 
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1; // every time we have to modify the right and left NOT give mid, otherwise may infinite-loop
        }
    }
    return left; // return the first one
}



bool LC::_0036_ValidSudoku::isValidSudoku(std::vector<std::vector<char>> &board) {
    std::function<bool(char, std::vector<int>&)> containDup = [](char tmp,  std::vector<int>& ext){
        if(tmp >= '1' && tmp <= '9') {
            if(ext[tmp-'1'] == 0) {
                ext[tmp - '1'] = 1;
            } else {
                return true;
            }
        }
        return false;
    };

    std::function<bool(std::vector<std::vector<char>> &, int, int)> existDuplicatePerSquare = [&containDup](std::vector<std::vector<char>> &board, int i, int j){
        std::vector<int> ext(9, 0);
        for(int ii = 0; ii != 3; ++ii) {
            for(int jj = 0; jj != 3; ++jj) {
                char tmp = board[ii+i*3][jj+j*3];
                if(containDup(tmp, ext)) {
                    return true;
                }
            }
        }
        return false;
    };

    std::function<bool(std::vector<std::vector<char>> &, int)> existDuplicatePerRow = [&containDup](std::vector<std::vector<char>> &board, int i) {
        std::vector<int> ext(9, 0);
        for(int ii = 0; ii != 9; ++ii) {
            char tmp = board[i][ii];
            if(containDup(tmp, ext)) {
                return true;
            }
        }
        return false;
    };


    std::function<bool(std::vector<std::vector<char>> &, int)> existDuplicatePerColumn = [&containDup](std::vector<std::vector<char>> &board, int j) {
        std::vector<int> ext(9, 0);
        for(int ii = 0; ii != 9; ++ii) {
            char tmp = board[ii][j];
            if(containDup(tmp, ext)) {
                return true;
            }
        }
        return false;
    };

    for(int i = 0; i != 9; ++i) {
        if(existDuplicatePerRow(board, i)) {
            return false;
        }
    }
    for(int i = 0; i != 9; ++i) {
        if (existDuplicatePerColumn(board, i)) {
            return false;
        }
    }
    for(int i = 0; i != 3; ++i) {
        for(int j = 0; j != 3; ++j) {
            if (existDuplicatePerSquare(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

void LC::_0048_RotateImage::rotate(std::vector<std::vector<int>>& matrix) {
    const size_t N = matrix.size();
    for(size_t i = 0; i < N - 1; ++i) {
        for(size_t j = i + 1; j < N; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < matrix.size(); ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}



std::string LC::_0067_AddBinary::addBinary(std::string a, std::string b) {
    std::stack<char> ast;
    std::stack<char> bst;
    std::stack<char> resst;
    for(auto& ch : a) {
        ast.push(ch);
    }
    for(auto& ch : b) {
        bst.push(ch);
    }

    int carry = 0;
    while(!ast.empty() && !bst.empty()) {
        int cha = ast.top() - '0';
        int chb = bst.top() - '0';
        ast.pop();
        bst.pop();
        int re = cha + chb + carry;
        if(re >= 2) {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));            
    }

    while(!ast.empty()) {
        int cha = ast.top() - '0';
        ast.pop();
        int re = cha + carry;
        if(re >= 2) {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));
    }

    while(!bst.empty()) {
        int chb = bst.top() - '0';
        bst.pop();
        int re = chb + carry;
        if(re >= 2) {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));
    }

    if(carry == 1) {
        resst.push('1');
    }
    
    std::string res;
    while(!resst.empty())
    {
        res = res + resst.top();
        resst.pop();
    }
    return res;
}



bool LC::_0074_SearchA2DMatrix::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const int M = matrix.size();
    if(M == 0) {
        return false;
    }
    const int N = matrix[0].size();
    if(N == 0) {
        return false;
    }
    int i = 0;
    int j = N - 1;
    while(i < M && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        } else if(matrix[i][j] > target) {
            --j;
        } else {
            ++i;
        }
    }
    return false;
}


void LC::_0075_SortColors::sortColors(std::vector<int>& nums) {
    int s1 = 0;
    int s2 = 0;
    for(auto& n : nums) {
        if(n == 0) {
            n = nums[s2];
            nums[s2] = nums[s1];
            nums[s1] = 0;
            ++s1;
            ++s2;
        } else if(n == 1) {
            n = nums[s2];
            nums[s2] = 1;
            ++s2;
        }
    }
}
