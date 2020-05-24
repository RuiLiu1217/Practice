#include "headers.hpp"

// Copy from a solution:
/*
I guess you know how to solve max subarray sum (without circular).
If not, you can have a reference here: 53. Maximum Subarray

Explanation
So there are two case.
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.


Here is a diagram by @motorix:
image

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)


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

*/
int LeetCode::_0918_MaximumSumCircularSubarray::maxSubarraySumCircular(std::vector<int>& A) {
    int curmax = 0;
    int curmin = 0;
    int totmax = A[0];
    int totmin = A[0];
    int totV = 0;
    for(int i = 0; i < A.size(); ++i) {
        int a = A[i];
        curmax = std::max(curmax + a, a);
        totmax = std::max(curmax, totmax);
        curmin = std::min(curmin + a, a);
        totmin = std::min(curmin, totmin);
        totV += a;
    }
    return totmax > 0 ? std::max(totmax, totV - totmin) : totmax;
}