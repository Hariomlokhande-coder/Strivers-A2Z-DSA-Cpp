// ============================================================
// Problem 057: Insertion Sorting
//
// Question:
// Given an array of integers nums, sort it in non-decreasing order using the Insertion Sort
// algorithm.
//
// Insertion Sort builds the sorted portion one element at a time. It takes the next unsorted
// element and inserts it into its correct position within the already-sorted prefix - the same way
// you sort a hand of playing cards.
//
// Example:
//   Input:  nums = [13, 46, 24, 52, 20, 9]
//   Output: [9, 13, 20, 24, 46, 52]
//
//   Explanation (the | marks the end of the sorted prefix):
//   [13 | 46, 24, 52, 20, 9]   insert 46 -> already in place
//   [13, 46 | 24, 52, 20, 9]   insert 24 -> goes between 13 and 46
//   [13, 24, 46 | 52, 20, 9]   insert 52 -> already in place
//   [13, 24, 46, 52 | 20, 9]   insert 20 -> goes between 13 and 24
//   [13, 20, 24, 46, 52 | 9]   insert 9  -> goes to the front
//   [9, 13, 20, 24, 46, 52]
//
// Constraints:
// - 1 <= nums.size() <= 10^3
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach (Insert by Repeated Swapping):
// To place element i into the sorted prefix, keep swapping it with its left neighbour while that
// neighbour is larger. The element "bubbles down" into position.
//
// Time Complexity: O(n^2) worst case.
// Space Complexity: O(1) - sorting happens in place.

// Optimal Approach (Shift and Place):
// Save current = nums[i] once. Then shift every element greater than current one position right.
// When the gap reaches the correct spot, write current into it. The number of comparisons is
// unchanged; the number of writes falls by roughly a third.
//
// Time Complexity: O(n^2) worst and average case; O(n) best case on sorted or nearly-sorted input,
//                  because the inner while fails on its first test for every i.
// Space Complexity: O(1) - one temporary variable.

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution: Shift and Place

void insertionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        int current = nums[i];      // hold the element aside
        int j = i - 1;

        // Shift everything greater than current one place to the right.
        while (j >= 0 && nums[j] > current) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = current;      // drop it into the gap
    }
}

int main() {
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    insertionSort(nums);

    for (int value : nums) cout << value << " ";
    cout << endl;
    return 0;
}
