"""
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        # first letter match occurs if the first character is either a period or the same as the text
        first_match = bool(s) and p[0] in {s[0], '.'}

        # if there is a * in pattern
        if len(p) >= 2 and p[1] == '*':
            # text matches p[2] and onward
            return (self.isMatch(s, p[2:]) or
                    # first_match is true and the rest of the text matches the pattern
                    first_match and self.isMatch(s[1:], p))

        # if there's no *
        # return true if the first characters match and the rest of the strings match
        else:
            return first_match and self.isMatch(s[1:], p[1:])

    # time complexity: O(m*n)
    @staticmethod
    def isMatchOp(s: str, p: str) -> bool:
        # initialize DP
        dp = [[False] * (len(p) + 1) for i in range(len(s) + 1)]

        # set to true if there's no pattern
        dp[0][0] = True

        # iterate over the pattern
        for j in range(2, len(p) + 1):
            # if char is *
            if p[j - 1] == '*':
                # Populate the first row
                # * allows for 0 or more of the previous elem.
                # If pattern existed before the elem, then pattern will continue, else it won't
                dp[0][j] = dp[0][j - 2]

        # iterate over the string
        for i in range(1, len(s) + 1):
            # iterate oer the pattern
            for j in range(1, len(p) + 1):
                # return true
                # if pattern matches string char --- p[j-1] in [s[i-1],'.'] and
                # dp[i-1][j-1] ---- all patterns until the present char matched, return true
                # or
                # if pattern char is * ----- p[j-1] == '*' and
                # ((p[j-2] in [s[i-1],'.'] ----- one prior to last pattern char matched the string -------
                # and dp[i-1][j]) --------  and excluding the present string char, all patterns matched
                # or
                # excluding * and the previous char, if all chars have matched, then return true
                dp[i][j] = (p[j - 1] in [s[i - 1], '.'] and dp[i - 1][j - 1]) or (
                            p[j - 1] == '*' and ((p[j - 2] in [s[i - 1], '.'] and dp[i - 1][j]) or (dp[i][j - 2])))

        return dp[len(s)][len(p)]