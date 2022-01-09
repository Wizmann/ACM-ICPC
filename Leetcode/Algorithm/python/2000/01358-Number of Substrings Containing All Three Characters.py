# https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

from typing import *
from collections import defaultdict

INF = 10 ** 10

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        l, r = 0, 0
        d = defaultdict(int)

        contains_all = lambda: d['a'] and d['b'] and d['c']

        res = 0
        while l < n or r < n:
            while r < n and not contains_all():
                d[s[r]] += 1
                r += 1
            if contains_all():
                res += n - r + 1
            d[s[l]] -= 1
            l += 1
        return res

S = Solution()
assert S.numberOfSubstrings('aaabc') == 3
assert S.numberOfSubstrings('abc') == 1
assert S.numberOfSubstrings('ab') == 0
assert S.numberOfSubstrings('abcabc') == 10
assert S.numberOfSubstrings('') == 0



