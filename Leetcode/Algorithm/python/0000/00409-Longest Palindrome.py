from collections import Counter

class Solution(object):
    def longestPalindrome(self, s):
        c = Counter(s)
        ans = 0
        for (k, v) in c.items():
            ans += (v / 2) * 2
        return min(ans + 1, len(s))
