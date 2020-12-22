#include "LeetCode_ArrayProblems.hpp"
#include "HeaderFiles.hpp"
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
    for(auto i = nums.size()-2; i >= 0; --i) {
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
    for(auto i = nums.size() - 1; i >= firstSmall; --i) {
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


/*
Facebook
*/
void LC::_0088_MergeSortedArray::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int pos = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while(j >= 0) {
        nums1[pos--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
}


std::vector<std::vector<int>> LC::_0118_PascalTriangle::generate(int numRows) {
    if(numRows == 0) {
        return std::vector<std::vector<int>>();
    }
    std::vector<std::vector<int>> res;
    std::vector<int> a{1};
    res.push_back(a);
    if(numRows == 1) {
        return res;
    }
    std::vector<int> b{1,1};
    res.push_back(b);
    if(numRows == 2) {
        return res;
    }
    for(int i = 2; i < numRows; ++i) {
        std::vector<int> t(i+1, 0);
        t[0] = 1;
        for(int j = 1; j < t.size() - 1; ++j) {
            t[j] = res[i-1][j-1] + res[i-1][j];
        }
        t[t.size()-1] = 1;
        res.push_back(t);
    }
    return res;
}



/*
Type: Array
*/
std::vector<int> LC::_0119_PascalTriangleII::getRow(int rowIndex) {
    if(rowIndex == 0) {
        return {1};
    }
    std::vector<int> p{1,1};
    if(rowIndex == 1) {
        return p;
    }

    int rdx = 2;
    while(rdx <= rowIndex) {
        std::vector<int> c(p.size() + 1);
        c[0] = 1;
        for(int i = 1; i < p.size(); ++i) {
            c[i] = p[i-1] + p[i];
        }
        c[c.size() - 1] = 1;
        p = c;
        ++rdx;
    }
    return p;
}

int LC::_0120_Triangle::minimumTotal(std::vector<std::vector<int>>& triangle) {
    /*std::vector<std::vector<int>> DP = triangle;
    DP[0][0] = triangle[0][0];
    for(int i = 1; i < DP.size(); ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                DP[i][j] = DP[i-1][j] + triangle[i][j];
            } else if(j == i) {
                DP[i][j] = DP[i-1][j-1] + triangle[i][j];
            } else {
                DP[i][j] = std::min(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j];
            }
        }
    }
    DP.back().resize(triangle.size());
    auto it = std::min_element(DP.back().begin(), DP.back().end());
    return *it;
    */
    
    std::vector<int> DP[2];
    DP[0].resize(1);
    DP[0] = triangle[0];
    for(int i = 1; i < triangle.size(); ++i) {
        const int rowIdx = i % 2;
        const int lstIdx = (i-1) % 2;
        DP[rowIdx].resize(i + 1);
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                DP[rowIdx][j] = DP[lstIdx][j] + triangle[i][j];
            } else if(j == i) {
                DP[rowIdx][j] = DP[lstIdx][j-1] + triangle[i][j];
            } else {
                DP[rowIdx][j] = std::min(DP[lstIdx][j-1], DP[lstIdx][j]) + triangle[i][j];
            }
        }
    }
    std::vector<int>& r = DP[(triangle.size() - 1) % 2];
    auto it = std::min_element(r.begin(), r.end());
    return *it;
}


LC::_0155_MinStack::_0155_MinStack() {}
void LC::_0155_MinStack::push(int x) {
    mainStack.push(x);
    if(minStack.empty() || minStack.top() >= x) {
        minStack.push(x);
    }
}

void LC::_0155_MinStack::pop() {
    if(!mainStack.empty()) {
        int topV = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && minStack.top() == topV) {
            minStack.pop();
        }
    }
}

int LC::_0155_MinStack::top() {
    if(!mainStack.empty()) {
        return mainStack.top();
    } else {
        return -1;
    }
}

int LC::_0155_MinStack::getMin() {
    if(!minStack.empty()) {
        return minStack.top();
    } else {
        return -1;
    }
}

int LC::_0162_FindPeakElement::findPeakElement(std::vector<int>& nums) {
    if(nums.size() == 1) {
        return 0;
    } else if(nums.size() == 2) {
        if(nums[0] > nums[1]) {
            return 0;
        } else {
            return 1;
        }
    }
    int i = 1;
    for(; i < nums.size() - 1; ++i) {
        if(i == 1 && nums[i-1] > nums[i]) {
            return 0;
        }
        if(i == nums.size() - 2 && nums[i] < nums[i+1]) {
            return i+1;
        }
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
            return i;
        }
    }
    return i;
}



// There is better solution without sorting. (TODO)
int LC::_0169_MajorityElement::majorityElement(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

/*
Hash Table
Count the number of appearances for each distinct number
in nums, once we see a number appear more than n / 2 times, 
it is the majority element.
*/
int LC::_0169_MajorityElement::majorityElement_hash(std::vector<int>& nums) {
    std::unordered_map<int, int> counter;
    for (int num : nums) {
        if (++counter[num] > nums.size() / 2) {
            return num;
        }
    }
    return 0;
}

/*
Sorting
Since the majority element appears more than n / 2 times, 
the n / 2-th element in the sorted nums must be the majority 
element. In this case, a partial sort by nth_element is enough.
*/
int LC::_0169_MajorityElement::majorityElement_Nth(std::vector<int>& nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}

/*
Randomization
Pick an element randomly and check whether it is the majority one.
*/
int LC::_0169_MajorityElement::majorityElement_Random(std::vector<int>& nums) {
    int n = nums.size(), candidate, counter;
    std::srand(unsigned(std::time(NULL)));
    while (true) {
        candidate = nums[rand() % n], counter = 0;
        for (int num : nums) {
            if (num == candidate) {
                counter++;
            }
        }
        if (counter > n / 2) {
            break;
        }
    }
    return candidate;
}

/*
Divide and Conquer
Recursively find the majority in the two halves of nums and combine the results. The base case is that the majority element of a single-element array is just that element.
*/
int LC::_0169_MajorityElement::majorityElement_DivideAndConquer(std::vector<int>& nums, int l, int r) {
    if (l == r) {
        return nums[l];
    }
    int m = l + (r - l) / 2, lm = majorityElement_DivideAndConquer(nums, l, m), rm = majorityElement_DivideAndConquer(nums, m + 1, r);
    if (lm == rm) {
        return lm;
    }
    return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
}

/*
Moore Voting Algorithm
*/
int LC::_0169_MajorityElement::majorityElement_MooreVoting(std::vector<int>& nums) {
    int counter = 0, majority;
    for (int num : nums) {
        if (!counter) {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    return majority;
}

/*
Bit Manipulation
The bits in the majority are just the majority bits of all numbers.
*/
int LC::_0169_MajorityElement::majorityElement_bit(std::vector<int>& nums) {
    int majority = 0;
    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
        int bits = 0;
        for (int num : nums) {
            if (num & mask) {
                bits++;
            }
        }
        if (bits > nums.size() / 2) {
            majority |= mask;
        }
    }
    return majority;
}


void LC::_0189_RotateArray::rotate(std::vector<int>& nums, int k) {
    int numVecSize = nums.size();
    k = k % numVecSize;
    if(k != 0) {
        int i1 = 0;
        int i2 = numVecSize - k - 1;
        int i3 = numVecSize - k;
        int i4 = numVecSize - 1;
        while(i1 < i2) {
            std::swap(nums[i1],nums[i2]);
            i1++;
            i2--;
        }
        while(i3 < i4) {
            std::swap(nums[i3], nums[i4]);
            i3++;
            i4--;
        }
        i1 = 0;
        i2 = numVecSize-1;
        while(i1<i2) {
            std::swap(nums[i1], nums[i2]);
            i1++;
            i2--;
        }
    }
}

std::vector<int> LC::_0167_TwoSumII_InputArrayIsSorted::twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> res;
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum < target) {
            ++i;
        } else if(sum > target) {
            --j;
        } else {
            res.push_back(i + 1);
            res.push_back(j + 1);
            ++i;
            --j;
        }
    }
    return res;
}


// Tag: sliding window
// TODO: while < or <= and edge conditions is hard to make right
int LC::_0209_MinimumSizeSubarraySum::minSubArrayLen(int s, std::vector<int>& nums) {
    int l = 0;
    int r = 0;
    int n = nums.size();
    int sum = 0;
    int len = INT_MAX;
    while(r < n) {
        sum += nums[r++];
        while(sum >= s) {
            len = std::min(len, r - l);
            sum -= nums[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

//! This solution is copied.
// NlogN solution is harder.
// Tag: presum, binary search
// 1. sums[0] = 0
// 2. sums[i] = nums[0] + ... + nums[i-1] for  i > 0
// 对于每个 sum[i] >= s, 我们用二分搜索找到这样的 j : sums[j] > sums[i] - s (j < i), 同样 sums[j - 1] <= sums[i] - s.
// 将定义带入公式:
// nums[0] + ... + nums[j-1] > nums[0] + ... + nums[j - 1] + nums[j] + ... + nums[i-1] - s
// nums[0] + ... + nums[j-2] <= nums[0] + ... + nums[j - 2] + nums[j - 1] + ... + nums[i - 1] - s
// 这样就有：
// nums[j - 1] + ... + nums[i - 1] >= s
// nums[j] + ... + nums[i - 1] < s
// 那么 {nums[j-1], ... nums[i-1]} 就是以nums[i-1]结尾的最短的subarray，其和不小于s
// 然后我们遍历所有的 i 
// 需要注意的是，我们要在数组的开头放一个 0， 这是为了以防: nums[3] = 3, s = 3; 这样的情况
int LC::_0209_MinimumSizeSubarraySum::minSubArrayNlogN(int s, std::vector<int>& nums) {
    int n = nums.size();
    int len = INT_MAX;
    std::vector<int> sums(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        sums[i] = sums[i-1] + nums[i-1];
    }

    for(int i = n; i >= 0 && sums[i] >= s; --i) {
        int j = std::upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
        len = std::min(len, i - j + 1);
    }
    return len == INT_MAX ? 0 : len;
}


// Facebook
int LC::_0215_KthLargestElementInAnArray::findKthLargest(std::vector<int>& nums, int k) {
    std::nth_element(begin(nums), begin(nums) + k-1, end(nums), std::greater<int>());
    return nums[k-1];
}

bool LC::_0217_ContainsDuplicate::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> se;
    for(auto n : nums) {
        if(se.find(n) != se.end()) {
            return true;
        }
        se.insert(n);
    }
    return false;
}

//! TODO: easy problem but suddenly forget how to solve it.
// Sliding window based
bool LC::_0219_ContainsDuplicateII::containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> s;
    if(k <= 0) {
        return false;
    }
    if(k >= nums.size() - 1) {
        k = nums.size() - 1;
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(i > k) {
            s.erase(nums[i - k - 1]);
        }
        if(s.find(nums[i]) != s.end()) {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}



void LC::_0225_ImplementStackUsingQueues::push(int x) {
    const int len = nums.size();
    nums.push(x);
    for(int i = 0; i != len; ++i) { // keep it last in first out structure
        nums.push(nums.front());
        nums.pop();
    }
}

// Removes the element on top of the stack;
int LC::_0225_ImplementStackUsingQueues::pop() {
    const int c = nums.front();
    nums.pop();
    return c;
}

// get the top element
int LC::_0225_ImplementStackUsingQueues::top() {
    return nums.front();
}

// Return whether the stack is empty
bool LC::_0225_ImplementStackUsingQueues::empty() {
    return nums.empty();
}

std::vector<std::string> LC::_0228_SummaryRange::summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> res;
    int i = 0;
    while(i < nums.size()) {
        int endIdx = i;
        while(endIdx < nums.size() && nums[endIdx] == nums[i] + (endIdx - i)) {
            ++endIdx;
        }
        if(endIdx - i == 1) {
            res.push_back(std::to_string(nums[i]));
            ++i;
        } else {
            res.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[endIdx-1]));
            i = endIdx;
        }
    }
    return res;
}

// Tag: basic data structure
LC::_0232_ImplementQueueUsingStacks::_0232_ImplementQueueUsingStacks(){

}
void LC::_0232_ImplementQueueUsingStacks::push(int x) {
    while(!right.empty()){
        left.push(right.top());
        right.pop();
    }
    left.push(x);
}
int LC::_0232_ImplementQueueUsingStacks::pop() {
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    int a = right.top();
    
    right.pop();
    return a;
}
int LC::_0232_ImplementQueueUsingStacks::peek() {
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    return right.top();
}
bool LC::_0232_ImplementQueueUsingStacks::empty() {
    return (left.empty() && right.empty());
}


// Facebook
std::vector<int> LC::_0238_ProductOfArrayExceptSelf::productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), 1);
    for(int i = 1; i < res.size(); ++i) {
        res[i] = nums[i-1] * res[i - 1];
    }

    int t = 1;
    for(int i = nums.size() - 2; i >= 0; --i) {
        t *= nums[i+1];
        res[i] *= t;
    }
    return res;
}

int LC::_0243_ShortestWordDistance::shortestDistance(std::vector<std::string>& words, std::string word1, std::string word2) {
    int iw1 = -1;
    int iw2 = -1;
    int dis = words.size();
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == word1) {
            iw1 = i;
        } else if(words[i] == word2) {
            iw2 = i;
        }
        if(iw1 != -1 && iw2 != -1) {
            dis = std::min(dis, std::abs(iw1 - iw2));
        }
    }
    return dis;
}


int LC::_0245_ShortestWordDistanceIII::shortestWordDistance(std::vector<std::string>& words, std::string word1, std::string word2) {
    int p1 = -1;
    int p2 = -1;
    int dis = INT_MAX;

    if(word1 != word2) {
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                p1 = i;
            }
            if(words[i] == word2) {
                p2 = i;
            }
            if(p1 != -1 && p2 != -1) {
                dis = std::min(std::abs(p2-p1), dis);
            }
        }
        return dis;
    } else {
        // Special case that two words are the same
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                if(p1 == -1) {
                    p1 = i;
                } else {
                    if(p2 == -1) {
                        p2 = i;
                    } else {
                        p1 = p2;
                        p2 = i;
                    }
                }
                if(p1 != -1 && p2 != -1) {
                    dis = std::min(std::abs(p2-p1), dis);
                }
            }
        }
        return dis;
    }
}

LC::_0251_Flatten2DVector::_0251_Flatten2DVector(std::vector<std::vector<int>>& v) {
    i = v.begin();
    iEnd = v.end();
}

int LC::_0251_Flatten2DVector::next() {
    if(hasNext()) {
        return (*i)[j++];
    }
    return -1;
}

bool LC::_0251_Flatten2DVector::hasNext() {
    while(i != iEnd && j == (*i).size()) { // update next pointer in this function
        ++i;
        j = 0;
    }
    return i != iEnd;
}


void LC::_0283_MoveZeros::moveZeroes(std::vector<int>& nums) {
    int slow = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0) {
            nums[slow++] = nums[i];
        }
    }
    for(; slow < nums.size(); ++slow) {
        nums[slow] = 0;
    }
}


void LC::_0289_GameOfLife::gameOfLife(std::vector<std::vector<int>>& board) {
    const int m = board.size();
    const int n = m ? board[0].size() : 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int count = 0;
            for(int I = std::max(i-1, 0); I < std::min(i+2, m); ++I) {
                for(int J = std::max(j-1, 0); J < std::min(j+2, n); ++J) {
                    count += board[I][J] & 1;
                }
            }
            if(count == 3 || count - board[i][j] == 3) {
                board[i][j] |= 2;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            board[i][j] >>= 1;
        }
    }
}

// Prefix
LC::_0303_RangeSumQuery_Immutable::_0303_RangeSumQuery_Immutable(std::vector<int>& nums) {
    mSum.resize(nums.size() + 1, 0);
    int n = nums.size();
    if(n == 0) return;
    mSum[0] = nums[0];
    for(int i = 1; i < n; ++i) {
        mSum[i] = nums[i] + mSum[i-1];
    }
}

int LC::_0303_RangeSumQuery_Immutable::sumRange(int i, int j) {
    if(i == 0) {
        return mSum[j];
    }
    return mSum[j] - mSum[i-1];
}

// 2D Prefix
LC::_0304_RangeSumQuery2D_Immutable::_0304_RangeSumQuery2D_Immutable(std::vector<std::vector<int>>& matrix) {
    const int rowNum = matrix.size();
    if(rowNum == 0) {
        return;
    }
    const int colNum = matrix[0].size();
    if(colNum == 0) {
        return;
    }
    prefixSum.resize(rowNum+1);
    for(int i = 0; i != prefixSum.size(); ++i) {
        prefixSum[i].resize(colNum+1);
    }
    
    for(int i = 0; i != rowNum; ++i) {
        for(int j = 0; j != colNum; ++j) {
            prefixSum[i+1][j+1] = prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j] + matrix[i][j];
        }
    }   
}

int LC::_0304_RangeSumQuery2D_Immutable::sumRegion(int row1, int col1, int row2, int col2) {
     return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
}

// Copy from the solution
std::vector<std::pair<int, int>> LC::_0406_QueueReconstructionByHeight::reconstructQueue(std::vector<std::pair<int, int>>& people) {
    int n = people.size();
    if (n == 0) {
        return {};
    }
    // 从高到矮排列
    std::sort(people.begin(), people.end(), [](std::pair<int, int>& p1, std::pair<int,int>& p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);});

    //每次在头部 + n 个位置处插入当前最高的人
    std::vector<std::pair<int, int>> res;
    for (const auto& p : people) {
        res.insert(res.begin() + p.second, p);
    }
    return res;
}

std::vector<int> LC::_0347_TopKFrequentElements::topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for(int n : nums) {
        ++freq[n];
    }

    auto Comp = [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(Comp)> pq{Comp};
    for(auto& f : freq) {
        pq.push(f);
    }

    std::vector<int> res;

    for(int i = 0; i < k && !pq.empty(); ++i) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}


std::vector<int> LC::_0360_SortTransformedArray::sortTransformedArray(std::vector<int>& nums, int a, int b, int c) {
    std::vector<int> res;
    std::function<int(int)> fun = [&](int x){ return a * x * x + b * x + c;};
    std::function<bool(int, int)> select = [&](int fi, int fj) {
        if(a > 0) {
            return fi > fj;
        } else {
            return fi < fj;
        }
    };
    int i = 0;
    int j = nums.size() - 1;
    while(i <= j) {
        int fi = fun(nums[i]);
        int fj = fun(nums[j]);
        if(select(fi,fj)) {
            res.push_back(fi);
            ++i;
        } else {
            res.push_back(fj);
            --j;
        }
    }
    if(a > 0) {   
        std::reverse(begin(res), end(res));
    }
    return res;
}



int LC::_0361_BombEnemy::maxkilledEnemies(std::vector<std::vector<char>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    const int Row = grid.size();
    const int Col = grid[0].size();

    std::vector<std::vector<int>> DP(Row, std::vector<int>(Col, 0));
    int cnt = 0;
    std::function<void(int, int, int&)> update = [&](int r, int c, int& cnt){
        if(grid[r][c] == '0') {
            DP[r][c] += cnt;
        } else if(grid[r][c] == 'E') {
            ++cnt;
        } else {
            cnt = 0;
        }
    };

    for(int r = 0; r < Row; ++r) {
        cnt = 0;
        for(int c = 0; c < Col; ++c) {
            update(r,c,cnt);
        }
        
        cnt = 0;
        for(int c = Col - 1; c >= 0; --c) {
            update(r,c,cnt);
        }
    }
    
    int max = 0;
    for(int c = 0; c < Col; ++c) {
        int cnt = 0;
        for(int r = 0; r < Row; ++r) {
            update(r,c,cnt);
        }
        
        cnt = 0;
        for(int r = Row - 1; r >= 0; --r) {
            update(r,c,cnt);
            max = std::max(max, DP[r][c]);
        }
    }
    return max;
}


int LC::_0414_ThirdMaximumNumber::thirdMax(std::vector<int>& nums) {
    std::set<int> top3;
    for(int num : nums) {
        top3.insert(num);
        if(top3.size() > 3) {
            top3.erase(top3.begin());
        }
    }
    return top3.size() == 3 ? *(top3.begin()) : *(top3.rbegin());
}


 /* Consider the indices of the diagonals of a NxM matrix. Let's use a 3x4 matrix as an example: 
    (0, 0) (0, 1) (0, 2) (0, 3)
    (1, 0) (1, 1) (1, 2) (1, 3)
    (2, 0) (2, 1) (2, 2) (2, 3)
    (3, 0) (3, 1) (3, 2) (3, 3)
    
    The first diagonal is (0, 0). The second is (0, 1), (1, 0), the third is (2, 0), (1, 1), (0, 2), etc.
    
    It should be clear that the sum of row i and column j is equal to the index of the diagonal 
    (diagonal number - 1). e.g. for the second diagonal (index 1), all possible pairings of (i, j) 
    sum to 1, i.e. i + j = 1 for the 2nd diagonal. The maximum diagonal index is simply 
    ((N-1) + (M-1)) = N + M - 2
    
    So to solve the problem we simply need iterate through all possible diagonal indices (denote this 
    as s) and find all possible pairs (i, j) such that i + j = s. The only thing we need to concern 
    ourselves about is the order. We can find the ordering by looking at whether the diagonal index 
    is even or odd. When the diagonal index is even we want to the first pair to be (s, 0) and when 
    it is odd when want the first pair to be (0, s), and we decrease or increase i/j by 1 accordingly. */
std::vector<int> LC::_0498_DiagonalTraverse::findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
    if(matrix.empty()) {
        return {};
    }
    std::vector<int> res;
    const int M = matrix.size();
    const int N = matrix[0].size();
    
    for(int s = 0; s <= M + N - 2; ++s) {
        // for all i + j = s
        for(int x = 0; x <= s; ++x) {
            int i = x;
            int j = s - i;
            if(s % 2 == 0) {
                std::swap(i, j);
            }
            
            if(i >= M || j >= N) {
                continue;
            }
            
            res.push_back(matrix[i][j]);
        }
    }    
    return res;
}

int LC::_0532_KdiffPairsInAnArray::findPairs(std::vector<int>& nums, int k) {
    if (k < 0) {
        return 0;
    }
    int res = 0;
    std::unordered_map<int, int> mp;
    for (int n : nums) {
        mp[n]++;
    }

    for (auto a : mp) {
        if (k == 0 && a.second > 1) {
            res++;
        }
        if (k > 0 && mp.count(a.first + k) > 0) {
            res++;
        }
    }
    return res;
}

// Copy from solution
int LC::_0533_LonelyPixelII::findBlackPixel(std::vector<std::vector<char>>& picture, int N) {
    if(picture.empty() || picture[0].empty()) {return 0;}
    const int m = picture.size();
    const int n = picture[0].size();
    int res = 0;
    int k = 0;

    std::vector<int> rowCnt(m, 0);
    std::vector<int> colCnt(n, 0);
    std::vector<std::string> rows(m, "");
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            rows[i].push_back(picture[i][j]);
            if(picture[i][j] == 'B') {
                ++rowCnt[i];
                ++colCnt[j];
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(rowCnt[i] == N && colCnt[j] == N) {
                for(k = 0; k < m; ++k) {
                    if(picture[k][j] == 'B') {
                        if(rows[i] != rows[k]) break;
                    }
                }
                if(k == m) {
                    res += colCnt[j];
                    colCnt[j] = 0; // erase the colCount to avoid calculate multiple times
                }
            }
        }
    }
    return res;
}

// ! Copy from the solution
/* Derived from StefanPochmann's idea in "game of life": 
the board has ints in [0, 255], hence only 8-bit is used, 
we can use the middle 8-bit to store the new state 
(average value), replace the old state with the new state by shifting all values 8 bits to the right. */ 
std::vector<std::vector<int>> LC::_0661_ImageSmoother::imageSmoother(std::vector<std::vector<int>>& M) {
    const int m = M.size();
    const int n = M[0].size();
    
    std::vector<std::vector<int>> dirs = {
        {0, 1},{0, -1},{1, 0},{-1, 0},
        {-1,-1},{1,1},{-1,1},{1,-1}};
    
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            int sum = M[i][j];
            int cnt = 1;
            for(int k = 0; k < dirs.size(); ++k) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if(x < 0 || x > m - 1 || y < 0 || y > n - 1) {
                    continue;
                }
                
                sum += (M[x][y] & 0xFF);
                ++cnt;
            }
            M[i][j] |= ((sum / cnt) << 8);
        }
    }
    
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            M[i][j] >>= 8;
        }
    }
    return M;
}

std::vector<std::string> LC::_0692_TopKFrequentWords::topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> freq;
    for(auto w : words) {
        ++freq[w];
    }

    using Pair = std::pair<std::string, int>;
    auto cmp = [](Pair& a, Pair& b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);}; // a.first > b.first alphabetically sorting 
    
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq(cmp);
    for(auto f : freq) {
        pq.push(f);
    }
    std::vector<std::string> res;
    for(int i = 0; i < k; ++i) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}


std::vector<std::vector<int>> LC::_0832_FlippingAnImage::flipAndInvertImage(std::vector<std::vector<int>>& A) {
    for (auto & row : A) std::reverse(row.begin(), row.end());
    for (auto & row : A) {
        for (int & i : row) {
            i ^= 1;
        }
    }
    return A;
}


void scanningKer(std::string dominoes, int i, char sig, std::vector<int>& steps, std::stack<int>& cache) {
    if(dominoes[i] == '.') {
        cache.push(i);
    } else if(dominoes[i] == sig) {
        while(!cache.empty()) {
            steps[cache.top()] = std::abs(i - cache.top());
            cache.pop();
        }
        steps[i] = 0;
    } else {
        while(!cache.empty()) {
            steps[cache.top()] = INT_MAX;
            cache.pop();
        }
        steps[i] = INT_MAX;
    }
}

// ! Copy from the solution
std::string LC::_0838_PushDominoes::pushDominoes(std::string dominoes) {
    std::string res = "";
    dominoes = "L" + dominoes + "R";
    for(int i = 0, j = 1; j < dominoes.size(); ++j) {
        if(dominoes[j] == '.') {
            continue;
        }
        int mid = j - i - 1;
        if(i > 0) {
            res += dominoes[i];
        }
        if(dominoes[i] == dominoes[j]) {
            res += std::string(mid, dominoes[i]);
        } else if(dominoes[i] == 'L' && dominoes[j] == 'R') {
            res += std::string(mid, '.');
        } else {
            res += std::string(mid / 2, 'R') + std::string(mid % 2, '.') + std::string(mid / 2, 'L');
        }
        i = j;
    }
    return res;
}


std::vector<std::vector<int>> LC::_0830_PositionsOfLargeGroups::largeGroupPositions(std::string s) {
    int startIdx = 0;
    int count = 0;
    std::vector<std::vector<int>> res;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == s[startIdx]) {
            ++count;
        } else {
            if(count >= 3) {
                res.push_back({startIdx, i-1});
            }
            startIdx = i;
            count = 1;
        }
    }
    if(count >= 3) {
        res.push_back({startIdx, static_cast<int>(s.size()) - 1});
    }
    return res;
}


int LC::_0852_PeakIndexInAMountainArray::peakIndexInMountainArray(std::vector<int>& A) {
    int i = -1;
    for(i = 0; i < A.size() - 2; ++i) {
        if(A[i+1] < A[i] && A[i] > A[i-1]) {
            return i;
        }
    }
    return i;
}


int LC::_0861_ScoreAfterFlippingMatrix::matrixScore(std::vector<std::vector<int>>& A) {
    int powIdx = A[0].size();
    int totRowNum = A.size();
    std::function<void()> flipRow = [&]() {
        for(int i = 0; i < A.size(); ++i) {
            if(A[i][0] == 0) {
                for(int j = 0; j < A[i].size(); ++j) {
                    A[i][j] = A[i][j] ^ 1;
                }
            }
        }
    };

    flipRow();
    int sum = std::pow(2, powIdx) * totRowNum;
    for(int j = 1; j < A[0].size(); ++j) {
        --powIdx;
        int num0 = 0;
        int num1 = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i][j] == 0) {
                ++num0;
            } else {
                ++num1;
            }
        }
        if(num0 > num1) {
            sum += pow(2, powIdx) * num0;
        } else {
            sum += pow(2, powIdx) * num1;
        }
    }
    return sum>>1;
}

int LC::_0874_WalkingRobotSimulation::robotSim(std::vector<int>& commands,std::vector<std::vector<int>>& obstacles) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;

    std::set<std::pair<int, int>> obstacleSet;
    for (std::vector<int> obstacle: obstacles) {
        obstacleSet.insert(std::make_pair(obstacle[0], obstacle[1]));
    }

    int ans = 0;
    for (int cmd: commands) {
        if (cmd == -2)
            di = (di + 3) % 4;
        else if (cmd == -1)
            di = (di + 1) % 4;
        else {
            for (int k = 0; k < cmd; ++k) {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (obstacleSet.find(std::make_pair(nx, ny)) == obstacleSet.end()) {
                    x = nx;
                    y = ny;
                    ans = std::max(ans, x*x + y*y);
                }
            }
        }
    }
    return ans;
}

int LC::_0881_BoatsToSavePeople::numResculeBoats(std::vector<int>& people, int limit) {
    std::sort(begin(people), end(people));
    int l = 0;
    int r = people.size() - 1;
    int count = 0;
    while(l < r) {
        if(people[l] + people[r] <= limit) {
            ++l;
        }
        ++count;
        --r;
    }
    if(l == r) {
        ++count;
    }
    return count;
}

int LC::_0883_ProjectionAreaOf3DShapes::projectionArea(std::vector<std::vector<int>>& grid) {
    std::vector<int> rowHeight(grid.size(), 0);
    std::vector<int> colHeight(grid[0].size(), 0);
    int count = 0;
    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[r].size(); ++c) {
            if(grid[r][c] != 0) {
                ++count;
            }
            if (grid[r][c] > rowHeight[r]) {
                rowHeight[r] = grid[r][c];
            }
            if (grid[r][c] > colHeight[c]) {
                colHeight[c] = grid[r][c];
            }
        }
    }
    return std::accumulate(begin(rowHeight), end(rowHeight), 0) + 
        std::accumulate(begin(colHeight), end(colHeight), 0)  + count;
}


/*
! Copy from a solution:
I guess you know how to solve max subarray sum (without circular).
If not, you can have a reference here: 53. Maximum Subarray

Explanation
So there are two case.
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case 2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
! The maximum result equals to the total sum minus the minimum subarray sum.
! -> max(the max subarray sum, the total sum - the min subarray sum)

Prove of the second case
max(prefix+suffix)
= max(total sum - subarray)
= total sum + max(-subarray)
= total sum - min(subarray)

Corner case
Just one to pay attention:
If all numbers are negative, maxSum = max(A) and minSum = sum(A).
In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
So we return the maxSum to handle this corner case.

Complexity
One pass, time O(N)
No extra space, space O(1)
! 很难想的一道题目
*/
int LC::_0918_MaximumSumCircularSubarray::maxSubarraySumCircular(std::vector<int>& A) {
    int curmax = 0;
    int curmin = 0;
    int totmax = A[0];
    int totmin = A[0];
    int totV = 0;
    for(int a : A) {
        curmax = std::max(curmax + a, a); // Refer to problem 53
        totmax = std::max(curmax, totmax);
        curmin = std::min(curmin + a, a);
        totmin = std::min(curmin, totmin);
        totV += a;
    }
    return totmax > 0 ? std::max(totmax, totV - totmin) : totmax;
}


LC::_0933_NumberOfRecentCalls::_0933_NumberOfRecentCalls() {
}

int LC::_0933_NumberOfRecentCalls::ping(int t) {
    while(!q.empty() && t - q.front() > 3000) {
        q.pop();
    }
    q.push(t);
    return q.size();
}


bool LC::_0946_ValidateStackSequences::_0946_ValidateStackSequences::validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
    const int N = popped.size();
    std::stack<int> st;
    int j = 0;
    for(int x : pushed) { // PUSH ELEMENTS IN
        st.push(x);
        while(!st.empty() && j < N && st.top() == popped[j]) { // If the top and the popped are the same, pop it.
            st.pop();
            ++j;
        }
    }
    return j == N; // Finally the popped and the total elment number are the same.
}


int LC::_1582_SpecialPositionsInABinaryMatrix::numSpecial(std::vector<std::vector<int>>& mat) {
    if(mat.empty() || mat[0].empty()) {
        return 0;
    }
    int res = 0;
    const int M = mat.size();
    const int N = mat[0].size();
    std::vector<int> rowCnt(M, 0);
    std::vector<int> colCnt(N, 0);
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(mat[i][j]) {
                ++rowCnt[i];
                ++colCnt[j];
            }
        }
    }
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(mat[i][j] == 1 && rowCnt[i] == 1 && colCnt[j] == 1) {
                ++res;
            }
        }
    }
    return res;
}

int LC::_1144_DecreaseElementsToMakeArrayZigzag::movesToMakeZigzag(std::vector<int>& nums) {
    int count[2] = {0, 0};
    int lower, higher, n = nums.size();
    std::function<int(const std::vector<int>&, int, int)> get = [](const std::vector<int>& nums, int a, int n) {
        if(a < 0 || a >= n) {
            return INT_MAX;
        }
        return nums[a];
    };
    
    for(int i = 0; i < n; ++i) {
        lower = get(nums, i-1, n);
        higher = get(nums, i+1, n);
        lower = std::min(lower, higher);
        if(lower <= nums[i]) {
            count[i%2] += nums[i] - lower + 1;
        }
    }
    return std::min(count[0], count[1]);
}

std::vector<std::vector<int>> LC::_1282_GroupThePeopleGivenTheGroupSizeTheyBelongTo::groupThePeople(std::vector<int>& groupSizes) {
    std::unordered_map<int, std::unordered_set<int>> map; // map from size to index;
    for(int i = 0; i < groupSizes.size(); ++i) {
        map[groupSizes[i]].insert(i);
    }
    std::vector<std::vector<int>> res;
    std::vector<int> group;
    for(auto& g : map) {
        int groupSize = g.first;
        int count = 0;
        for(auto idx : g.second) {
            group.push_back(idx);
            ++count;
            if(count == groupSize) {
                res.push_back(group);
                group.clear();
                count = 0;
            }
        }
    }
    return res;    
}

int LC::_1283_FindTheSmallestDivisorGivenAThreshold::smallestDivisor(std::vector<int>& nums, int threshold) {
     int sum = *std::max_element(nums.begin(), nums.end());        
    int left = 1;
    int right = sum;
    while(left < right) {
        int mid = left + (right - left) / 2;
        int res = std::accumulate(nums.begin(), nums.end(), 0, [&](int a, int b){
            return a + b / mid + ((b % mid) ? 1 : 0);
        });
        if(res > threshold) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int LC::_1295_FindNumbersWithEvenNumberOfDigits::findNumber(std::vector<int>& nums) {
    std::function<bool(int)>  isEvenNumberOfDigits = [](int num) {
        int count = 0;
        while(num) {
            ++count;
            num /= 10;
        }
        return count % 2 == 0;
    };

    int count = 0;
    for(auto n : nums) {
        if(isEvenNumberOfDigits(n)) {
            ++count;
        }
    }
    return count;
}

std::vector<int> LC::_1299_ReplaceElementsWithGreatestElementOnRightSide::replaceElements(std::vector<int>& arr) {
    std::vector<int> res(arr.size(), -1);
    int maxV = arr.back();
    for(int i = res.size() - 2; i >= 0; --i) {
        res[i] = maxV;
        if(arr[i] > maxV) {
            maxV = arr[i];
        }
    }
    return res;
}

std::vector<int> LC::_1313_DecompressRunLengthEncodedList::decompressRLElist(std::vector<int>& nums) {
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


bool LC::_1437_CheckIf1sAreAtLeastLengthKPlacesAway::kLengthApart(std::vector<int>& nums, int k) {
    int curIdx = 0;
    int distance = k + 1; // how to start at the beginning is the key of this code
    while(curIdx < nums.size()) {
        if(nums[curIdx] == 1) {
            if(distance < k) {
                return false;
            } else {
                distance = 0;
            }
        } else {
            ++distance;
        }
        ++curIdx;
    }
    return true;
}


bool LC::_1497_CheckIfArraypairsAreDivisibleByK::canArrange(std::vector<int>& arr, int k) {
    std::vector<int> mods(k, 0);
    for(int x : arr) {
        ++mods[(x % k + k) % k];
    }
    for(int i = 1; i < k; ++i) {
        if(mods[i] != mods[k - i]) {
            return false;
        }
    }
    return mods[0] % 2 == 0;
}


std::vector<std::vector<int>> LC::_1222_QueensThatCanAttackTheKing::queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) {
    int dis[8] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    std::vector<std::vector<int>> temp(8);
    for(auto& queen : queens) {
        const int disX = std::abs(queen[0] - king[0]);
        const int disY = std::abs(queen[1] - king[1]);
        const int d = disX + disY;
        if(queen[1] == king[1] && queen[0] > king[0]) {
            if(d < dis[0]) {
                dis[0] = d;
                temp[0] = queen;
            }
        } else if(queen[1] > king[1] && queen[0] > king[0] && (disX == disY)) {
            if(d < dis[1]) {
                dis[1] = d;
                temp[1] = queen;
            }
        } else if(queen[0] == king[0] && queen[1] > king[1]) {
            if(d < dis[2]) {
                dis[2] = d;
                temp[2] = queen;
            }
        } else if(queen[1] > king[1] && queen[0] < king[0] && (disX == disY)) {
            if(d < dis[3]) {
                dis[3] = d;
                temp[3] = queen;
            }
        } else if(queen[0] < king[0] && queen[1] == king[1]) {
            if(d < dis[4]) {
                dis[4] = d;
                temp[4] = queen;
            }
        } else if(queen[0] < king[0] && queen[1] < king[1] && (disX == disY)) {
            if(d < dis[5]) {
                dis[5] = d;
                temp[5] = queen;
            }
        } else if(queen[0] == king[0] && queen[1] < king[1]) {
            if(d < dis[6]) {
                dis[6] = d;
                temp[6] = queen;
            }
        } else if(queen[0] > king[0] && queen[1] < king[1] && (disX == disY)) {
            if(d < dis[7]) {
                dis[7] = d;
                temp[7] = queen;
            }
        }
    }
    std::vector<std::vector<int>> res;
    for(int i = 0; i < 8; ++i) {
        if(dis[i] != INT_MAX) {
            res.push_back(temp[i]);
        }
    }
    return res;
}