"""
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas
and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead
and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
"""
import math
from typing import List


class Solution:
    @staticmethod
    def minEatingSpeed(piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        # initialize result to the max our solution could possibly be
        result = r

        while l <= r:
            # initialize k as the middle value of l and r
            k = (l + r) // 2
            # total hours it takes to finish the bananas
            hours = 0

            # iterate over the pile of bananas
            for p in piles:
                # math.ceil(p / k) ----- gives us the upper limit of hours it takes
                # to eat the pile of bananas at k bananas per hour
                # sum up the total hours it takes to eat all the bananas
                hours += math.ceil(p / k)

            # if bananas can be eaten  in lesser time than the total
            if hours <= h:
                # update result
                result = min(result, k)
                # look on the left side of k to find a lesser k for optimal answer
                r = k - 1
            # if hours exceeded given time and teh guard is back,
            # then look for a faster rate of eating and move l up to k+1
            else:
                l = k + 1

        return result
