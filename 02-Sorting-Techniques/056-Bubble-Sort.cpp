// ============================================================
// Problem 056: Bubble Sort
//
// Question:
// Given an array of integers nums, sort it in non-decreasing order using the Bubble Sort
// algorithm.
//
// Bubble Sort repeatedly steps through the array, compares each pair of adjacent elements, and
// swaps them if they are in the wrong order. Each full pass pushes the largest remaining element
// to the end of the unsorted region - it "bubbles up" to its final place.
//
// Example:
//   Input:  nums = [13, 46, 24, 52, 20, 9]
//   Output: [9, 13, 20, 24, 46, 52]
//
//   Explanation (pass 1, largest bubbles to the end):
//   [13, 46, 24, 52, 20,  9]   compare 13,46 -> no swap
//   [13, 46, 24, 52, 20,  9]   compare 46,24 -> swap
//   [13, 24, 46, 52, 20,  9]   compare 46,52 -> no swap
//   [13, 24, 46, 52, 20,  9]   compare 52,20 -> swap
//   [13, 24, 46, 20, 52,  9]   compare 52, 9 -> swap
//   [13, 24, 46, 20,  9, 52]   52 is now final
//
// Constraints:
// - 1 <= nums.size() <= 10^3
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach:
// If every adjacent pair in an array is in the correct relative order, the whole array is sorted.
// So just keep sweeping across the array swapping any out-of-order neighbours. One sweep is not
// enough - an element may need to travel many positions - but n - 1 sweeps are guaranteed to
// finish the job, because each sweep locks at least one more element into its final spot.
//
// Time Complexity: O(n^2) - exactly n - 1 passes, each doing n - 1 comparisons, so (n-1)^2 work
//                  regardless of the input.
// Space Complexity: O(1) - swapping happens in place; only loop counters are stored.

// Better Approach:
// After i completed passes, the last i positions are sorted and final. Therefore pass i only needs
// to sweep up to index n - i - 2. Shrinking the sweep does not change the algorithm's behaviour,
// it just stops re-checking settled elements.
//
// Time Complexity: O(n^2).
// Space Complexity: O(1) - still fully in place.

// Optimal Approach:
// If a complete pass makes zero swaps, then every adjacent pair is already in order - which is
// precisely the definition of a sorted array. There is no need to run the remaining passes at all.
// A single boolean flag detects this.
//
// Time Complexity: O(n^2) worst and average case; O(n) best case. The best case occurs when the
//                  input is already sorted.
// Space Complexity: O(1) - one extra boolean plus loop counters.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> & nums){
    int n = nums.size();
    for (int i =0 ; i< n-1; i++){
        bool swaped = false;

        for (int j=0; j< n-i-1; j++){
            if (nums[j]> nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
}

int main() {
    vector<int> nums = {13, 46, 24, 54, 20, 9};

    bubbleSort(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}