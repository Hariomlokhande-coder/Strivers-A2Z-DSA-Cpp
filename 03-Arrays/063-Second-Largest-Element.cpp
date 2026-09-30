// ============================================================
// Problem 063: Second Largest Element
//
// Question:
// Given an array nums of n integers, find the second largest distinct element. If no such element
// exists, return -1.
//
// Example:
//   Input:  nums = [1, 2, 4, 7, 7, 5]
//   Output: 5
//   Explanation: the largest is 7, the second largest distinct value is 5.
//
//   Input:  nums = [7, 7, 7]
//   Output: -1
//   Explanation: every element is the same, so there is no second distinct value.
//
// Constraints:
// - 1 <= n <= 10^5
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach (Sort and Walk Back):
// Sort ascending, then step backwards from the end until a value different from the last one
// appears. That value is the second largest distinct element.
//
// Time Complexity: O(n log n) - the sort dominates the linear backward walk.
// Space Complexity: O(n) for the copy taken by value.

// Better Approach (Two Passes):
// The second largest is the maximum of everything not equal to the maximum. That is just another
// running-maximum scan with an added != filter.
//
// Time Complexity: O(n) - two separate passes, so 2n comparisons, which is O(n).
// Space Complexity: O(1).

// Optimal Approach (Single Pass, Two Trackers):
// Both values can be maintained together. Carry largest and secondLargest. When a new element
// beats largest, the old largest becomes the new secondLargest. When it falls strictly between the
// two, it becomes the new secondLargest directly.
//
// Time Complexity: O(n) - a single pass, at most two comparisons per element.
// Space Complexity: O(1) - two values and a flag.

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution: Single Pass, Two Trackers

int secondLargest(const vector<int> &nums) {
    int n = nums.size();
    if (n < 2) return -1;//edge case
    int largest = nums[0];
    int secondLargest = 0;
    bool found = false;

    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            secondLargest = largest;
            found = true;
            largest = nums[i];
        } else if (nums[i] < largest) { 
            if (!found || nums[i] > secondLargest) {
                secondLargest = nums[i];
                found = true;
            }
        }
    }

    return found ? secondLargest : -1;
}

int main() {
    vector<int> nums = {1, 2, 4, 7, 7, 5};

    cout << secondLargest(nums) << endl;
    return 0;
}
