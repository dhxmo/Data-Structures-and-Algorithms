''' 
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

'''


class Solution:
    # Time Complexity: O(n)
    def lengthOfLongestSubstring(self, s: str) -> int:
        # ptr1 is the rear end of the window
        # ptr2 is te front end of the window
        ptr1 = ptr2 = longest_substr = 0

        # instantiate a set
        chars = set()

        # iterate over the string
        while ptr2 < len(s):
            # if the letter is not in set
            if s[ptr2] not in chars:
                # add letter to set
                chars.add(s[ptr2])
                # move front end of window up
                ptr2 = ptr2 + 1
                # update length of consecutive non-repeating elements
                longest_substr = max(longest_substr, len(chars))
            # else if letter is in set, hence a repeating letter in the string
            else:
                # remove from set
                chars.remove(s[ptr1])
                # move rear end of window up
                ptr1 = ptr1 + 1

        return longest_substr
    
    ''' The above solution requires at most 2n steps. In fact, it could be optimized to require only n steps. Instead of using a set to tell if a character exists or not, we could define a mapping of the characters to its index. Then we can skip the characters immediately when we found a repeated character. '''
    def lengthOfLongestSubstringOp(self, s: str) -> int:
        back = longest_sub_str = 0
        hashmap = {}
        
        # iterate over the string
        for front in range(len(s)):
            # if duplicate
            if s[front] in hashmap:
                # move back edge of the window up by 1
                # this excludes the first copy of the letter from the window
                back = max(back, hashmap[s[front]] + 1)
                
            # if no duplicate found
            # update dictionary as letter:index
            hashmap[s[front]] = front
            # update current longest sub string
            longest_sub_str = max(longest_sub_str, front-back+1)
        return longest_sub_str
