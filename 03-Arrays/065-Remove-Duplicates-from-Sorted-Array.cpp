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