// ============================================================
// Problem 066: Left Rotate Array by One
//
// Question:
// Given an array, rotate the array to the left by one
// position.
//
// Example:
// Input:  nums = [1, 2, 3, 4, 5]
// Output: [2, 3, 4, 5, 1]
// ============================================================

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int temp = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}