import re

class Solution(object):
    def isPalindrome(self, s):
        s = ''.join(re.split("[^0-9a-zA-Z]", s)).lower()
        return s == s[::-1]
        
