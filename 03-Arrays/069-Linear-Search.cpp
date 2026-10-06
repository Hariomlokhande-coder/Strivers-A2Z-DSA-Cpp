// ============================================================
// Problem 069: Linear Search
//
// Question:
// Given an array nums of n integers and a target, return the index of the first occurrence of
// target, or -1 if it is not present.
//
// Example:
//   Input:  nums = [4, 8, 15, 16, 23, 42], target = 16
//   Output: 3
//
//   Input:  nums = [4, 8, 15], target = 99
//   Output: -1
//
// Constraints:
// - 1 <= n <= 10^5
// - -10^9 <= nums[i], target <= 10^9
// - The array is not assumed to be sorted
// ============================================================

// Approach (Linear Search):
// With no ordering to exploit, the only way to know whether a value is present is to look at the
// elements. Scan from the start and return as soon as it is found.
//
// Time Complexity: O(n) worst case, when the target is last or absent. O(1) best case when it is
//                  first, and O(n/2) on average for a present target.
// Space Complexity: O(1) - one index variable, no allocation.

// Follow-up (When the Array Is Sorted: Binary Search):
// If the array happens to be sorted, comparing with the middle element rules out half the
// remaining range in one step, giving O(log n). This is not an optimisation of the above - it is a
// different algorithm that needs a stronger precondition.
//
// Time Complexity: O(log n) - the range halves each iteration, so about log2(n) steps.
// Space Complexity: O(1) for this iterative form.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int target = 16;
    int n = 6;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}