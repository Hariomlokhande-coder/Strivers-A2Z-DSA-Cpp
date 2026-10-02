// ============================================================
// Problem 067: Left Rotate Array by K Places
//
// Question:
// Given an array nums of n integers and an integer k, rotate the array left by k positions in
// place.
//
// Example:
//   Input:  nums = [1, 2, 3, 4, 5, 6, 7], k = 2
//   Output: [3, 4, 5, 6, 7, 1, 2]
//
//   Input:  nums = [1, 2, 3], k = 4
//   Output: [2, 3, 1]
//   Explanation: k = 4 on a 3-element array is the same as k = 1.
//
// Constraints:
// - 1 <= n <= 10^5
// - 0 <= k <= 10^9
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach (Rotate by One, k Times):
// A rotation by k is just k rotations by one, and rotation by one is already solved in Q66. Repeat
// it.
//
// Time Complexity: O(n * k).
// Space Complexity: O(1).

// Better Approach (Temporary Buffer for the First k Elements):
// A left rotation by k splits the array into two blocks and swaps them: the first k elements move
// to the end, and the remaining n - k move to the front. Copy the first k aside, shift the rest,
// then append the saved block.
//
// Time Complexity: O(n) - one pass to save k, one to shift n - k, one to restore k.
// Space Complexity: O(k) - the buffer. In the worst case k approaches n, so this is O(n).

// Optimal Approach (Reversal Algorithm):
// Three reversals perform the block swap with no extra memory at all:
// 1. Reverse the first k elements.
// 2. Reverse the remaining n - k elements.
// 3. Reverse the whole array.
//
// The two blocks end up swapped and each restored to its original internal order.
//
// Time Complexity: O(n) - the three reversals touch k, n - k and n elements, totalling 2n swaps'
//                  worth of work, which is O(n).
// Space Complexity: O(1) - only index variables.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums= {1,2,3,4,5,6,7};
    int n= nums.size();
    int k=2;//how much rotation

    if (n==0){
        return 0;
    }

    if (k<0){
        return 0;
    }

    k= k % n;

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());

    for (int i=0; i<n; i++){
        cout<< nums[i]<< " ";

    }

    return 0;

}