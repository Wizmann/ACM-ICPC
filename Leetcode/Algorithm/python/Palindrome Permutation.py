from collections import Counter
class Solution(object):
    def canPermutePalindrome(self, s):
        odd, even = 0, 0
        for value in Counter(s).values():
            if value % 2 == 0:
                even += 1
            else:
                odd += 1
        if len(s) % 2 == 1:
            return odd == 1
        else:
            return odd == 0
        
