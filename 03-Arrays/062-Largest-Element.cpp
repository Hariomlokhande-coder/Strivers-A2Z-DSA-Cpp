// ============================================================
// Problem 062: Largest Element
//
// Question:
// Given an array nums of n integers, return the largest element in it.
//
// Example:
//   Input:  nums = [3, 3, 6, 1]
//   Output: 6
//
//   Input:  nums = [-5, -2, -9]
//   Output: -2
//
// Constraints:
// - 1 <= n <= 10^5
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach (Sort and Take the Last):
// If the array is sorted ascending, the largest element is the last one. Sorting therefore answers
// the question, even though it does far more work than needed - it orders every element when we
// only care about one.
//
// Time Complexity: O(n log n) - dominated by the sort.
// Space Complexity: O(n) as written, because the vector is taken by value so the caller's array is
//                   not disturbed. Sorting in place instead would be O(log n) for the sort's
//                   recursion stack, but would modify the input.

// Optimal Approach (Single Linear Scan):
// Carry the best value seen so far. Walk the array once, replacing it whenever a larger element
// appears. After one pass the carried value is the maximum.
//
// Time Complexity: O(n) - exactly n - 1 comparisons, one per element after the first.
// Space Complexity: O(1) - a single tracking variable.

#include <iostream>
using namespace std;

int main() {

    int arr[] = {3, 3, 6, 1};
    int n = 4;

    int largest = arr[0];

    for(int i = 1; i < n; i++) {

        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "Largest element is: " << largest;

    return 0;
}