# Given a string s, return the longest palindromic substring in s.

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""

        # iterate considering the letter to be the center
        for i in range(len(s)):

            # exit early if remaining can't surpass largest found
            if (len(s) - i) * 2 <= len(res):
                break

            # odd length strings
            # initialize pointers to point at center character
            left_ptr, right_ptr = i, i
            temp = self.palin_util(s, left_ptr, right_ptr)
            # if length of the palindrome found is greater than the previous result, update
            if len(temp) > len(res):
                res = temp

            # even length strings
            left_ptr, right_ptr = i, i + 1
            temp = self.palin_util(s, left_ptr, right_ptr)
            # if length of the palindrome found is greater than the previous result, update
            if len(temp) > len(res):
                res = temp

        return res

    def palin_util(self, s, left_ptr, right_ptr):
        # while pointers are inbound and pointers are equal to each other, palindrome exists
        while left_ptr >= 0 and right_ptr < len(s) and s[left_ptr] == s[right_ptr]:
            # shift left pointer down and right pointer up
            # increment sends pointers one outside the palindrome range
            left_ptr -= 1
            right_ptr += 1

        # return string found to be a palindrome
        # pointers are outside the palindrome range hence left is incremented
        return s[left_ptr + 1:right_ptr]
