/* 
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it 
as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
Algorithm 

Step 1: scan from right to left, find the first index that violates the non-decreasing property, denote as violationIdx

Step 2: scan from right to left, find the first index of number that is smaller than violationIdx, and swap the values

Step 3: reverse the array on the right side of the value

Time Complexity = O(N)
Space complexity = O(1)
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int violationIdx = nums.size() - 1;

        //Step 1: from right to left, find the first one that violates the non-decreasing trend
        while (violationIdx > 0 && nums[violationIdx] <= nums[violationIdx - 1])
        {
            violationIdx--;
        }

        if (violationIdx > 0)
        {
            violationIdx--;
            //Step 2: from right to left, find the first one that is larger than nums[violationIdx]
            int rightIdx = nums.size() - 1;
            while (rightIdx > 0 && nums[rightIdx] <= nums[violationIdx])
            {
                rightIdx--;
            }

            swap(nums[violationIdx], nums[rightIdx]);

            // go to righthand side of violationIdx
            violationIdx++;
        }

        //Step 3: reverse
        int end = nums.size() - 1;
        while (end > violationIdx)
        {
            swap(nums[violationIdx], nums[end]);
            violationIdx++;
            end--;
        }
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 2, 3};

    sol.nextPermutation(arr);

    for (int elem : arr)
    {
        cout << elem << " ";
    }

    cout << endl;
}