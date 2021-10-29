/* 
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
// time complexity - O(NlogN)  |  space complexity O(1)
// class Duplicate
// {
// public:
//     int findDuplicate(vector<int> &arr)
//     {
//         sort(arr.begin(), arr.end());

//         for (int elem : arr)
//         {
//             if (arr[elem] = arr[elem + 1])
//             {
//                 return arr[elem];
//             }
//         }
//         return 0;
//     }
// };

// time complexity - O(N) | Space complexity - O(1)
int findDuplicate(vector<int> &arr, int size)
{
    // if multiple duplicates are needed, convert this to an array
    int output;

    for (int i = 0; i < size; i++)
    {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0)
            output = index + 1;

        arr[index] = -arr[index];
    }

    return output;
}

int main()
{
    // Duplicate dup;
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    int size = arr.size();

    cout << "Duplicate value in array is : " << findDuplicate(arr, size) << endl;
}

/*  
turn numbers negative cyclically and then check which one becomes positive and output it

[4, 3, 2, 7, 8, 2, 3, 1]
as 1 <= nums[i] <= n, any nums[i]-1 is within the range of the array
i        nums[i]     index       nums[index]        +/-         num = -num
0           4         4-1            7             false           -7

[4, 3, 2, -7, 8, 2, 3, 1]
i        nums[i]     index       nums[index]        +/-         num = -num
1           3         3-1            2             false           -2

[4, 3, -2, -7, 8, 2, 3, 1]

i        nums[i]     index       nums[index]        +/-         num = -num
2           -2        2-1            3             false           -3

[4, -3, -2, -7, 8, 2, 3, 1]
i        nums[i]     index       nums[index]        +/-         num = -num
3           -7        7-1            3             false           -3

[4, -3, -2, -7, 8, 2, -3, 1]
i        nums[i]     index       nums[index]        +/-         num = -num
4           8         8-1            1             false           -1

[4, -3, -2, -7, 8, 2, -3, -1]
i        nums[i]     index       nums[index]        +/-         num = -num
5           2         2-1            -3            -> return 
*/