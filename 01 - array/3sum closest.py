# Given an integer array nums of length n and an integer target, find three integers in
# nums such that the sum is closest to target.
# Return the sum of the three integers.
# You may assume that each input would have exactly one solution.

# Example 1:
# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
from typing import List


class Solution:
    @staticmethod
    def threeSumClosest(nums: List[int], target: int) -> int:
        # base case
        if len(nums) in [0, 1, 2]:
            return 0

        # set variables
        min_diff = float("inf")
        result = 0

        # sort array
        sort_arr = sorted(nums)

        # iterate over array
        for i in range(len(nums)):
            # iterate forward and backward through the rest of the array
            start = i + 1
            end = len(nums) - 1

            while start < end:
                # sum of three nums
                curr_sum = sort_arr[i] + sort_arr[start] + sort_arr[end]

                # difference of sum and target for conditionals
                diff = abs(curr_sum - target)

                # found sum closest to target
                if diff == 0:
                    return curr_sum

                # if new smallest diff has been found
                if diff < min_diff:
                    # re-attribute min_diff and the result for this iteration
                    min_diff = diff
                    result = curr_sum

                if curr_sum <= target:
                    # need to include bigger numbers, hence move up
                    start += 1

                else:
                    # need to include smaller numbers, hence move down
                    end -= 1
        return result
