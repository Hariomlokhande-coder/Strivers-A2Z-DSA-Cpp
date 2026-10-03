// ============================================================
// Problem 068: Move Zeros to End
//
// Question:
// Given an array nums, move all 0s to the end while keeping the relative order of the non-zero
// elements. Do it in place.
//
// Example:
//   Input:  nums = [1, 0, 2, 3, 0, 4, 0, 1]
//   Output: [1, 2, 3, 4, 1, 0, 0, 0]
//
//   Input:  nums = [0, 0, 0]
//   Output: [0, 0, 0]
//
// Constraints:
// - 1 <= n <= 10^5
// - -10^9 <= nums[i] <= 10^9
// ============================================================

// Brute Force Approach (Collect Non-Zeros into a Temporary):
// Copy every non-zero element into a temporary array in order, write them back to the front of
// nums, then fill the remainder with zeros.
//
// Time Complexity: O(n) - two passes over the data.
// Space Complexity: O(n) - the temporary holds up to n non-zero elements.

// Better Approach (Two Pointers, Overwrite Then Fill):
// Keep insertPos marking where the next non-zero belongs. Scan with i; on every non-zero, write it
// to insertPos and advance. After the scan, everything from insertPos onward must be zero.
//
// Time Complexity: O(n) - the compaction pass plus the fill pass together touch each index at most
//                  twice.
// Space Complexity: O(1).

// Optimal Approach (Single Pass with Swapping):
// The second pass can be eliminated. Instead of overwriting and then filling, swap each non-zero
// with the element at insertPos. Because every position before insertPos is non-zero and every
// position between insertPos and i is zero, the swap sends a zero to where the non-zero came from
// - placing it correctly without a separate cleanup.
//
// Time Complexity: O(n) - a single pass, one comparison per element and at most one swap.
// Space Complexity: O(1).
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = 8;

    int temp = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[temp]);
            temp++;
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}