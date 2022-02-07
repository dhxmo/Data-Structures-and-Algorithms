# Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
# could represent. Return the answer in any order.
#
# A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#
# Input: digits = "23"
# Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
from typing import List


class Solution:
    @staticmethod
    def letterCombinations(digits: str) -> List[str]:
        digit_to_letters = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }

        result = []
        temp = []

        for i, x in enumerate(digits):
            if x not in digit_to_letters:
                continue

            if not result:
                result = [digit for digit in digit_to_letters[x]]
                continue

            while result:
                curr_word = result.pop()
                for digit in digit_to_letters[x]:
                    temp.append(curr_word + digit)

            result = temp
            temp = []

        return result

    @staticmethod
    def letterCombinationsOp(digits: str) -> List[str]:
        # base case
        if len(digits) == 0: return []

        # define legend
        legend = {
            '1': '',
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }

        # define final result
        res = [""]

        # iterate over the input digits
        for d in digits:
            # instantiate temp list
            temp = []
            # iterate over the dictionary
            for l in legend[d]:
                # for each individual number in the legend
                # separate the elements in res and append them together
                temp += [elem + l for elem in res]

                # assign temp to result
            res = temp

        return res


