"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
"""
from typing import List


class Solution:
    class Solution:
        @staticmethod
        def longestCommonPrefixOp(words: List[str]) -> str:
            lcp = ""

            # since we need a common prefix among all the words,
            # all we need to consider if the smallest and the largest string
            smallest_str = min(words)
            largest_str = max(words)

            # iterate over the smallest string as the longest common prefix
            # has to be found in the smallest string as well
            for char in range(len(smallest_str)):
                # if characters aren't equal, return the longest character prefix until that point
                if smallest_str[char] != largest_str[char]:
                    return lcp
                # else if characters are equal, append the character to the result
                else:
                    lcp += smallest_str[char]

                    # consolidate result
            return lcp

    @staticmethod
    def longestCommonPrefix(words: List[str]) -> str:
        # base case
        if not words:
            return ''

        # attribute first word as the longest common prefix
        common = words[0]

        # iterate over words
        for word in words:
            # if word doesn't start with the longest common prefix
            while not word.startswith(common):
                # reduce 1 character from the end of the longest prefix and try again
                common = common[:-1]

        # left with the longest common prefix, return answer
        return common
