# https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

from collections import Counter
import string

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        c1 = Counter(s)
        c2 = Counter(t)
        
        a, b = 0, 0
        for c in string.ascii_lowercase:
            delta = c1.get(c, 0) - c2.get(c, 0)
            if delta > 0:
                a += delta
            else:
                b += -delta
        return min(a, b) + abs(a - b)
