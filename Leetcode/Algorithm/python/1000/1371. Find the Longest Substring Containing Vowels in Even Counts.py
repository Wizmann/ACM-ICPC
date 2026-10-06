# https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

from typing import *

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        d = {0: -1}
        mp = dict(zip('aeiou', range(5)))
        
        res = 0
        status = 0
        for i, c in enumerate(s):
            if c in mp:
                status ^= 1 << mp[c]
            if status in d:
                res = max(res, i - d[status])
            else:
                d[status] = i
        return res

S = Solution()
assert(S.findTheLongestSubstring('foo') == 3)
