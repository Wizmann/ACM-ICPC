import re

class Solution:
    # @param {string} s A string
    # @return {boolean} Whether the string is a valid palindrome
    def isPalindrome(self, s):
        s = ''.join(re.findall("[a-zA-Z0-9]", s)).lower()
        return s == s[::-1]
