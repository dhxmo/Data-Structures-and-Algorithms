"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int num_rows);

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= num_rows <= 1000
"""


class Solution:
    # time complexity: O(N)
    # space complexity: O(N)
    @staticmethod
    def convert(s: str, num_rows: int) -> str:
        # edge case
        # no modifications necessary
        if num_rows == 1 or num_rows >= len(s):
            return s

        # create empty 2d array for each num_rows
        chars = [[] for _ in range(num_rows)]

        # start row iteration from the top
        row = 0
        # set direction to allow for a ping-pong effect of the row iteration
        direction = -1

        # iterate through the string
        for char in s:
            chars[row].append(char)

            # switch direction if at the first or the last row
            if row == 0 or row == num_rows - 1:
                direction *= -1

            # direction is +1 going down and -1 coming up
            # helps iterate over rows
            row += direction

        res = ""
        # consolidate result
        for arr in chars:
            res += "".join(arr)
        return res

    @staticmethod
    def convert_alt(s, num_rows):
        # edge case
        if num_rows == 1: return s

        # instantiate character array that holds the result
        char_arr = [""] * num_rows

        # boolean to determine the direction of iteration
        is_increasing = True

        # start from the first row
        row = 0

        # iterate over the string
        for i in range(len(s)):
            # add present letter to char_arr
            char_arr[row] += s[i]

            # if on the last row, set to false
            if row % num_rows == num_rows - 1:
                is_increasing = False
            # if on the first row, set to true
            elif row == 0:
                is_increasing = True

            # if on the first row, iterate up the rows
            if is_increasing:
                row += 1
            # if on the last row, iterate down the rows
            else:
                row -= 1

        # consolidate result
        ans = ''
        for c in char_arr:
            ans += c

        return ans
