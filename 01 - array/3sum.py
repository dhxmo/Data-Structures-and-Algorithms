"""
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Time Complexity: O(N^2)
Space Complexity: O(N)
"""
from collections import Counter
from typing import List


class Solution:
    @staticmethod
    def threeSumOp(nums: List[int]) -> List[List[int]]:
        # create a Counter object
        counter = Counter(nums)

        # get keys from counter to get rid of duplicates
        nums = list(counter.keys())

        # instantiate set to prevent duplicate answers
        three_sum = set()

        # base case
        if counter[0] >= 3:
            three_sum.add((0, 0, 0))

        # isolate positive and negative numbers
        pos = [i for i in nums if i > 0]
        neg = [i for i in nums if i < 0]

        # iterate over the numbers
        for p in pos:
            for n in neg:
                # complement of the numbers sum
                c = - (n + p)
                # if the complement of the sum exists in the list of numbers then that can be put together
                # with the positive and negative number to make a triplet
                # if complement is 0, then confirm 0 is in the list of numbers
                # is complement is one of the numbers in the list of numbers, confirm that there exist
                # more than one copy of the number
                # ie., to cancel 2, there need to be two -1s, only one will not do
                if c in counter and ((c != p and c != n) or counter[c] > 1):
                    three_sum.add(tuple(sorted([p, n, c])))

        return three_sum

    @staticmethod
    def threeSum(nums: List[int]) -> List[List[int]]:
        # base case
        if len(nums) < 3:
            return []

        if all(num == 0 for num in nums):
            return [[0, 0, 0]]

        # instantiate the result list
        res = []

        # sort list for cleaner iteration and allow skipping duplicates
        nums.sort()

        for i, a in enumerate(nums):
            # number is a copy of the one preceding it
            if i > 0 and a == nums[i - 1]:
                # don't reuse the same value and continue onwards
                continue

            # 2 point solution
            l, r = i + 1, len(nums) - 1

            while l < r:
                # compute the final sum
                three_sum = a + nums[l] + nums[r]

                # since our numbers as supposed to sum to 0

                # if sum is greater than zero, step right pointer down
                # in a sorted array the lesser number will allow a smaller sum
                if three_sum > 0:
                    r -= 1

                # if sum is lesser than zero, step left pointer up
                # in a sorted array the higher number will allow a greater sum
                elif three_sum < 0:
                    l += 1

                # if sum is 0, append to result
                else:
                    res.append([a, nums[l], nums[r]])

                    # iterate left pointer up and skip duplicates
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1

                    # iterate right pointer down and skip duplicates
                    r -= 1
                    while nums[r] == nums[r + 1] and l < r:
                        r -= 1
        return res
