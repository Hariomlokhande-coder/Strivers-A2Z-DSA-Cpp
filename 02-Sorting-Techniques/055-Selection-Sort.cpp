// ============================================================
// Problem 055: Selection Sort
//
// Question:
// Given an array of integers nums, sort it in non-decreasing order using the Selection Sort
// algorithm.
//
// Selection Sort works on one simple idea: repeatedly select the smallest element from the
// unsorted part of the array and place it at the front of the unsorted part. After the i-th round,
// the first i positions hold the i smallest elements in their final sorted order.
//
// Example:
//   Input:  nums = [13, 46, 24, 52, 20, 9]
//   Output: [9, 13, 20, 24, 46, 52]
//
//   Explanation:
//   Round 1 -> smallest is 9  -> [9, 46, 24, 52, 20, 13]
//   Round 2 -> smallest is 13 -> [9, 13, 24, 52, 20, 46]
//   Round 3 -> smallest is 20 -> [9, 13, 20, 52, 24, 46]
//   Round 4 -> smallest is 24 -> [9, 13, 20, 24, 52, 46]
//   Round 5 -> smallest is 46 -> [9, 13, 20, 24, 46, 52]
//
// Constraints:
// - 1 <= nums.size() <= 10^3
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach:
// The definition of the algorithm says "pick the smallest remaining element and put it next". The
// most literal way to obey that definition is to keep a second array as the output, scan the input
// for its minimum, append that minimum to the output, and then mark the chosen element as used so
// it is never picked again.
//
// Time Complexity: O(n^2).
// Space Complexity: O(n) - the sorted output array and the used boolean array each hold n entries.

// Optimal Approach:
// Instead of copying the minimum into a new array, swap it into the position where it belongs.
// After round i the prefix nums[0 .. i] is sorted and final, so round i + 1 only needs to search
// the suffix nums[i + 1 .. n - 1]. The used array becomes unnecessary, because "already used" is
// exactly the same as "sits before the current index".
//
// Time Complexity: O(n^2).
// Space Complexity: O(1) - only the integers i, j and minIndex are used; the sorting happens in
//                   place.

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution

void selectionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the smallest element in the unsorted suffix.
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(nums[i], nums[minIndex]);
        }
    }
}
int main() {
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    selectionSort(nums);

    for (int value : nums) cout << value << " ";
    cout << endl;
    return 0;
}
