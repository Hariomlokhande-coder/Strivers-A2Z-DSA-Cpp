// ============================================================
// Problem 065: Remove Duplicates from Sorted Array
//
// Question:
// Given a sorted array nums, remove the duplicates in place
// so that each distinct element appears exactly once,
// keeping their relative order.
//
// Return the number of unique elements k.
// The first k positions of nums must hold the unique elements.
//
// Elements beyond position k do not matter.
//
// Example:
// Input:  nums = [1, 1, 2, 2, 3, 3, 4]
// Output: k = 4, nums begins [1, 2, 3, 4]
//
// Input:  nums = [1, 2, 3]
// Output: k = 3, nums begins [1, 2, 3]
//
// Constraints:
// - 1 <= n <= 10^5
// - -10^9 <= nums[i] <= 10^9
// - nums is sorted in non-decreasing order
// ============================================================

// Optimal Solution: Two Pointers
//
// Approach:
// Use two pointers:
// - i tracks the index of the last unique element.
// - j scans the array from left to right.
//
// If nums[j] is different from nums[i], it is a new
// distinct element.
//
// Increment i and place nums[j] at nums[i].
//
// At the end, return i + 1.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================
// 
#include <bits/stdc++.h>
using namespace std;

// Optimal Solution: Two Pointers

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}