/* 
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown 
pivot index k (0 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index 
of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
 */

#include <iostream>
#include <vector>
using namespace std;

/* 
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid] 

Time Complexity: O(log n). 
                Binary Search requires log n comparisons to find the 
                element. So time complexity is O(log n).
Space Complexity: O(1). 
                As no extra space is required.
 */

int search(vector<int> &arr, int low, int high, int target)
{
    // base case
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;

    // binary search
    if (target >= arr[low] && target <= arr[mid])
        return search(arr, low, mid - 1, target);
    else
        return search(arr, mid + 1, high, target);
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 0;

    int i = search(arr, 0, n - 1, key);

    if (i != -1)
        cout << "Index of " << key << " in the given array: " << i << endl;
    else
        cout << "Key not found" << endl;
    return 0;
}