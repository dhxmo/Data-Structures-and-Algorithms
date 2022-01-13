"""
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Constraints:
-231 <= x <= 231 - 1
"""


class Solution:
    @staticmethod
    def reverse(x: int) -> int:
        # assign result variable
        res = 0

        # assign sign to accomodate negative numbers
        sign = -1 if x < 0 else 1

        # make the number positive if negative
        x *= sign

        while x:
            # add 10 modulo of x while shifting result up a tens unit
            res = res * 10 + x % 10
            # get quotient of x when divided by 10 for next iteration
            x //= 10

        # consolidate result
        return 0 if res < -2 ** 31 or res > 2 ** 31 else sign * res

    @staticmethod
    def reverse_alt(x: int) -> int:
        # edge case
        if x == 0: return 0
        # turn number to a string and iterate backwards and convert back to an integer if positive
        # if negative turn to string and reverse. last character is a - sign so exclude the last character and turn to integer
        res = int(str(x)[::-1]) if x > 0 else -1 * int(str(x)[::-1][:-1])

        # consolidate result
        return res if -2 ** 31 < res < 2 ** 31 else 0
