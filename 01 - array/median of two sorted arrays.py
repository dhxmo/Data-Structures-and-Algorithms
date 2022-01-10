
'''
leetcode #4

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays. The median is the central value that splits the dataset into halves.

The overall run time complexity should be O(log (m+n)).

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
'''
import statistics
from typing import List


class Solution:
    @staticmethod
    def median_sorted_arrays_subOp(nums1: List[int], nums2: List[int]) -> float:
        combined = nums1 + nums2
        return statistics.median(combined)

    def median_sorted_arrays_op(self, nums1: List[int], nums2: List[int]) -> float:
        # if first list greater than the second, switch to perform correct binary search on array_1
        if len(nums1) > len(nums2):
            return self.median_sorted_arrays_op(nums2, nums1)

        # set variables to not affect the original array
        array_1 = nums1
        array_2 = nums2

        array1_len = len(array_1)
        array2_len = len(array_2)

        start = 0
        end = len(array_1)

        while start <= end:
            # in a sorted array, median is the midpoint
            partition_arr1 = int((start + end) / 2)

            ''' half of (total length of combined array and add 1 to work with odd and even) 
                minus the length of the partition_arr1 (as partition_arr1 and partition_arr2 make up half the array length 
                and their sum would be the length of the combined array)
            '''
            partition_arr2 = int((array1_len + array2_len + 1) / 2 - partition_arr1)

            # determine numbers to the left and right of partition
            max_left_arr1 = float('-inf') if partition_arr1 == 0 else array_1[partition_arr1 - 1]
            min_right_arr1 = float('inf') if partition_arr1 == array1_len else array_1[partition_arr1]

            max_left_arr2 = float('-inf') if partition_arr2 == 0 else array_2[partition_arr2 - 1]
            min_right_arr2 = float('inf') if partition_arr2 == array2_len else array_2[partition_arr2]

            # if conditions are satisfied, we've found the correct partition
            if (max_left_arr1 <= min_right_arr2) and (max_left_arr2 <= min_right_arr1):

                # if total combined length is even
                if (array1_len + array2_len) % 2 == 0:
                    median = ((max(max_left_arr1, max_left_arr2) + min(min_right_arr1, min_right_arr2)) / 2)
                    return median

                # for odd lengths
                else:
                    median = max(max_left_arr1, max_left_arr2)
                    return median

            # if the correct partition hasn't been found, set the limits for binary search
            # if max-left of arr2 is higher than min-right of arr1, we're starting too low
            # hence start needs to be moved up to one above partition
            elif max_left_arr2 > min_right_arr1:
                start = partition_arr1 + 1
            # else if max-left of arr1 is higher than min-right of arr2, we're ending too high
            # hence end needs to be moved down to one below partition
            else:
                end = partition_arr1 - 1
